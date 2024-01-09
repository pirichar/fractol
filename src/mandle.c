/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:26:15 by pirichar          #+#    #+#             */
/*   Updated: 2024/01/08 17:25:02 by pirichar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
"The" Mandelbrot set is the set obtained from the quadratic recurrence equation
 z_(n+1)= z_n^2+C 

Complexe Squaring:
* (A+iB)^2
* =(A+iB)(A+iB)
* =(AA)+(AB)I+(AB)i-BB
* =(AA-BB)+(2AB)i
https://www.geeksforgeeks.org/fractals-in-cc/ 
*/
void	print_info_mandle(t_mlx *mlx)
{
	printf(RED"Madlebrot\nThis is min_val %f\n and this is max_val %f\nThis is im_min %f\nThis is im_max %f\n"RESET,
		mlx->min_val, mlx->max_val, mlx->im_min, mlx->im_max);
	printf("This is max iteration %d\nThis is n %f\n", mlx->max_i, mlx->n);
	printf("This is win_x %d\nThis is win_y %d\n", mlx->win_x, mlx->win_y);
	printf("This is mlx->a %Lf\nThis is mlx->b %Lf\n", mlx->a, mlx->b);
	printf("This is mlx->im_min %lf\n", mlx->im_min);
	printf("This is mouse_x %d\n This is mouse_y%d\n",
		mlx->mouse.x_pos, mlx->mouse.y_pos);
	printf("This is base %Lf\nThis is mlx state %c\n", mlx->zoom_base,
		mlx->f_state);
	printf("THis is mouse.move %d\n", mlx->mouse.move);
	printf("This is menu_state %c\n", mlx->menu_state);
	printf("This is_looping %c\n", mlx->is_looping);
}

static int calculate_mandle(t_mlx *mlx, int x, int y)
{
    long double t;
    int i;

    i = 0;
    mlx->a = mlx->min_val + (x / mlx->n);
    mlx->b = mlx->im_min + (y / mlx->n);
    mlx->x = 0;
    mlx->y = 0;
    while (i++ < mlx->max_i)
    {
        t = mlx->x;
        mlx->x = (mlx->x * mlx->x) - (mlx->y * mlx->y) + mlx->a;
        mlx->y = (2 * t * mlx->y) + mlx->b;
        if ((mlx->x * mlx->x) + (mlx->y * mlx->y) > 4.0)
            break ;
    }
    return (i);
}


int mandlebroth(t_mlx *mlx)
{
    int i;
    int x;
    int y;

    clearscreen(mlx);
    y = 0;
    for (int b = mlx->win_y - 1; b >= 0; b--)
    {
        x = 0;
        for (int a = 0; a < mlx->win_x; a++)
        {
            i = calculate_mandle(mlx, x, y);
            print_mandle(i, a, b, mlx);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
    show_menu(mlx);
    print_info_mandle(mlx);
    return (0);
}



void	init_mandle(t_mlx *mlx)
{
	mlx->min_val = -2.25;
	mlx->max_val = 1.05;
	mlx->n = 360;
	mlx->zoom_base = 10;
	mlx->f_state = 'm';
	mlx->is_active = 'y';
	mlx->is_looping = 'n';
	mlx->max_i = 60;
	mlx->im_min = -1.10000;
	mlx->mouse.move = 0;
	mandle_black(mlx);
	mandlebroth(mlx);
}

void	start_with_mandle(t_mlx *mlx)
{
	mlx->f_state = 'm';
	mlx->is_active = 'n';
}
