/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:08 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/16 14:00:03 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	refresh_mandle(t_mlx *mlx)
{
	if (mlx->f_state == 'm')
		mandlebroth(mlx);
	else if (mlx->f_state == 'j')
		julia_set(mlx);
	else if (mlx->f_state == 'b')
		burningship(mlx);
	else if (mlx->f_state == 's')
		sierpinski(mlx);
	else 
		return ;
}

void	chose_color(int key, t_mlx *mlx)
{
	if (key == KEY_1)
		mandle_blue(mlx);
	if (key == KEY_2)
		mandle_red(mlx);
	if (key == KEY_3)
		mandle_green(mlx);
	if (key == KEY_4)
		mandle_black(mlx);
	if (key == KEY_5)
		mandle_funk(mlx);
	if (key == KEY_P)
		shift_palet(mlx);
	refresh_mandle(mlx);
}

void	change_iterations(int key, t_mlx *mlx)
{
	if (key == KEY_I)
		mlx->max_i = mlx->max_i * 1.3;
	if (key == KEY_O)
		mlx->max_i = mlx->max_i / 1.3;
	refresh_mandle(mlx);
}

void	fractal_movement(int key, t_mlx *mlx)
{
	if (key == KEY_DOWN)
		mlx->max_val -= (1.0 / mlx->zoom_base);
	if (key == KEY_RIGHT)
		mlx->min_val += (1.0 / mlx->zoom_base);
	if (key == KEY_UP)
		mlx->max_val += (1.0 / mlx->zoom_base);
	if (key == KEY_LEFT)
		mlx->min_val -= (1.0 / mlx->zoom_base);
	refresh_mandle(mlx);
}

void	julia_modif(int key, t_mlx *mlx)
{
	if (mlx->f_state == 'b')
	{
		if (key == KEY_W)
			mlx->midpoint_y = mlx->midpoint_y + 1;
		if (key == KEY_S)
			mlx->midpoint_y = mlx->midpoint_y - 1;
		if (key == KEY_A)
			mlx->midpoint_x = mlx->midpoint_x + 1;
		if (key == KEY_D)
			mlx->midpoint_x = mlx->midpoint_x - 1;
		burningship(mlx);
	}
	if (mlx->f_state == 'j')
	{
		if (key == KEY_W)
			mlx->c1 = mlx->c1 * 1.1;
		if (key == KEY_S)
			mlx->c1 = mlx->c1 * 0.9;
		if (key == KEY_A)
			mlx->c2 = mlx->c2 * 1.1;
		if (key == KEY_D)
			mlx->c2 = mlx->c2 * 0.9;
		if (key == KEY_N)
		{
			if (mlx->mouse.move == 0)
				mlx->mouse.move = 1;
			else
				mlx->mouse.move = 0;
			refresh_mandle(mlx);
		}
		julia_set(mlx);
	}

}
