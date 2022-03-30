/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:47:50 by pirichar          #+#    #+#             */
/*   Updated: 2022/03/30 10:23:26 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	loop_palet(int key, t_mlx *mlx)
{
	if (key == KEY_6)
	{
		if (mlx->is_looping == 'n')
			mlx->is_looping = 'y';
		else
			mlx->is_looping = 'n';
	}
}

void	shift_palet_funk(t_mlx *mlx)
{
	int	tmp;

	tmp = mlx->col.black;
	mlx->col.black = mlx->col.a;
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

void	shift_palet(t_mlx *mlx)
{
	int	tmp;

	tmp = mlx->col.a;
	if (mlx->clr_state == 'f')
		shift_palet_funk(mlx);
	else
	{
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
}
