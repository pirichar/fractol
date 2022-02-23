/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:13:29 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/23 10:34:12 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//maybe create a state for the color in the struct so I know how to init itppp
void	mandle_green(t_mlx *mlx)
{
	mlx->col.black = COLOR_black;
	mlx->col.a = COLOR_1;
	mlx->col.b = COLOR_2;
	mlx->col.c = COLOR_3;
	mlx->col.d = COLOR_4;
	mlx->col.e = COLOR_5;
	mlx->col.f = COLOR_6;
	mlx->col.g = COLOR_7;
	mlx->col.h = COLOR_8;
	mlx->col.i = COLOR_9;
	mlx->col.w = COLOR_white;
}

void	mandle_blue(t_mlx *mlx)
{
	mlx->col.black = COLOR_black;
	mlx->col.a = COLOR_11;
	mlx->col.b = COLOR_12;
	mlx->col.c = COLOR_13;
	mlx->col.d = COLOR_14;
	mlx->col.e = COLOR_15;
	mlx->col.f = COLOR_16;
	mlx->col.g = COLOR_17;
	mlx->col.h = COLOR_18;
	mlx->col.i = COLOR_19;
	mlx->col.w = COLOR_white;
}

void	mandle_red(t_mlx *mlx)
{
	mlx->col.black = COLOR_black;
	mlx->col.a = COLOR_21;
	mlx->col.b = COLOR_22;
	mlx->col.c = COLOR_23;
	mlx->col.d = COLOR_24;
	mlx->col.e = COLOR_25;
	mlx->col.f = COLOR_26;
	mlx->col.g = COLOR_27;
	mlx->col.h = COLOR_28;
	mlx->col.i = COLOR_29;
	mlx->col.w = COLOR_white;
}

void	mandle_black(t_mlx *mlx)
{
	mlx->col.black = COLOR_black;
	mlx->col.a = COLOR_31;
	mlx->col.b = COLOR_32;
	mlx->col.c = COLOR_33;
	mlx->col.d = COLOR_34;
	mlx->col.e = COLOR_35;
	mlx->col.f = COLOR_36;
	mlx->col.g = COLOR_37;
	mlx->col.h = COLOR_38;
	mlx->col.i = COLOR_39;
	mlx->col.w = COLOR_white;
}

void	mandle_funk(t_mlx *mlx)
{
	mlx->col.black = NEON_LT_PUR;
	mlx->col.a = NEON_RE;
	mlx->col.b = NEON_OR;
	mlx->col.c = NEON_YE;
	mlx->col.d = NEON_GR;
	mlx->col.e = NEON_LT_GR;
	mlx->col.f = NEON_BL;
	mlx->col.g = NEON_LT_BL;
	mlx->col.h = NEON_LT_PUR;
	mlx->col.i = NEON_PUR;
	mlx->col.w = NEON_LT_PUR;
}
