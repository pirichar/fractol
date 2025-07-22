/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gemini <gemini@google.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:00:00 by Gemini            #+#    #+#             */
/*   Updated: 2025/07/21 18:00:00 by Gemini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// Forward declarations for calculation functions from other files
int			calculate_mandle(t_mlx *mlx, int x, int y);
int			calculate_julia(t_mlx *mlx, int x, int y);
int			calculate_ship(t_mlx *mlx, int x, int y);

static void	*thread_worker(void *arg)
{
	t_thread_data	*data;
	t_mlx			*mlx;
	int				x;
	int				y;
	int				i;

	data = (t_thread_data *)arg;
	mlx = data->mlx;
	for (y = data->y_start; y < mlx->win_y; y += NUM_THREADS)
	{
		for (x = 0; x < mlx->win_x; x++)
		{
			if (mlx->f_state == 'm')
				i = calculate_mandle(mlx, x, y);
			else if (mlx->f_state == 'j')
				i = calculate_julia(mlx, x, y);
			else // 'b'
				i = calculate_ship(mlx, x, y);
			print_mandle(i, x, y, mlx);
		}
	}
	return (NULL);
}

void	render_fractal(t_mlx *mlx)
{
	pthread_t		threads[NUM_THREADS];
	t_thread_data	thread_data[NUM_THREADS];
	int				i;

	clearscreen(mlx);
	i = 0;
	while (i < NUM_THREADS)
	{
		thread_data[i].mlx = mlx;
		thread_data[i].y_start = i;
		pthread_create(&threads[i], NULL, thread_worker, &thread_data[i]);
		i++;
	}
	i = 0;
	while (i < NUM_THREADS)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	show_menu(mlx);
}
