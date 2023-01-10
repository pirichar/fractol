/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:43:13 by pirichar          #+#    #+#             */
/*   Updated: 2023/01/09 14:25:24 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	chose_zoom(int key, t_mlx *mlx)
{
	if (key == KEY_L)
	{
		if (mlx->zoom_state == 'o')
			mlx->zoom_state = 'l';
		else
			mlx->zoom_state = 'o';
	}
	else if (mlx->zoom_state == 'l')
		zoom_locked(key, mlx);
	else if (mlx->zoom_state == 'o')
		zoom_in_out(key, mlx);
	if (key == KEY_MINUS)
		mlx->zoom_base = mlx->zoom_base * 2;
	if (key == KEY_PLUS && mlx->zoom_base > 1)
		mlx->zoom_base = mlx->zoom_base * 0.5;
	refresh_mandle(mlx);
}

void	zoom_burning(int key, t_mlx *mlx)
{
	if (key == KEY_Z)
	{
		mlx->n = mlx->n * 1.3;
		if (mlx->min_val < 1)
			mlx->min_val = mlx->min_val + 0.7;
		if (mlx->max_val > 0.05)
			mlx->max_val = mlx->max_val * 0.7;
		mlx->zoom_base = mlx->zoom_base * 1.3;
	}
	if (key == KEY_X)
	{
		mlx->n = mlx->n / 1.3;
		if (mlx->min_val < 1)
			mlx->max_val = mlx->max_val / 0.7;
		if (mlx->max_val > 0.05)
			mlx->min_val = mlx->min_val / 0.7;
		if (mlx->zoom_base > 5)
			mlx->zoom_base = mlx->zoom_base / 1.3;
	}
}

// void	zoom_in_out(int key, t_mlx *mlx)
// {
// 	if (key == KEY_Z)
// 	{
// 		mlx->n = mlx->n * 1.3;
// 		if (mlx->f_state == 'j' || mlx->min_val < -1.809494)
// 		{
// 			mlx->max_val = mlx->max_val * 0.77;
// 			mlx->min_val = mlx->min_val * 0.98;
// 		}
// 		mlx->zoom_base = mlx->zoom_base * 1.3;
// 	}
// 	if (key == KEY_X)
// 	{
// 		mlx->n = mlx->n / 1.3;
// 		if (mlx->min_val < -1.809494)
// 		{
// 			mlx->max_val = mlx->max_val / 0.77;
// 			mlx->min_val = mlx->min_val / 0.98;
// 		}
// 		if (mlx->zoom_base > 5)
// 			mlx->zoom_base = mlx->zoom_base / 1.3;
// 	}
// }

// void zoom_in_out(int key, t_mlx *mlx)
// {
//     double center_re, center_im, zoom_factor;

//     if (key == KEY_Z)
//     {
//         zoom_factor = 1.3;
//     }
//     else if (key == KEY_X)
//     {
//         zoom_factor = 1 / 1.3;
//     }
//     else
//     {
//         return;
//     }

//     // Calculate the center of the screen in complex coordinates
//     center_re = (mlx->max_val + mlx->min_val) / 2;
//     center_im = (mlx->im_max + mlx->im_min) / 2;

//     // Adjust the values of max_val and min_val based on the zoom factor and the center
//     mlx->max_val = center_re + (mlx->max_val - center_re) * zoom_factor;
//     mlx->min_val = center_re + (mlx->min_val - center_re) * zoom_factor;
//     mlx->im_max = center_im + (mlx->im_max - center_im) * zoom_factor;
//     mlx->im_min = center_im + (mlx->im_min - center_im) * zoom_factor;

//     // Update the zoom base
//     mlx->zoom_base *= zoom_factor;
// }

void zoom_in_out(int key, t_mlx *mlx)
{
    double center_re, zoom_factor;

    if (key == KEY_Z)
    {
        zoom_factor = 1.3;
    }
    else if (key == KEY_X)
    {
        zoom_factor = 1 / 1.3;
    }
    else
    {
        return;
    }

    // Calculate the center of the screen in real coordinates
    center_re = (mlx->max_val + mlx->min_val) / 2;

    // Adjust the values of max_val and min_val based on the zoom factor and the center
    mlx->max_val = center_re + (mlx->max_val - center_re) * zoom_factor;
    mlx->min_val = center_re + (mlx->min_val - center_re) * zoom_factor;

    // Adjust the values of im_max and im_min based on the zoom factor
    mlx->im_max *= zoom_factor;
    mlx->im_min *= zoom_factor;

    // Update the zoom base
    mlx->zoom_base *= zoom_factor;
}


void	zoom_locked(int key, t_mlx *mlx)
{
	if (key == KEY_Z)
	{
		mlx->n = mlx->n * 1.1;
		mlx->zoom_base = mlx->zoom_base * 1.1;
	}
	if (key == KEY_X)
	{
		mlx->n = mlx->n / 1.1;
		if (mlx->zoom_base > 5)
			mlx->zoom_base = mlx->zoom_base * 0.9;
	}
}
