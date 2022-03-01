/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:10:00 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/28 07:58:04 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mouse_mover(int x, int y, t_mlx *mlx)
{
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

int	mousehook(int key, int x, int y, t_mlx *mlx)
{
	if (mlx->mouse.move == 1)
		mouse_mover(x, y, mlx);
	if (mlx->is_active == 'y')
	{
		if (key == MOUSE_UP)
		{
			mlx->n = mlx->n * 1.1;
			mlx->max_val = mlx->max_val / 1.01;
			mlx->min_val = mlx->min_val / 1.2;
			mlx->zoom_base = mlx->zoom_base * 1.1;
		}
		if (key == MOUSE_DOWN)
		{
			mlx->n = mlx->n / 1.1;
			mlx->max_val = mlx->max_val * 1.01;
			mlx->min_val = mlx->min_val * 1.2;
			if (mlx->zoom_base > 4)
				mlx->zoom_base = mlx->zoom_base * 0.9;
		}
		refresh_mandle(mlx);
	}
	return (0);
}