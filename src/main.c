/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:05:55 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/23 09:29:04 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

//error function to write


// parse function to write
char	*s_argv2(char **argv)
{
	if (ft_strcmp(argv[1],"mandel") == 0)
		return "mandel";
	else if (ft_strcmp(argv[1],"julia") == 0)
		return "julia";
	else
		return "error";
}

int	error()
{
	printf("Error\n");
	printf("Usage : ./fractol \"fractal wanted\"\n");
	printf("Available = mandle or julia\n");
	printf("Once in program ; press h for help with parameters\n");
	return (1);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->win_x = 1280;
	mlx->win_y = 720;
	mlx->mouse.move = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x,mlx->win_y, "fract-OL");
	mlx->img.img = mlx_new_image(mlx->mlx_ptr,mlx->win_x,mlx->win_y);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length, &mlx->img.endian);
	mlx->m_state = 'n';
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		t_mlx mlx;
		if (s_argv2(argv))
		{
			if (ft_strcmp(argv[1],"mandel") == 0)
				init_mandle_param(&mlx);
			else if (ft_strcmp(argv[1],"julia") == 0)	
				init_julia_param(&mlx);
			else
				return (error());
		}
		init_mlx(&mlx);
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