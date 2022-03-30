/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:26:15 by pirichar          #+#    #+#             */
/*   Updated: 2022/03/14 10:15:30 by pirichar         ###   ########.fr       */
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

void	print_info_ship(t_mlx *mlx)
{
	printf(RED"Burning Ship\nThis is min_val %f\n and this is max_val %f\n"RESET,
		mlx->min_val, mlx->max_val);
	printf("This is max iteration %d\nThis is n %f\n", mlx->max_i, mlx->n);
	printf("This is win_x %d\nThis is win_y %d\n", mlx->win_x, mlx->win_y);
	printf("This is base %Lf\nThis is mlx f_state %c\n", mlx->zoom_base,
		mlx->f_state);
	printf("This is zoom_state %c\nThis is n%f\n", mlx->zoom_state, mlx->n);
}

static int	calculate_ship(t_mlx *mlx)
{
	int			i;
	long double	t;

	mlx->x = 0;
	mlx->y = 0;
	i = 0;
	while (i < mlx->max_i)
	{
		t = ((mlx->x * mlx->x) - (mlx->y * mlx->y)) + mlx->a;
		mlx->y = fabsl(2 * mlx->x * mlx->y - mlx->b);
		mlx->x = fabsl(t);
		if ((mlx->x * mlx->x) + (mlx->y * mlx->y) > 4)
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
		mlx->b = mlx->max_val - (b / mlx->n);
		a = 0;
		while (a++ < mlx->win_x)
		{
			mlx->a = mlx->min_val + (a / mlx->n);
			i = calculate_ship(mlx);
			print_mandle(i, a, b, mlx);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	show_menu(mlx);
	print_info_ship(mlx);
	return (0);
}

void	init_ship(t_mlx *mlx)
{
	mlx->zoom_state = 'o';
	mlx->min_val = -2.578728;
	mlx->max_val = 2.175875;
	mlx->n = 223;
	mlx->zoom_base = 4;
	mlx->f_state = 'b';
	mlx->is_active = 'y';
	mlx->is_looping = 'n';
	mlx->max_i = 60;
	mandle_black(mlx);
	burningship(mlx);
}

void	start_with_ship(t_mlx *mlx)
{
	mlx->f_state = 'b';
	mlx->is_active = 'n';
}
