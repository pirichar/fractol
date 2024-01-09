/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:43:13 by pirichar          #+#    #+#             */
/*   Updated: 2024/01/09 01:36:37 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	chose_zoom(int key, t_mlx *mlx)
{
	zoom_locked(key, mlx);
	if (key == KEY_MINUS)
		mlx->zoom_base = mlx->zoom_base * 2;
	if (key == KEY_PLUS && mlx->zoom_base > 1)
		mlx->zoom_base = mlx->zoom_base * 0.5;
	refresh_mandle(mlx);
}

void	zoom_locked(int key, t_mlx *mlx)
{
    long double center_a, center_b;

	if (key == KEY_Z || key == KEY_X)
	{
		if (key == KEY_Z)
		{
			mlx->n = mlx->n * 1.1;
			mlx->zoom_base = mlx->zoom_base * 1.2;
		}
		if (key == KEY_X)
		{
			mlx->n = mlx->n / 1.1;
			if (mlx->zoom_base > 5)
				mlx->zoom_base = mlx->zoom_base * 0.9;
		}
		// Calculate the center in the complex plane
		center_a = mlx->min_val + ((mlx->max_val - mlx->min_val) / 2);
		center_b = mlx->im_min + ((mlx->im_max - mlx->im_min) / 2);
		// Adjust min_val and max_val to keep the center fixed
		mlx->min_val = center_a - ((mlx->win_x / 2) / mlx->n);
		mlx->max_val = center_a + ((mlx->win_x / 2) / mlx->n);
		mlx->im_min = center_b - ((mlx->win_y / 2) / mlx->n);
		mlx->im_max = center_b + ((mlx->win_y / 2) / mlx->n);
	}
}
