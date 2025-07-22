/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pirichar <pirichar@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 13:00:27 by pirichar          #+#    #+#             */
/*   Updated: 2025/07/21 18:10:00 by Gemini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include "keys.h"
# include "colors.h"

# define NUM_THREADS 8

typedef struct s_color_pal
{
	int	black;
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;
	int	f;
	int	g;
	int	h;
	int	i;
	int	w;
} t_color_pal;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct s_mouse
{
	double	x;
	double	y;
	int		move;
	int		x_pos;
	int		y_pos;
	int		drag_start_x;
	int		drag_start_y;
} t_mouse;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*s;
	int				win_x;
	int				win_y;
	char			f_state;
	char			clr_state;
	char			zoom_state;
	char			menu_state;
	char			is_looping;
	char			is_active;
	char			is_dragging;
	long double		min_val;
	long double		max_val;
	long double		im_max;
	long double		im_min;
	long double		c1;
	long double		c2;
	int				max_i;
	long double		zoom_base;
	t_data			img;
	t_color_pal		col;
	t_mouse			mouse;
} t_mlx;

typedef struct s_thread_data
{
	t_mlx	*mlx;
	int		y_start;
} t_thread_data;

void	clearscreen(t_mlx *mlx);
void	reset_screen(t_mlx *mlx);
void	print_mandle(int i, int a, int b, t_mlx *mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_strcmp(char *s1, char*s2);
char	*ft_strjoin(const char *s1, const char *s2);
void	show_menu(t_mlx *mlx);
char	*ft_itoa(int n);
int		ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);

//mandle.c
int		mandlebroth(t_mlx *mlx);
void	mandle_green(t_mlx *mlx);
void	mandle_blue(t_mlx *mlx);
void	mandle_red(t_mlx *mlx);
void	init_mandle(t_mlx *mlx);
void	mandle_black(t_mlx *mlx);
void	mandle_funk(t_mlx *mlx);
void	shift_palet(t_mlx *mlx);
void	start_with_mandle(t_mlx *mlx);

//keypress functions
void	zoom_in_out(int key, t_mlx *mlx);
void	chose_color(int key, t_mlx *mlx);
void	change_iterations(int key, t_mlx *mlx);
void	fractal_movement(int key, t_mlx *mlx);
void	param_modif(int key, t_mlx *mlx);
void	chose_zoom(int key, t_mlx *mlx);
void	zoom_locked(int key, t_mlx *mlx);
void	zoom_burning(int key, t_mlx *mlx);
void	refresh_mandle(t_mlx *mlx);
int		mouse_mover(int x, int y, t_mlx *mlx);
int		mouse_press_hook(int button, int x, int y, t_mlx *mlx);
int		mouse_release_hook(int button, int x, int y, t_mlx *mlx);
int		keypress(int key, t_mlx *mlx);
void	init_fractals(int key, t_mlx *mlx);
void	modif_fractals(int key, t_mlx *mlx);
void	init_first_fractal(t_mlx *mlx);

//color rotation
void	loop_palet(int key, t_mlx *mlx);

//julia.c
int		julia_set(t_mlx *mlx);
void	init_julia(t_mlx *mlx);
void	start_with_julia(t_mlx *mlx);

//burning ship
int		burningship(t_mlx *mlx);
void	init_ship(t_mlx *mlx);
void	start_with_ship(t_mlx *mlx);

//Sierpinski 
void	init_sierpinski(t_mlx *mlx);
int		sierpinski(t_mlx *mlx);

//render.c
void	render_fractal(t_mlx *mlx);

#endif