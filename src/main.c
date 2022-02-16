/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:55 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/16 14:21:38 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
void	init_fractals(int key, t_mlx *mlx)
{
	if (key == KEY_M)
		init_mandle(mlx);
	if (key == KEY_J)
		init_julia(mlx);
	if (key == KEY_B)
		init_ship(mlx);
	if (key == KEY_T)
		init_sierpinski(mlx);
}

int	keypress(int key, t_mlx *mlx)
{
	printf("%x\n", key);
	if (key == KEY_M || key == KEY_J || key == KEY_B || key == KEY_T)
		init_fractals(key, mlx);
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit (0);
	}	
	if (mlx->f_state == 'j' || mlx->f_state == 'm' || mlx->f_state == 's' || mlx->f_state == 'b')
	{
		if (key == KEY_C)
			reset_screen(mlx);	
		if (key == KEY_Z || key == KEY_X || key == KEY_MINUS|| key == KEY_PLUS || key == KEY_L )
			chose_zoom(key, mlx);
		if (key == KEY_I || key == KEY_O)
			change_iterations(key, mlx);
		if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4 || key == KEY_5 || key == KEY_P)
			chose_color(key, mlx);
		if (key == KEY_DOWN || key == KEY_RIGHT || key == KEY_UP || key == KEY_LEFT)
			fractal_movement(key, mlx);
		if (key == KEY_W || key == KEY_S|| key == KEY_A || key == KEY_D || key == KEY_N)
			julia_modif(key, mlx);
	}
	return (0);
}
int	mouse_mover(int x, int y, t_mlx *mlx)
{
	mlx->mouse.x_pos = x;
	mlx->mouse.y_pos = y;
	if (mlx->f_state == 'j' && mlx->mouse.move == 1)
	{
		if (x > mlx->win_x * 0.333)
			mlx->c1 = mlx->c1 + 0.01;
		if (x < mlx->win_x * 0.666)
			mlx->c1 = mlx->c1 - 0.01;
		if (y > mlx->win_y * 0.333)
			mlx->c2 = mlx->c2 + 0.01;
		if (y < mlx->win_y * 0.666)
			mlx->c2 = mlx->c2 - 0.01;
	}
	refresh_mandle(mlx);
	return (0);
}

int		mousehook(int key,int x, int y, t_mlx *mlx)
{
	if (mlx->mouse.move == 1)
		mouse_mover(x, y , mlx);
	if (mlx->f_state == 'j' || mlx->f_state == 'm' || mlx->f_state == 's') 
	{
		if(key == MOUSE_UP)
		{
			mlx->n = mlx->n * 1.3;
			mlx->max_val = mlx->max_val / 1.3;
			mlx->min_val = mlx->min_val / 1.02;
			mlx->zoom_base = mlx->zoom_base * 1.3;
		}
		if(key == MOUSE_DOWN)
		{
			mlx->n = mlx->n / 1.3;
			mlx->max_val = mlx->max_val * 1.3;
			mlx->min_val = mlx->min_val * 1.02;
			mlx->zoom_base = mlx->zoom_base / 1.3;
		}
		refresh_mandle(mlx);
	}
	return (0);
}

int main()
{
	t_mlx mlx;

	mlx.win_x = 1280;
	mlx.win_y = 720;
	mlx.mouse.move = 0;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_x,mlx.win_y, "fract-OL");
	mlx.img.img = mlx_new_image(mlx.mlx_ptr,mlx.win_x,mlx.win_y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx_key_hook(mlx.win_ptr, keypress, &mlx);
	mlx_hook(mlx.win_ptr, 6, 3, mouse_mover, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mousehook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}