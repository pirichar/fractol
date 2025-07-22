/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:31:26 by pirichar          #+#    #+#             */
/*   Updated: 2024/01/08 17:24:31 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"



int	calculate_julia(t_mlx *mlx, int x, int y)
{
	long double	t, a, b, zx, zy;
	int			i;

	i = 1;
	a = mlx->min_val + (long double)x / mlx->win_x * (mlx->max_val - mlx->min_val);
    b = mlx->im_max - (long double)y / mlx->win_y * (mlx->im_max - mlx->im_min);
	zx = a;
	zy = b;
	while (i++ < mlx->max_i)
	{
		t = zx;
		zx = (zx * zx) - (zy * zy) + mlx->c1;
		zy = (2 * t * zy) + mlx->c2;
		if ((zx * zx) +(zy * zy) > 4)
			break ;
	}
	return (i);
}

int	julia_set(t_mlx *mlx)
{
	render_fractal(mlx);
	return (0);
}

void	init_julia(t_mlx *mlx)
{
	long double range_re;

	mlx->f_state = 'j';
	mlx->min_val = -2.0;
	mlx->max_val = 2.0;
	range_re = mlx->max_val - mlx->min_val;
	mlx->im_max = range_re * mlx->win_y / mlx->win_x / 2.0;
	mlx->im_min = -mlx->im_max;
	mlx->c1 = -0.787545;
	mlx->c2 = -0.134741;
	mlx->max_i = 200;
	mlx->mouse.move = 0;
	mlx->is_active = 'y';
	mlx->is_looping = 'n';
	mandle_black(mlx);
	julia_set(mlx);
}

void	start_with_julia(t_mlx *mlx)
{
	mlx->f_state = 'j';
	mlx->is_active = 'n';
}
