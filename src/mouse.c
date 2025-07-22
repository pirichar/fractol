/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:10:00 by pirichar          #+#    #+#             */
/*   Updated: 2025/07/21 15:10:00 by Gemini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_mover(int x, int y, t_mlx *mlx)
{
	if (mlx->is_looping == 'y')
	{
		shift_palet(mlx);
		refresh_mandle(mlx);
	}
	mlx->mouse.x_pos = x;
	mlx->mouse.y_pos = y;
	if (mlx->f_state == 'j' && mlx->mouse.move == 1)
	{
		if (x > mlx->win_x * 0.333)
			mlx->c1 = mlx->c1 + 0.05;
		if (x < mlx->win_x * 0.666)
			mlx->c1 = mlx->c1 - 0.05;
		if (y > mlx->win_y * 0.333)
			mlx->c2 = mlx->c2 + 0.05;
		if (y < mlx->win_y * 0.666)
			mlx->c2 = mlx->c2 - 0.05;
		refresh_mandle(mlx);
	}
	return (0);
}

void	zoom_in(t_mlx *mlx)
{
	long double	mouse_re;
	long double	mouse_im;
	long double	zoom_factor = 1.5;
	long double	range_re, range_im, new_range_re, new_range_im;
	long double	rel_x, rel_y;

	range_re = mlx->max_val - mlx->min_val;
	range_im = mlx->im_max - mlx->im_min;

	mouse_re = mlx->min_val + ((long double)mlx->mouse.x_pos / mlx->win_x) * range_re;
	mouse_im = mlx->im_min + ((long double)(mlx->win_y - mlx->mouse.y_pos) / mlx->win_y) * range_im;

	new_range_re = range_re / zoom_factor;
	new_range_im = range_im / zoom_factor;

	rel_x = (long double)mlx->mouse.x_pos / mlx->win_x;
	rel_y = (long double)(mlx->win_y - mlx->mouse.y_pos) / mlx->win_y;

	mlx->min_val = mouse_re - rel_x * new_range_re;
	mlx->max_val = mlx->min_val + new_range_re;
	mlx->im_min = mouse_im - rel_y * new_range_im;
	mlx->im_max = mlx->im_min + new_range_im;
}

void	zoom_out(t_mlx *mlx)
{
	long double	mouse_re;
	long double	mouse_im;
	long double	zoom_factor = 1.5;
	long double	range_re, range_im, new_range_re, new_range_im;
	long double	rel_x, rel_y;

	range_re = mlx->max_val - mlx->min_val;
	range_im = mlx->im_max - mlx->im_min;

	mouse_re = mlx->min_val + ((long double)mlx->mouse.x_pos / mlx->win_x) * range_re;
	mouse_im = mlx->im_min + ((long double)(mlx->win_y - mlx->mouse.y_pos) / mlx->win_y) * range_im;

	new_range_re = range_re * zoom_factor;
	new_range_im = range_im * zoom_factor;

	rel_x = (long double)mlx->mouse.x_pos / mlx->win_x;
	rel_y = (long double)(mlx->win_y - mlx->mouse.y_pos) / mlx->win_y;

	mlx->min_val = mouse_re - rel_x * new_range_re;
	mlx->max_val = mlx->min_val + new_range_re;
	mlx->im_min = mouse_im - rel_y * new_range_im;
	mlx->im_max = mlx->im_min + new_range_im;
}

int	mousehook(int key, int x, int y, t_mlx *mlx)
{
	if (mlx->mouse.move == 1)
		mouse_mover(x, y, mlx);
	if (mlx->is_active == 'y')
	{
		if (key == MOUSE_UP)
			zoom_in(mlx);
		if (key == MOUSE_DOWN)
			zoom_out(mlx);
		refresh_mandle(mlx);
	}
	return (0);
}
