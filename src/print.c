/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:47:58 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/16 12:22:04 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_mandle(int i, int a, int b, t_mlx *mlx)
{
	if (a <= mlx->win_x && b <= mlx->win_y)
	{
		if (i > 0 && i <= (float)mlx->max_i * 0.06)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_black);
		if (i > (float)mlx->max_i * 0.06 && i <= (float)mlx->max_i * 0.08)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_30);
		if (i > (float)mlx->max_i * 0.08 && i <= (float)mlx->max_i * 0.1)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_40);
		if (i > (float)mlx->max_i * 0.1 && i <= (float)mlx->max_i * 0.2)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_10);
		if (i > (float)mlx->max_i * 0.2 && i <= (float)mlx->max_i * 0.3)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_20);
		if (i > (float)mlx->max_i * 0.3 && i <= (float)mlx->max_i * 0.4)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_30);
		if (i > (float)mlx->max_i * 0.4 && i <= (float)mlx->max_i * 0.6)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_50);
		if (i > (float)mlx->max_i * 0.6 && i <= (float)mlx->max_i * 0.8)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_60);
		if (i > (float)mlx->max_i * 0.8 && i <= (float)mlx->max_i * 0.9)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_80);
		if (i > (float)mlx->max_i * 0.9 && i <= (float)mlx->max_i * 1)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_90);
		if (i == mlx->max_i)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.clr_black);
	}
}

void	shift_palet(t_mlx *mlx)
{
	int	tmp;

	tmp = mlx->col.clr_black;
	mlx->col.clr_black = mlx->col.clr_10;
	mlx->col.clr_10 = mlx->col.clr_20;
	mlx->col.clr_20 = mlx->col.clr_30;
	mlx->col.clr_30 = mlx->col.clr_40;
	mlx->col.clr_40 = mlx->col.clr_50;
	mlx->col.clr_50 = mlx->col.clr_60;
	mlx->col.clr_60 = mlx->col.clr_70;
	mlx->col.clr_70 = mlx->col.clr_80;
	mlx->col.clr_80 = mlx->col.clr_90;
	mlx->col.clr_90 = mlx->col.clr_white;
	mlx->col.clr_white = tmp;
}

void	clearscreen(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->win_x)
	{
		j = 0;
		while (j < mlx->win_y)
		{
			my_mlx_pixel_put(&mlx->img, i, j, mlx->col.clr_black);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}

void	reset_screen(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->win_x)
	{
		j = 0;
		while (j < mlx->win_y)
		{
			my_mlx_pixel_put(&mlx->img, i, j, COLOR_black);
			j++;
		}
		i++;
	}
	mlx->f_state = 'n';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}