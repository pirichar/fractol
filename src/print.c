/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:47:58 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/15 10:36:13 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}


void	print_mandle(int i, int A, int B, t_mlx *mlx)
{
	if (A <= mlx->win_x && B <= mlx->win_y)
	{
		if (i > 0 && i <= (float)mlx->max_i * 6 / 100)
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_black);
		if(i > (float)mlx->max_i * 6 / 100 && i <= (float)mlx->max_i * 7 / 100)
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_30);	
		if(i > (float)mlx->max_i * 7 / 100 && i <= (float)mlx->max_i * 8 / 100)	
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_20);	
		if(i > (float)mlx->max_i * 8 / 100 && i <= (float)mlx->max_i * 9 / 100)	
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_10);
		if(i > (float)mlx->max_i * 9 / 100 && i <= (float)mlx->max_i * 10 / 100)	
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_40);			
		if (i > (float)mlx->max_i * 10/100 && i <= (float)mlx->max_i * 20/100)
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_10);
		if (i > (float)mlx->max_i * 20/100 && i <= (float)mlx->max_i * 30/100)
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_20);
		if (i > (float)mlx->max_i * 30 / 100 && i <= (float)mlx->max_i * 40/100)
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_30);
		if (i > (float)mlx->max_i * 40 / 100 && i <= (float)mlx->max_i * 50/100)
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_40);
		if (i > (float)mlx->max_i * 50 / 100 && i <= (float)mlx->max_i * 60/100)
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_50);
		if (i > (float)mlx->max_i * 60 / 100 && i <= (float)mlx->max_i * 70/100)
			my_mlx_pixel_put(&mlx->img, A, B, mlx->col.clr_60);
		if (i > (float)mlx->max_i * 70 / 100 && i <= (float)mlx->max_i * 80/100)
			my_mlx_pixel_put(&mlx->img,A,B,mlx->col.clr_70);
		if (i > (float)mlx->max_i * 80 / 100 && i <= (float)mlx->max_i * 90 / 100)
			my_mlx_pixel_put(&mlx->img,A,B,mlx->col.clr_80);
		if (i > (float)mlx->max_i * 900 / 100 && i <= (float)mlx->max_i * 100 / 100)
			my_mlx_pixel_put(&mlx->img,A,B,mlx->col.clr_90);
		if ( i == mlx->max_i)
			my_mlx_pixel_put(&mlx->img,A,B,mlx->col.clr_black);
	}
}

void	shift_palet(t_mlx *mlx)
{
	int tmp;

	tmp = mlx->col.clr_10;
	// mlx->col.clr_black = mlx->col.clr_10;
	mlx->col.clr_10 = mlx->col.clr_20;
	mlx->col.clr_20 = mlx->col.clr_30;
	mlx->col.clr_30 = mlx->col.clr_40;
	mlx->col.clr_40 = mlx->col.clr_50;
	mlx->col.clr_50 = mlx->col.clr_60;
	mlx->col.clr_60 = mlx->col.clr_70;
	mlx->col.clr_70 = mlx->col.clr_80;
	mlx->col.clr_80 = mlx->col.clr_90;
	mlx->col.clr_90 = tmp;
	// mlx->col.clr_white = tmp;
}

void    clearscreen(t_mlx *mlx)
{
	int i;
	int j;

	i =0;
	while (i < mlx->win_x)
	{
		j = 0;
		while (j < mlx->win_y)
		{
			my_mlx_pixel_put(&mlx->img,i,j,mlx->col.clr_black);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr,mlx->win_ptr,mlx->img.img,0,0);		
}
