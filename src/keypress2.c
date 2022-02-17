#include "../include/fractol.h"

void	refresh_mandle(t_mlx *mlx)
{
	if (mlx->f_state == 'm')
		mandlebroth(mlx);
	else if (mlx->f_state == 'j')
		julia_set(mlx);
	else if (mlx->f_state == 'b')
		burningship(mlx);
	else if (mlx->f_state == 's')
		sierpinski(mlx);
	else 
		return ;
}

void	chose_color(int key, t_mlx *mlx)
{
	if (key == KEY_1)
		mandle_blue(mlx);
	if (key == KEY_2)
		mandle_red(mlx);
	if (key == KEY_3)
		mandle_green(mlx);
	if (key == KEY_4)
		mandle_black(mlx);
	if (key == KEY_5)
		mandle_funk(mlx);
	if (key == KEY_P)
		shift_palet(mlx);
	refresh_mandle(mlx);
}

void	change_iterations(int key, t_mlx *mlx)
{
	if (key == KEY_I)
		mlx->max_i = mlx->max_i * 1.3;
	if (key == KEY_O)
		mlx->max_i = mlx->max_i / 1.3;
	refresh_mandle(mlx);
}