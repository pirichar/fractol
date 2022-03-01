/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:26:15 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/28 08:12:56 by pirichar         ###   ########.fr       */
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
https://www.geeksforgeeks.org/fractals-in-cc/ 
*/
void	print_info_mandle(t_mlx *mlx)
{
	printf("Mandelbrot\nThis is min_val %f\n and this is max_val %f\n",
		mlx->min_val, mlx->max_val);
	printf("This is max iteration %d\nThis is n %f\n", mlx->max_i, mlx->n);
	printf("This is win_x %d\nThis is win_y %d\n", mlx->win_x, mlx->win_y);
	printf("This is mlx->a %f\nThis is mlx->b %f\n", mlx->a, mlx->b);
	printf("This is mouse_x %d\n This is mouse_y%d\n",
		mlx->mouse.x_pos, mlx->mouse.y_pos);
	printf("This is base %d\nThis is mlx state %c\n", mlx->zoom_base,
		mlx->f_state);
	printf("This is z_state %c\n", mlx->z_state);
	printf("THis is mouse.move %d\n", mlx->mouse.move);
	printf("This is m_state %c\n", mlx->m_state);
	printf("This is_looping %c\n", mlx->is_looping);
}

static int	calculate_mandle(t_mlx *mlx)
{
	double	x;
	double	y;
	double	t;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (i++ < mlx->max_i)
	{
		t = x;
		x = (x * x) - (y * y) + mlx->a;
		y = (2 * t * y) + mlx->b;
		if ((x * x) + (y * y) > 4.0)
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
	show_menu(mlx);
	print_info_mandle(mlx);
	return (0);
}

void	init_mandle(t_mlx *mlx)
{
	mlx->z_state = 'o';
	mlx->min_val = -2.45;
	mlx->max_val = 1.05;
	mlx->mouse.x_pos = mlx->win_x / 2;
	mlx->mouse.y_pos = mlx->win_y / 2 ;
	mlx->n = mlx->win_y / 2;
	mlx->zoom_base = 10;
	mlx->f_state = 'm';
	mlx->is_active = 'y';
	mlx->is_looping = 'n';
	mlx->max_i = 60;
	mlx->mouse.move = 0;
	mandle_black(mlx);
	mandlebroth(mlx);
}

void	init_mandle_param(t_mlx *mlx)
{
	mlx->z_state = 'o';
	mlx->min_val = -2.45;
	mlx->max_val = 1.05;
	mlx->n = mlx->win_y / 2;
	mlx->zoom_base = 10;
	mlx->f_state = 'm';
	mlx->is_active = 'n';
	mlx->max_i = 60;
	mlx->mouse.move = 0;
	mlx->mouse.x_pos = mlx->win_x / 2;
	mlx->mouse.y_pos = mlx->win_y / 2 ;
	mandle_black(mlx);
}
