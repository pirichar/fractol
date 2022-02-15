/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:26:15 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/15 11:43:29 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
"The" Mandelbrot set is the set obtained from the quadratic recurrence equation
 z_(n+1)=z_n^2+C 

Complexe Squaring:
* (A+iB)^2
* =(A+iB)(A+iB)
* =(AA)+(AB)I+(AB)i-BB
* =(AA-BB)+(2AB)i
*/
void	print_info_mandle(t_mlx *mlx, int a, int b)
{
	printf("Mandelbrot\nThis is min_val %f\n and this is max_val %f\n",
		mlx->min_val, mlx->max_val);
	printf("This is max iteration %d\nThis is n %f\n", mlx->max_i, mlx->n);
	printf("This is win_x %d\nThis is win_y %d\n", mlx->win_x, mlx->win_y);
	printf("This is A %d\nThis is B %d\n", a, b);
	printf("This is base %d\nThis is mlx state %c\n", mlx->zoom_base,
		mlx->f_state);
	printf("This is z_state %c\n", mlx->z_state);
}

static int	calculate_mandle(t_mlx *mlx)
{
	double	x;
	double	y;
	double	t;
	int		i;

	x = 0;
	y = 0;
	i = 1;
	while (i++ < mlx->max_i)
	{
		t = x;
		x = (x * x) - (y * y) + mlx->a;
		y = (2 * t * y) + mlx->b;
		if ((x * x) + (y * y) > 4)
			break ;
	}
	return (i);
}

int	mandlebroth(t_mlx *mlx)
{
	int	a;
	int	b;
	int	i;

	clearscreen(mlx);
	b = 0;
	while (b++ < mlx->win_y)
	{
		mlx->b = mlx->max_val - (b / mlx->n);
		a = 0;
		while (a++ < mlx->win_x)
		{
			mlx->a = mlx->min_val + (a / mlx->n);
			i = calculate_mandle(mlx);
			print_mandle(i, a, b, mlx);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	print_info_mandle(mlx, a, b);
	return (0);
}

void	init_mandle(t_mlx *mlx)
{
	mlx->z_state = 'o';
	mlx->min_val = -2.45;
	mlx->max_val = 1.05;
	mlx->n = mlx->win_y / 2;
	mlx->zoom_base = 10;
	mlx->f_state = 'm';
	mlx->max_i = 60;
	mandle_black(mlx);
	mandlebroth(mlx);
}
