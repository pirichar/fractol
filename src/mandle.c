/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:26:15 by pirichar          #+#    #+#             */
/*   Updated: 2022/03/18 08:45:57 by pirichar         ###   ########.fr       */
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
void	print_info_mandle(t_mlx *mlx)
{
	printf(RED"Mandelbrot\nThis is min_val %f\n and this is max_val %f\n"RESET,
		mlx->min_val, mlx->max_val);
	printf("This is max iteration %d\nThis is n %f\n", mlx->max_i, mlx->n);
	printf("This is win_x %d\nThis is win_y %d\n", mlx->win_x, mlx->win_y);
	printf("This is mlx->a %Lf\nThis is mlx->b %Lf\n", mlx->a, mlx->b);
	printf("This is mouse_x %d\n This is mouse_y%d\n",
		mlx->mouse.x_pos, mlx->mouse.y_pos);
	printf("This is base %Lf\nThis is mlx state %c\n", mlx->zoom_base,
		mlx->f_state);
	printf("This is zoom_state %c\n", mlx->zoom_state);
	printf("THis is mouse.move %d\n", mlx->mouse.move);
	printf("This is menu_state %c\n", mlx->menu_state);
	printf("This is_looping %c\n", mlx->is_looping);
}

/*
	z_n^2+C 
	x represent z_real
	y represent z_im
	mlx->a represent c_real 
	mlx->b represent z_real
*/

static int	calculate_mandle(t_mlx *mlx)
{
	long double	t;
	int			i;

	i = 0;
	mlx->x = 0;
	mlx->y = 0;
	while (i++ < mlx->max_i)
	{
		t = mlx->x;
		mlx->x = (mlx->x * mlx->x) - (mlx->y * mlx->y) + mlx->a;
		mlx->y = (2 * t * mlx->y) + mlx->b;
		if ((mlx->x * mlx->x) + (mlx->y * mlx->y) > 4.0)
			break ;
	}
	return (i);
}

/*
	z_n^2+C 
	mlx->a represent c_real 
	mlx->b represent z_real
	min_val = --gauche ++droite
	max_val == --bas ++haut
*/

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
	mlx->zoom_state = 'o';
	mlx->min_val = -2.45;
	mlx->max_val = 1.05;
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

void	start_with_mandle(t_mlx *mlx)
{
	mlx->f_state = 'm';
	mlx->is_active = 'n';
}
