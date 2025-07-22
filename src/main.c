/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:55 by pirichar          #+#    #+#             */
/*   Updated: 2024/01/08 17:26:38 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

char	*s_argv2(char **argv)
{
	if (ft_strcmp(argv[1], "mandel") == 0)
		return ("mandel");
	else if (ft_strcmp(argv[1], "julia") == 0)
		return ("julia");
	else
		return ("error");
}

int	error(void)
{
	printf("Error\n");
	printf("Usage : ./fractol \"fractal wanted\"\n");
	printf("Available = mandle ,julia or ship\n");
	printf("Once in program ; press h for help with parameters\n");
	return (1);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->win_x = 1280;
	mlx->win_y = 720;
	mlx->mouse.move = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x,
			mlx->win_y, "Fractol");
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel,
			&mlx->img.line_length, &mlx->img.endian);
	mlx->menu_state = 'n';
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc == 2)
	{
		if (s_argv2(argv))
		{
			if (ft_strcmp(argv[1], "mandle") == 0)
				start_with_mandle(&mlx);
			else if (ft_strcmp(argv[1], "julia") == 0)
				start_with_julia(&mlx);
			else if (ft_strcmp(argv[1], "ship") == 0)
				start_with_ship(&mlx);
			else
				return (error());
		}
		init_mlx(&mlx);
		init_first_fractal(&mlx);
		mlx_key_hook(mlx.win_ptr, keypress, &mlx);
		mlx_hook(mlx.win_ptr, 6, 3, mouse_mover, &mlx);
		mlx_mouse_hook(mlx.win_ptr, mousehook, &mlx);
		show_menu(&mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		return (error());
	return (0);
}
