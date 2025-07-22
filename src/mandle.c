/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:26:15 by pirichar          #+#    #+#             */
/*   Updated: 2024/01/08 17:25:02 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
"The" Mandelbrot set is the set obtained from the quadratic recurrence equation
 z_(n+1)= z_n^2+C 

Complexe Squaring:
* (A+iB)^2
* =(A+iB)(A+iB)
* =(AA)+(AB)I+(AB)i-BB
* =(AA-BB)+(2AB)i
https://www.geeksforgeeks.org/fractals-in-cc/ 
*/


int	calculate_mandle(t_mlx *mlx, int x, int y)
{
    long double t, a, b, zx, zy;
    int i;

    i = 0;
    a = mlx->min_val + (long double)x / mlx->win_x * (mlx->max_val - mlx->min_val);
    b = mlx->im_max - (long double)y / mlx->win_y * (mlx->im_max - mlx->im_min);
    zx = 0;
    zy = 0;
    while (i++ < mlx->max_i)
    {
        t = zx;
        zx = (zx * zx) - (zy * zy) + a;
        zy = (2 * t * zy) + b;
        if ((zx * zx) + (zy * zy) > 4.0)
            break ;
    }
    return (i);
}

int mandlebroth(t_mlx *mlx)
{
    render_fractal(mlx);
    return (0);
}



void	init_mandle(t_mlx *mlx)
{
	mlx->min_val = -2.25;
	mlx->max_val = 1.05;
	mlx->f_state = 'm';
	mlx->is_active = 'y';
	mlx->is_looping = 'n';
	mlx->max_i = 200;
	mlx->im_min = -1.10000;
	mlx->im_max = mlx->im_min + (mlx->max_val - mlx->min_val) * mlx->win_y / mlx->win_x;
	mlx->mouse.move = 0;
	mandle_black(mlx);
	mandlebroth(mlx);
}

void	start_with_mandle(t_mlx *mlx)
{
	mlx->f_state = 'm';
	mlx->is_active = 'n';
}
