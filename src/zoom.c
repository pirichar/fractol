
#include "../include/fractol.h"

void	chose_zoom(int key, t_mlx *mlx)
{
	if (key == KEY_L)
	{
		if (mlx->z_state == 'o')
			mlx->z_state = 'l';
		else
			mlx->z_state = 'o';
	}
	if (mlx->z_state == 'l')
		zoom_locked(key, mlx);
	else
		zoom_in_out(key, mlx);
}

void	zoom_locked(int key, t_mlx *mlx)
{
	if (key == KEY_Z)
	{
		mlx->n = mlx->n * 1.3;
		mlx->max_val = mlx->max_val / 1.3;
		mlx->min_val = mlx->min_val / 1.3;
		mlx->zoom_base = mlx->zoom_base * 1.3;
	}
	if (key == KEY_X)
	{
		mlx->n = mlx->n / 1.3;
		mlx->max_val = mlx->max_val * 1.3;
		mlx->min_val = mlx->min_val * 1.3;
		mlx->zoom_base = mlx->zoom_base / 1.3;
	}
	if (key == KEY_PLUS)
		mlx->zoom_base = mlx->zoom_base * 10;
	if (key == KEY_MINUS)
		mlx->zoom_base = mlx->zoom_base / 10;
	if (mlx->f_state == 'm')
		mandlebroth(mlx);
	else
		julia_set(mlx);
}

void	zoom_in_out(int key, t_mlx *mlx)
{
	if (key == KEY_Z)
	{
		mlx->n = mlx->n * 1.3;
		mlx->max_val = mlx->max_val / 1.3;
		mlx->min_val = mlx->min_val / 1.02;
		mlx->zoom_base = mlx->zoom_base * 1.3;
	}
	if (key == KEY_X)
	{
		mlx->n = mlx->n / 1.3;
		mlx->max_val = mlx->max_val * 1.3;
		mlx->min_val = mlx->min_val * 1.02;
		mlx->zoom_base = mlx->zoom_base / 1.3;
	}
	if (key == KEY_PLUS)
		mlx->zoom_base = mlx->zoom_base * 10;
	if (key == KEY_MINUS)
		mlx->zoom_base = mlx->zoom_base / 10;
	if (mlx->f_state == 'm')
		mandlebroth(mlx);
	else
		julia_set(mlx);
}
