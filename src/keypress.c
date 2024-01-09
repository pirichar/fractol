/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:08 by pirichar          #+#    #+#             */
/*   Updated: 2024/01/08 16:53:59 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	keypress(int key, t_mlx *mlx)
{
	if (key == KEY_RTN)
		init_first_fractal(mlx);
	if (key == KEY_H)
	{
		if (mlx->menu_state == 'n')
			mlx->menu_state = 'o';
		else
			mlx->menu_state = 'n';
		refresh_mandle(mlx);
	}
	if (key == KEY_M || key == KEY_J || key == KEY_B || key == KEY_T)
		init_fractals(key, mlx);
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit (0);
	}	
	if (mlx->is_active == 'y')
		modif_fractals(key, mlx);
	return (0);
}

void	modif_fractals(int key, t_mlx *mlx)
{
	if (key == KEY_Z || key == KEY_X || key == KEY_MINUS
		|| key == KEY_PLUS || key == KEY_L)
		chose_zoom(key, mlx);
	if (key == KEY_I || key == KEY_O)
		change_iterations(key, mlx);
	if (key == KEY_1 || key == KEY_2 || key == KEY_3
		|| key == KEY_4 || key == KEY_5 || key == KEY_P)
		chose_color(key, mlx);
	if (key == KEY_DOWN || key == KEY_RIGHT
		|| key == KEY_UP || key == KEY_LEFT)
		fractal_movement(key, mlx);
	if (key == KEY_W || key == KEY_S || key == KEY_A
		|| key == KEY_D || key == KEY_N)
		param_modif(key, mlx);
	if (key == KEY_6)
		loop_palet(key, mlx);
}

void	init_fractals(int key, t_mlx *mlx)
{
	if (key == KEY_M)
		init_mandle(mlx);
	if (key == KEY_J)
		init_julia(mlx);
	if (key == KEY_B)
		init_ship(mlx);
}


void	fractal_movement(int key, t_mlx *mlx)
{
    double movement;

    movement = 1.0 / mlx->zoom_base;
    if (key == KEY_DOWN)
        mlx->im_min -= movement;
    if (key == KEY_RIGHT)
        mlx->min_val += movement;
    if (key == KEY_UP)
        mlx->im_min += movement;
    if (key == KEY_LEFT)
        mlx->min_val -= movement;
    refresh_mandle(mlx);
}

void	param_modif(int key, t_mlx *mlx)
{
	if (mlx->f_state == 'j')
	{
		if (key == KEY_W)
			mlx->c1 = mlx->c1 * 1.1;
		if (key == KEY_S)
			mlx->c1 = mlx->c1 * 0.9;
		if (key == KEY_A)
			mlx->c2 = mlx->c2 * 1.5;
		if (key == KEY_D)
			mlx->c2 = mlx->c2 * 0.5;
		if (key == KEY_N)
		{
			if (mlx->mouse.move == 0)
				mlx->mouse.move = 1;
			else
				mlx->mouse.move = 0;
		}
		refresh_mandle(mlx);
		shift_palet(mlx);
	}
}
