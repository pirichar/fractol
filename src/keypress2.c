/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:58:38 by pirichar          #+#    #+#             */
/*   Updated: 2022/03/01 15:51:39 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	refresh_mandle(t_mlx *mlx)
{
	if (mlx->f_state == 'm')
		mandlebroth(mlx);
	else if (mlx->f_state == 'j')
		julia_set(mlx);
	else if (mlx->f_state == 'b')
		burningship(mlx);
	else
		return ;
}

void	chose_color(int key, t_mlx *mlx)
{
	if (mlx->is_active == 'y')
	{
		if (key == KEY_1)
			mandle_blue(mlx);
		if (key == KEY_2)
			mandle_red(mlx);
		if (key == KEY_3)
			mandle_green(mlx);
		if (key == KEY_4)
			mandle_funk(mlx);
		if (key == KEY_5)
			mandle_black(mlx);
		if (key == KEY_P)
			shift_palet(mlx);
		refresh_mandle(mlx);
	}
}

void	change_iterations(int key, t_mlx *mlx)
{
	if (key == KEY_I)
		mlx->max_i = mlx->max_i * 1.3;
	if (key == KEY_O)
	{
		if (mlx->max_i > 4)
			mlx->max_i = mlx->max_i / 1.3;
	}
	refresh_mandle(mlx);
}

void	init_first_fractal(t_mlx *mlx)
{
	if (mlx->f_state == 'm')
		init_mandle(mlx);
	if (mlx->f_state == 'j')
		init_julia(mlx);
	if (mlx->f_state == 'b')
		init_ship(mlx);
}

void	shift_palet(t_mlx *mlx)
{
	int	tmp;

	tmp = mlx->col.a;
	mlx->col.a = mlx->col.b;
	mlx->col.b = mlx->col.c;
	mlx->col.c = mlx->col.d;
	mlx->col.d = mlx->col.e;
	mlx->col.e = mlx->col.f;
	mlx->col.f = mlx->col.g;
	mlx->col.g = mlx->col.h;
	mlx->col.h = mlx->col.i;
	mlx->col.i = mlx->col.w;
	mlx->col.w = tmp;
}
