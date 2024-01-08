/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:10:00 by pirichar          #+#    #+#             */
/*   Updated: 2024/01/08 13:54:36 by pirichar         ###   ########.fr       */
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
	long double center_a, center_b;
	mlx->n = mlx->n * 1.1;
	mlx->zoom_base = mlx->zoom_base * 1.1;
	
	// Calculate the center in the complex plane
	center_a = mlx->min_val + ((mlx->max_val - mlx->min_val) / 2);
	center_b = mlx->im_min + ((mlx->im_max - mlx->im_min) / 2);

	// Adjust min_val and max_val to keep the center fixed
	mlx->min_val = center_a - ((mlx->win_x / 2) / mlx->n);
	mlx->max_val = center_a + ((mlx->win_x / 2) / mlx->n);
	mlx->im_min = center_b - ((mlx->win_y / 2) / mlx->n);
	mlx->im_max = center_b + ((mlx->win_y / 2) / mlx->n);
}

void	zoom_out(t_mlx *mlx)
{
	long double center_a, center_b;
	
	mlx->n = mlx->n / 1.1;
	if (mlx->zoom_base > 5)
		mlx->zoom_base = mlx->zoom_base * 0.9;
	
	// Calculate the center in the complex plane
	center_a = mlx->min_val + ((mlx->max_val - mlx->min_val) / 2);
	center_b = mlx->im_min + ((mlx->im_max - mlx->im_min) / 2);

	// Adjust min_val and max_val to keep the center fixed
	mlx->min_val = center_a - ((mlx->win_x / 2) / mlx->n);
	mlx->max_val = center_a + ((mlx->win_x / 2) / mlx->n);
	mlx->im_min = center_b - ((mlx->win_y / 2) / mlx->n);
	mlx->im_max = center_b + ((mlx->win_y / 2) / mlx->n);
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
