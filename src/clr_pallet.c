/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr_pallet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:13:29 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/15 10:10:14 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//maybe create a state for the color in the struct so I know how to init itppp
void	mandle_green(t_mlx *mlx)
{
	mlx->col.clr_black = COLOR_black;
	mlx->col.clr_10 = COLOR_1;
	mlx->col.clr_20 = COLOR_2;
	mlx->col.clr_30 = COLOR_3;
	mlx->col.clr_40 = COLOR_4;
	mlx->col.clr_50 = COLOR_5;
	mlx->col.clr_60 = COLOR_6;
	mlx->col.clr_70 = COLOR_7;
	mlx->col.clr_80 = COLOR_8;
	mlx->col.clr_90 = COLOR_9;
	mlx->col.clr_white = COLOR_white;
}

void	mandle_blue(t_mlx *mlx)
{
	mlx->col.clr_black = COLOR_black;
	mlx->col.clr_10 = COLOR_11;
	mlx->col.clr_20 = COLOR_12;
	mlx->col.clr_30 = COLOR_13;
	mlx->col.clr_40 = COLOR_14;
	mlx->col.clr_50 = COLOR_15;
	mlx->col.clr_60 = COLOR_16;
	mlx->col.clr_70 = COLOR_17;
	mlx->col.clr_80 = COLOR_18;
	mlx->col.clr_90 = COLOR_19;
	mlx->col.clr_white = COLOR_white;
}

void	mandle_red(t_mlx *mlx)
{
	mlx->col.clr_black = COLOR_black;
	mlx->col.clr_10 = COLOR_21;
	mlx->col.clr_20 = COLOR_22;
	mlx->col.clr_30 = COLOR_23;
	mlx->col.clr_40 = COLOR_24;
	mlx->col.clr_50 = COLOR_25;
	mlx->col.clr_60 = COLOR_26;
	mlx->col.clr_70 = COLOR_27;
	mlx->col.clr_80 = COLOR_28;
	mlx->col.clr_90 = COLOR_29;
	mlx->col.clr_white = COLOR_white;
}

void	mandle_black(t_mlx *mlx)
{
	mlx->col.clr_black = COLOR_black;
	mlx->col.clr_10 = COLOR_31;
	mlx->col.clr_20 = COLOR_32;
	mlx->col.clr_30 = COLOR_33;
	mlx->col.clr_40 = COLOR_34;
	mlx->col.clr_50 = COLOR_35;
	mlx->col.clr_60 = COLOR_36;
	mlx->col.clr_70 = COLOR_37;
	mlx->col.clr_80 = COLOR_38;
	mlx->col.clr_90 = COLOR_39;
	mlx->col.clr_white = COLOR_white;
}

void	mandle_funk(t_mlx *mlx)
{
	mlx->col.clr_black = COLOR_black;
	mlx->col.clr_10 = NEON_RE;
	mlx->col.clr_20 = NEON_OR;
	mlx->col.clr_30 = NEON_YE;
	mlx->col.clr_40 = NEON_GR;
	mlx->col.clr_50 = NEON_LT_GR;
	mlx->col.clr_60 = NEON_BL;
	mlx->col.clr_70 = NEON_LT_BL;
	mlx->col.clr_80 = NEON_LT_PUR;
	mlx->col.clr_90 = NEON_PUR;
	mlx->col.clr_white = COLOR_white;
}
