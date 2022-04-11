/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:31:26 by pirichar          #+#    #+#             */
/*   Updated: 2022/04/06 11:08:30 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	print_info_julia(t_mlx *mlx)
{
	printf(RED"Julia's Set\nThis is min_val %f\n and this is max_val %f\n"RESET,
		mlx->min_val, mlx->max_val);
	printf("This is max iteration %d\nThis is n %f\n", mlx->max_i, mlx->n);
	printf("This is win_x %d\nThis is win_y %d\n", mlx->win_x, mlx->win_y);
	printf("This is mouse_x %d\n This is mouse_y%d\n",
		mlx->mouse.x_pos, mlx->mouse.y_pos);
	printf("This is mlx->mouse.move = %d\n", mlx->mouse.move);
	printf("This is mlx->c1%f\nThis is mlx->c2 %f\n", mlx->c1, mlx->c2);
	printf("This is base %Lf\n", mlx->zoom_base);
	printf("This is f_state %c\n", mlx->f_state);
}

static int	calculate_julia(t_mlx *mlx)
{
	long double	t;
	int			i;

	i = 1;
	mlx->x = mlx->a;
	mlx->y = mlx->b;
	while (i++ < mlx->max_i)
	{
		t = mlx->x;
		mlx->x = (mlx->x * mlx->x) - (mlx->y * mlx->y) + mlx->c1;
		mlx->y = (2 * t * mlx->y) + mlx->c2;
		if ((mlx->x * mlx->x) +(mlx->y * mlx->y) > 4)
			break ;
	}
	return (i);
}

int	julia_set(t_mlx *mlx)
{
	int	a;
	int	b;
	int	i;

	clearscreen(mlx);
	b = 0;
	while (b++ <= mlx->win_y)
	{
		mlx->b = mlx->max_val - (b / mlx->n);
		a = 0;
		while (a++ <= mlx->win_x)
		{
			mlx->a = mlx->min_val + (a / mlx->n);
			i = calculate_julia(mlx);
			print_mandle(i, a, b, mlx);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	show_menu(mlx);
	print_info_julia(mlx);
	return (0);
}

void	init_julia(t_mlx *mlx)
{
	mlx->zoom_state = 'o';
	mlx->min_val = -1.882566;
	mlx->max_val = 1.094675;
	mlx->n = 338;
	mlx->zoom_base = 16;
	mlx->f_state = 'j';
	mlx->c1 = -0.787545;
	mlx->c2 = -0.134741;
	mlx->max_i = 60;
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
