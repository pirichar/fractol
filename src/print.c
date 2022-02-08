/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:47:58 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/08 12:12:13 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void    print_mandle(int i, int A, int B, t_mlx *mlx)
{
	if(i > 0 && i <= (float)mlx->max_i * 10 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_black);
	if(i > (float)mlx->max_i * 10 / 100 && i <= (float)mlx->max_i * 20 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_10);
	if(i > (float)mlx->max_i * 20 / 100 && i <= (float)mlx->max_i * 30 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_20);
	if(i > (float)mlx->max_i * 30 / 100 && i <= (float)mlx->max_i * 40 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_30);
	if(i > (float)mlx->max_i * 40 / 100 && i <= (float)mlx->max_i * 50 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_40);
	if(i > (float)mlx->max_i * 50 / 100 && i <= (float)mlx->max_i * 60 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_50);
	if (i > (float)mlx->max_i * 60 / 100 && i <= (float)mlx->max_i * 70 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_60);
	if(i > (float)mlx->max_i * 70 / 100 && i <= (float)mlx->max_i * 80 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_70);
	if(i > (float)mlx->max_i * 80 / 100 && i <= (float)mlx->max_i * 90 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_80);
	if(i > (float)mlx->max_i * 900 / 100 && i <= (float)mlx->max_i * 100 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_90);
	if(i==mlx->max_i)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_white);
}

void    rev_print_mandle(int i, int A, int B, t_mlx *mlx)
{
	if(i > 0 && i <= (float)mlx->max_i * 10 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_white);
	if(i > (float)mlx->max_i * 10 / 100 && i <= (float)mlx->max_i * 20 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_90);
	if(i > (float)mlx->max_i * 20 / 100 && i <= (float)mlx->max_i * 30 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_80);
	if(i > (float)mlx->max_i * 30 / 100 && i <= (float)mlx->max_i * 40 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_70);
	if(i > (float)mlx->max_i * 40 / 100 && i <= (float)mlx->max_i * 50 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_60);
	if(i > (float)mlx->max_i * 50 / 100 && i <= (float)mlx->max_i * 60 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_50);
	if (i > (float)mlx->max_i * 60 / 100 && i <= (float)mlx->max_i * 70 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_50);
	if(i > (float)mlx->max_i * 70 / 100 && i <= (float)mlx->max_i * 80 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_30);
	if(i > (float)mlx->max_i * 80 / 100 && i <= (float)mlx->max_i * 90 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_20);
	if(i > (float)mlx->max_i * 900 / 100 && i <= (float)mlx->max_i * 100 / 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_10);
	if(i==mlx->max_i)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,mlx->col.clr_black);
}

void    clearscreen(t_mlx *mlx)
{
	for(int i = 0; i < mlx->win_x; i++)
		for(int j = 0; j < mlx->win_y;j++)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,i, j,0x000000);
}
