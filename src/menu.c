/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:32:17 by pirichar          #+#    #+#             */
/*   Updated: 2022/02/23 09:46:13 by pirichar         ###   ########.fr       */
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
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 20, 10, mlx->col.clr_wh, str);
}
void	show_menu(t_mlx *mlx)
{
	display_info(mlx);
	char	*str;
	if(mlx->m_state == 'o')
	{
		str = "ARROWS | WASD - MOVE FRACTAL";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 30, mlx->col.clr_wh, str);
		str = "RETURN - INIT FRACTALS";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 50, mlx->col.clr_wh, str);
		str = "Z or X or Mouse wheel - ZOOM IN OR OUT";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 70, mlx->col.clr_wh, str);
		str = "I or O - INCREASE/DECREASE ITERATIONS";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 90, mlx->col.clr_wh, str);
		str = "N - Activate mouse movement in Julia";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 110, mlx->col.clr_wh, str);
		str = "WASD - PLAY WITH JULIA";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 130, mlx->col.clr_wh, str);
		str = "1 to 5 - CHANGE COLOR";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 150, mlx->col.clr_wh, str);
		str = "P - ROTATE COLOR PALETTE";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 170, mlx->col.clr_wh, str);
		str = "PLUS OR MINUS - ARROW SENSITIVITY";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 190, mlx->col.clr_wh, str);
		str = "ESC - EXIT PROGRAM";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 30, 210, mlx->col.clr_wh, str);
	}
}