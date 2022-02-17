
#include "../include/fractol.h"

int	mouse_mover(int x, int y, t_mlx *mlx)
{
	mlx->mouse.x_pos = x;
	mlx->mouse.y_pos = y;
	if (mlx->f_state == 'j' && mlx->mouse.move == 1)
	{
		if (x > mlx->win_x * 0.333)
			mlx->c1 = mlx->c1 + 0.05;
		if (x < mlx->win_x * 0.666)
			mlx->c1 = mlx->c1 - 0.05;
		if (y > mlx->win_y * 0.333)
			mlx->c2 = mlx->c2 + 0.05;
		if (y < mlx->win_y * 0.666)
			mlx->c2 = mlx->c2 - 0.05;
		refresh_mandle(mlx);
	}
	return (0);
}

int		mousehook(int key,int x, int y, t_mlx *mlx)
{
	if (mlx->mouse.move == 1)
		mouse_mover(x, y , mlx);
	if (mlx->f_state == 'j' || mlx->f_state == 'm' || mlx->f_state == 's') 
	{
		if(key == MOUSE_UP)
		{
			mlx->n = mlx->n * 1.3;
			mlx->max_val = mlx->max_val / 1.3;
			mlx->min_val = mlx->min_val / 1.02;
			mlx->zoom_base = mlx->zoom_base * 1.3;
		}
		if(key == MOUSE_DOWN)
		{
			mlx->n = mlx->n / 1.3;
			mlx->max_val = mlx->max_val * 1.3;
			mlx->min_val = mlx->min_val * 1.02;
			mlx->zoom_base = mlx->zoom_base / 1.3;
		}
		refresh_mandle(mlx);
	}
	return (0);
}