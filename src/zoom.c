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
	refresh_mandle(mlx);
}

void	zoom_locked(int key, t_mlx *mlx)
{
    long double center_a, center_b;
	long double zoom_factor;

	if (key == KEY_Z || key == KEY_X)
	{
		if (key == KEY_Z)
			zoom_factor = 1.2;
		else
			zoom_factor = 1 / 1.2;

		center_a = mlx->min_val + (mlx->max_val - mlx->min_val) / 2.0;
		center_b = mlx->im_min + (mlx->im_max - mlx->im_min) / 2.0;

		mlx->min_val = center_a + (mlx->min_val - center_a) / zoom_factor;
		mlx->max_val = center_a + (mlx->max_val - center_a) / zoom_factor;
		mlx->im_min = center_b + (mlx->im_min - center_b) / zoom_factor;
		mlx->im_max = center_b + (mlx->im_max - center_b) / zoom_factor;
	}
}
