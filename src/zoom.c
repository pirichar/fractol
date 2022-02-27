/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:43:13 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/27 12:55:12 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	chose_zoom(int key, t_mlx *mlx)
{
	if (key == KEY_L)
	{
		if (mlx->z_state == 'o')
			mlx->z_state = 'l';
		else
			mlx->z_state = 'o';
	}
	if (mlx->z_state == 'l')
		zoom_locked(key, mlx);
	else
		zoom_in_out(key, mlx);
	if (key == KEY_MINUS)
		mlx->zoom_base = mlx->zoom_base * 2;
	if (key == KEY_PLUS && mlx->zoom_base > 1)
		mlx->zoom_base = mlx->zoom_base * 0.5;
	refresh_mandle(mlx);
}

void	zoom_in_out(int key, t_mlx *mlx)
{
	if (key == KEY_Z)
	{
		mlx->n = mlx->n * 1.3;
		mlx->max_val = mlx->max_val * 0.77;
		mlx->min_val = mlx->min_val * 0.98;
		mlx->zoom_base = mlx->zoom_base * 1.3;
	}
	if (key == KEY_X)
	{
		mlx->n = mlx->n / 1.3;
		mlx->max_val = mlx->max_val * 1.3;
		mlx->min_val = mlx->min_val * 1.02;
		if (mlx->zoom_base > 4)
			mlx->zoom_base = mlx->zoom_base * 0.5;
	}
}

void	zoom_locked(int key, t_mlx *mlx)
{
	if (key == KEY_Z)
	{
		mlx->n = mlx->n * 1.1;
		mlx->max_val = mlx->max_val / 1.01;
		mlx->min_val = mlx->min_val / 1.2;
		mlx->zoom_base = mlx->zoom_base * 1.1;
	}
	if (key == KEY_X)
	{
		mlx->n = mlx->n / 1.1;
		if (mlx->zoom_base > 4)
			mlx->zoom_base = mlx->zoom_base * 0.9;
	}
}
