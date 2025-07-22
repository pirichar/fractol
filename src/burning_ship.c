/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:26:15 by pirichar          #+#    #+#             */
/*   Updated: 2024/01/08 17:24:44 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
"The Burning Ship Fractal is a slight variant on the Mandelbrot Set Fractal. 
The basic Mandelbrot Fractal formula is z=z^2+c. 
The Burning Ship Fractal formula is z=abs(z)^2+c.

Complexe Squaring:
* (A+iB)^2
* =(A+iB)(A+iB)
* =(AA)+(AB)I+(AB)i-BB
* =(AA-BB)+(2AB)i

 http://paulbourke.net/fractals/burnship/burningship.c 
 https://spanishplus.tripod.com/maths/FractalBurningShip.htm

	Create the burning ship fractal
	Whole ship        -w 1.7 -c 0.45 0.5
	First small ship  -w 0.04 -c 1.755 0.03
	Second small ship -w .04 -c 1.625 0.035
	Tiny ship in tail -w 0.005 -c 1.941 0.004
	Another small one -w 0.008 -c 1.861 0.005
	*/



int	calculate_ship(t_mlx *mlx, int x, int y)
{
	int			i;
	long double	t, a, b, zx, zy;

	a = mlx->min_val + (long double)x / mlx->win_x * (mlx->max_val - mlx->min_val);
    b = mlx->im_max - (long double)y / mlx->win_y * (mlx->im_max - mlx->im_min);
	zx = 0;
	zy = 0;
	i = 0;
	while (i < mlx->max_i)
	{
		t = ((zx * zx) - (zy * zy)) + a;
		zy = fabsl((2 * zx * zy) - b);
		zx = fabsl(t);
		if ((zx * zx) + (zy * zy) > 4)
			break ;
		i++;
	}
	return (i);
}

int	burningship(t_mlx *mlx)
{
	render_fractal(mlx);
	return (0);
}

void	init_ship(t_mlx *mlx)
{
	long double range_re;

	mlx->f_state = 'b';
	mlx->min_val = -2.5;
	mlx->max_val = 1.5;
	range_re = mlx->max_val - mlx->min_val;
	mlx->im_max = range_re * mlx->win_y / mlx->win_x / 2.0;
	mlx->im_min = -mlx->im_max;
	mlx->max_i = 200;
	mlx->is_active = 'y';
	mlx->is_looping = 'n';
	mandle_black(mlx);
	burningship(mlx);
}

void	start_with_ship(t_mlx *mlx)
{
	mlx->f_state = 'b';
	mlx->is_active = 'n';
}
