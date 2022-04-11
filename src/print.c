/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:47:58 by pirichar          #+#    #+#             */
/*   Updated: 2022/04/11 11:04:12 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	print_mandle_small(int i, int a, int b, t_mlx *mlx)
{
	if (a <= mlx->win_x && b <= mlx->win_y)
	{
		if (i > 0 && i <= (float)mlx->max_i * 0.01)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.black);
		if (i > (float)mlx->max_i * 0.01 && i <= (float)mlx->max_i * 0.02)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.a);
		if (i > (float)mlx->max_i * 0.02 && i <= (float)mlx->max_i * 0.03)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.b);
		if (i > (float)mlx->max_i * 0.03 && i <= (float)mlx->max_i * 0.04)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.c);
		if (i > (float)mlx->max_i * 0.04 && i <= (float)mlx->max_i * 0.05)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.d);
		if (i > (float)mlx->max_i * 0.06 && i <= (float)mlx->max_i * 0.07)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.e);
		if (i > (float)mlx->max_i * 0.07 && i <= (float)mlx->max_i * 0.08)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.f);
		if (i > (float)mlx->max_i * 0.08 && i <= (float)mlx->max_i * 0.09)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.g);
		if (i > (float)mlx->max_i * 0.09 && i <= (float)mlx->max_i * 0.10)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.h);
	}
}

void	print_mandle(int i, int a, int b, t_mlx *mlx)
{
	if (a <= mlx->win_x && b <= mlx->win_y)
	{
		print_mandle_small(i, a, b, mlx);
		if (i > (float)mlx->max_i * 0.1 && i <= (float)mlx->max_i * 0.2)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.b);
		if (i > (float)mlx->max_i * 0.2 && i <= (float)mlx->max_i * 0.3)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.c);
		if (i > (float)mlx->max_i * 0.3 && i <= (float)mlx->max_i * 0.4)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.d);
		if (i > (float)mlx->max_i * 0.4 && i <= (float)mlx->max_i * 0.6)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.e);
		if (i > (float)mlx->max_i * 0.6 && i <= (float)mlx->max_i * 0.7)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.f);
		if (i > (float)mlx->max_i * 0.7 && i <= (float)mlx->max_i * 0.8)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.g);
		if (i > (float)mlx->max_i * 0.8 && i <= (float)mlx->max_i * 0.9)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.h);
		if (i > (float)mlx->max_i * 0.9 && i <= (float)mlx->max_i * 1)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.i);
		if (i == mlx->max_i)
			my_mlx_pixel_put(&mlx->img, a, b, mlx->col.black);
	}
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
			my_mlx_pixel_put(&mlx->img, i, j, mlx->col.black);
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
			my_mlx_pixel_put(&mlx->img, i, j, COLOR_BLACK);
			j++;
		}
		i++;
	}
	mlx->f_state = 'n';
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
}
