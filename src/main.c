/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:55 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/15 10:30:01 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strcmp(char *s1, char*s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}

int	keypress(int key, t_mlx *mlx)
{
	printf("%x\n",key);
	if (key == KEY_M)
		init_mandle(mlx);
	if (key == KEY_C)
		clearscreen(mlx);
	if(key == KEY_Z || key == KEY_X || key == KEY_MINUS || key == KEY_PLUS)
		zoom_in_out(key, mlx);
	if(key == KEY_I || key == KEY_O)
		change_iterations(key, mlx);
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit (0);
	}
	if (key == KEY_1 || key == KEY_2 || key == KEY_3 || key == KEY_4 || key == KEY_5 || key == KEY_P)
		chose_color(key, mlx);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		fractal_movement(key, mlx);
	if(key == KEY_J)
		init_julia(mlx);
	if(key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		julia_modif(key, mlx);
	return (0);
}

int		mousehook(int key, t_mlx *mlx)
{
	printf("Hello from key %x\n", key);
	if(key == MOUSE_LEFT)
	{
		mlx->n = mlx->n * 1.3;
		mlx->max_val = mlx->max_val / 1.3;
		mlx->min_val = mlx->min_val / 1.02;
		mlx->zoom_base = mlx->zoom_base * 1.3;
		if (mlx->f_state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
	if(key == MOUSE_RIGHT)
	{
		mlx->n = mlx->n / 1.3;
		mlx->max_val = mlx->max_val * 1.3;
		mlx->min_val = mlx->min_val * 1.02;
		mlx->zoom_base = mlx->zoom_base / 1.3;
		if (mlx->f_state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
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