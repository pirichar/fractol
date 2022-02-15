/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:08 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/15 10:10:13 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_in_out(int key, t_mlx *mlx)
{
	if (key == KEY_Z)
	{
		mlx->n = mlx->n * 1.3;
		mlx->max_val = mlx->max_val / 1.3;
		mlx->min_val = mlx->min_val / 1.02;
		mlx->zoom_base = mlx->zoom_base * 1.3;
	}
	if (key == KEY_X)
	{
		mlx->n = mlx->n / 1.3;
		mlx->max_val = mlx->max_val * 1.3;
		mlx->min_val = mlx->min_val * 1.02;
		mlx->zoom_base = mlx->zoom_base / 1.3;
	}
	if (key == KEY_PLUS)
		mlx->zoom_base = mlx->zoom_base * 10;
	if (key == KEY_MINUS)
		mlx->zoom_base = mlx->zoom_base / 10;
	if (mlx->f_state == 'm')
		mandlebroth(mlx);
	else
		julia_set(mlx);
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
	if (mlx->f_state == 'm')
		mandlebroth(mlx);
	else
		julia_set(mlx);
}				

void	change_iterations(int key, t_mlx *mlx)
{
	if (key == KEY_I)
		mlx->max_i = mlx->max_i * 2;
	if (key == KEY_O)
		mlx->max_i = mlx->max_i / 2;
	if (mlx->f_state == 'm')
		mandlebroth(mlx);
	else
		julia_set(mlx);
}

void	fractal_movement(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->max_val -= (1.0 / mlx->zoom_base);
	if (key == KEY_A)
		mlx->min_val += (1.0 / mlx->zoom_base);
	if (key == KEY_S)
		mlx->max_val += (1.0 / mlx->zoom_base);
	if (key == KEY_D)
		mlx->min_val -= (1.0 / mlx->zoom_base);
	if (mlx->f_state == 'm')
		mandlebroth(mlx);
	else
		julia_set(mlx);
}

void	julia_modif(int key, t_mlx *mlx)
{
	if (mlx->f_state == 'j')
	{
		if (key == KEY_UP)
			mlx->c1 = mlx->c1 * 1.1;
		if (key == KEY_DOWN)
			mlx->c1 = mlx->c1 * 0.9;
		if (key == KEY_LEFT)
			mlx->c2 = mlx->c2 * 1.1;
		if (key == KEY_RIGHT)
			mlx->c2 = mlx->c2 * 0.9;
		julia_set(mlx);
	}
}
