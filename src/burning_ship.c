/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:26:15 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/22 17:34:15 by pirichar         ###   ########.fr       */
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
	
for (i=0;i<N;i++) {
		for (j=0;j<N;j++) {
			p.x = 0;
			p.y = 0;
			c.x = midpoint.x + 2 * range * (i / (double)N - 0.5);
         	c.y = midpoint.y + 2 * range * (j / (double)N - 0.5);
			for (k=0;k<iteratemax;k++) {
				p.x = p0.x*p0.x - p0.y*p0.y - c.x;
				p.y = 2 * fabs(p0.x*p0.y) - c.y;
				p0 = p;
				if (p.x*p.x + p.y*p.y > 10)
					break;
			}
			//if (k == iteratemax)
			//	image[j*N+i] = 0;
			//else
				image[j*N+i] = k;
		}
	}
	
	MID POINT.x IS = -c 0.45 
	MID POINT.y IS = 0.5
	range is = -w 1.7 */
	
void	print_info_ship(t_mlx *mlx)
{
	printf("Burning Ship\nThis is min_val %f\n and this is max_val %f\n",
		mlx->min_val, mlx->max_val);
	printf("This is max iteration %d\nThis is n %f\n", mlx->max_i, mlx->n);
	printf("This is win_x %d\nThis is win_y %d\n", mlx->win_x, mlx->win_y);
	printf("This is base %d\nThis is mlx f_state %c\n", mlx->zoom_base,
		mlx->f_state);
	printf("This is midpoint.x %f\n This is midpoint.y %f\n", mlx->midpoint_x, mlx->midpoint_y);
	printf("This is z_state %c\nThis is n%f\n", mlx->z_state, mlx->n);
}

static int	calculate_ship(t_mlx *mlx)
{
	long double	x;
	long double	y;
	int		i;
	// int		t;

	x = 0;
	y = 0;
	i = 0;
	while (i < mlx->max_i)
	{
		//  t = x;
		x = (x * x) - (y * y) - mlx->a;
		y = fabs(2 * (x * y)) - mlx->b;
		if ((x * x) + (y * y) > 4)
			break ;
		i++;
	}
	return (i);
}

int	burningship(t_mlx *mlx)
{
	int	a;
	int	b;
	int	i;


	clearscreen(mlx);
	b = 0;
	while (b++ < mlx->win_y)
	{
		// mlx->b = mlx->midpoint_y + (2 * mlx->range * (b /(double)mlx->n - 0.5));
		mlx->b = mlx->max_val - (b / mlx->n);
		a = 0;
		while (a++ < mlx->win_x)
		{
			// mlx->a = mlx->midpoint_x + (2 * mlx->range * (a /(double)mlx->n - 0.5));
			mlx->a = mlx->min_val + (a / mlx->n);
			i = calculate_ship(mlx);
			// print_mandle(i, a, b, mlx);
			if (i == mlx->max_i)
				my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_black);
			else
				my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_wh);

		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	print_info_ship(mlx);
	return (0);
}


void	init_ship(t_mlx *mlx)
{
	mlx->z_state = 'o';
	// mlx->range = 0.4;
	mlx->midpoint_x = 1.75;
	mlx->midpoint_y = 0.03;
	mlx->min_val = -1.179828;
	mlx->max_val = 1.375875;
	// mlx->n = mlx->win_x / 2;
	mlx->n = 378;
	mlx->zoom_base = 10;
	mlx->f_state = 'b';
	mlx->max_i = 60;
	mandle_black(mlx);
	burningship(mlx);
}
