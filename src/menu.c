/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:32:17 by pirichar          #+#    #+#             */
/*   Updated: 2022/03/30 10:23:02 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

char	*strjoin_free(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s2);
	return (str);
}

void	display_info(t_mlx *mlx)
{
	char	*str;

	str = "TO OPEN OR CLOSE HELP MENU PRESS H";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 10, mlx->col.w, str);
}

void	show_menu(t_mlx *mlx)
{
	display_info(mlx);
	if (mlx->menu_state == 'o')
	{
		mlx->s = "ARROWS | WASD - MOVE FRACTAL";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 30, mlx->col.w, mlx->s);
		mlx->s = "RETURN - INIT FRACTALS";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 50, mlx->col.w, mlx->s);
		mlx->s = "Z or X or Mouse wheel - ZOOM IN OR OUT";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 70, mlx->col.w, mlx->s);
		mlx->s = "I or O - INCREASE/DECREASE ITERATIONS";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 90, mlx->col.w, mlx->s);
		mlx->s = "WASD OR MOUSE IF ACTIVATED - PLAY WITH JULIA";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 110, mlx->col.w, mlx->s);
		mlx->s = "N - Activate mouse movement in Julia";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 130, mlx->col.w, mlx->s);
		mlx->s = "1 to 5 - CHANGE COLOR";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 150, mlx->col.w, mlx->s);
		mlx->s = "P - ROTATE COLOR PALETTE";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 170, mlx->col.w, mlx->s);
		mlx->s = "+ o - - ARROW SENSITIVITY";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 210, mlx->col.w, mlx->s);
		mlx->s = "ESC - EXIT PROGRAM";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 230, mlx->col.w, mlx->s);
	}
}
