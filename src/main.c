/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:55 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/15 11:45:50 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	keypress(int key, t_mlx *mlx)
{
	printf("%x\n",key);
	if (key == KEY_M)
		init_mandle(mlx);
	if (key == KEY_C)
		clearscreen(mlx);
	if(key == KEY_Z || key == KEY_X || key == KEY_MINUS || key == KEY_PLUS || key == KEY_L )
		chose_zoom(key, mlx);
	if(key == KEY_I || key == KEY_O)
		change_iterations(key, mlx);
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit (0);
	}
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4 || key == KEY_5 || key == KEY_P)
		chose_color(key, mlx);
	if (key == KEY_DOWN || key == KEY_RIGHT || key == KEY_UP || key == KEY_LEFT)
		fractal_movement(key, mlx);
	if(key == KEY_J)
		init_julia(mlx);
	if(key == KEY_W || key == KEY_S|| key == KEY_A || key == KEY_D)
		julia_modif(key, mlx);
	return (0);
}

int		mousehook(int key,int x, int y, t_mlx *mlx)
{
	printf("Hello from key %x\n", key);
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
	if (key == MOUSE_LEFT)
	{
		printf("This is x%d\nThis is y%d\n", x, y);
		return (0);
	}
	if (mlx->f_state == 'm')
		mandlebroth(mlx);
	else 
		julia_set(mlx);
	return (0);
}

int main()
{
	t_mlx mlx;

	mlx.win_x = 1280;
	mlx.win_y = 720;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_x,mlx.win_y, "fract-OL");
	mlx.img.img = mlx_new_image(mlx.mlx_ptr,mlx.win_x,mlx.win_y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx_key_hook(mlx.win_ptr, keypress, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mousehook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}