/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:10:00 by pirichar          #+#    #+#             */
/*   Updated: 2022/03/20 17:38:46 by pirichar         ###   ########.fr       */
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
	mlx->n = mlx->n * 1.3;
	if (mlx->f_state == 'j' || mlx->min_val < -1.809494)
	{
		mlx->max_val = mlx->max_val * 0.77;
		mlx->min_val = mlx->min_val * 0.98;
	}
	mlx->zoom_base = mlx->zoom_base * 1.3;
}

void	zoom_out(t_mlx *mlx)
{
	mlx->n = mlx->n / 1.3;
	if (mlx->f_state == 'j' || mlx->min_val < -1.809494)
	{
		mlx->max_val = mlx->max_val / 0.77;
		mlx->min_val = mlx->min_val / 0.98;
	}
	if (mlx->zoom_base > 5)
		mlx->zoom_base = mlx->zoom_base / 1.3;
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
