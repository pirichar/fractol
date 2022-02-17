/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:55 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/17 11:31:41 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int main()
{
	t_mlx mlx;

	mlx.win_x = 1280;
	mlx.win_y = 720;
	mlx.mouse.move = 0;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_x,mlx.win_y, "fract-OL");
	mlx.img.img = mlx_new_image(mlx.mlx_ptr,mlx.win_x,mlx.win_y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx_key_hook(mlx.win_ptr, keypress, &mlx);
	mlx_hook(mlx.win_ptr, 6, 3, mouse_mover, &mlx);
	mlx_mouse_hook(mlx.win_ptr, mousehook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}