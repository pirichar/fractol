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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:10:00 by pirichar          #+#    #+#             */
/*   Updated: 2025/07/21 18:20:00 by Gemini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	zoom_in(t_mlx *mlx);
void	zoom_out(t_mlx *mlx);

int	mouse_mover(int x, int y, t_mlx *mlx)
{
	if (mlx->is_dragging)
	{
		double dx = (double)(x - mlx->mouse.drag_start_x) / mlx->win_x * (mlx->max_val - mlx->min_val);
		double dy = (double)(y - mlx->mouse.drag_start_y) / mlx->win_y * (mlx->im_max - mlx->im_min);
		mlx->min_val -= dx;
		mlx->max_val -= dx;
		mlx->im_min += dy;
		mlx->im_max += dy;
		mlx->mouse.drag_start_x = x;
		mlx->mouse.drag_start_y = y;
		refresh_mandle(mlx);
	}
	else
	{
		mlx->mouse.x_pos = x;
		mlx->mouse.y_pos = y;
		if (mlx->is_looping == 'y' || (mlx->f_state == 'j' && mlx->mouse.move == 1))
			refresh_mandle(mlx);
	}
	return (0);
}

int	mouse_press_hook(int button, int x, int y, t_mlx *mlx)
{
	if (button == MOUSE_LEFT)
	{
		mlx->is_dragging = 1;
		mlx->mouse.drag_start_x = x;
		mlx->mouse.drag_start_y = y;
	}
	else if (button == MOUSE_UP)
	{
		zoom_in(mlx);
		refresh_mandle(mlx);
	}
	else if (button == MOUSE_DOWN)
	{
		zoom_out(mlx);
		refresh_mandle(mlx);
	}
	return (0);
}

int	mouse_release_hook(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT)
		mlx->is_dragging = 0;
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
