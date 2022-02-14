#include "../mlx/mlx.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "keys.h"
#include "colors.h"

typedef struct s_color_pal
{
	int	clr_black;
	int clr_10;
	int clr_20;
	int clr_30;
	int clr_40;
	int clr_50;
	int clr_60;
	int clr_70;
	int clr_80;
	int clr_90;
	int clr_white;
}			t_color_pal;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_x;
	int		win_y;
	char	state; 
	double	min_val;
	double	max_val;
	double	c1;
	double	c2;
	int		max_i;
	double	n;
	int		zoom_base;
	t_data	img;
	t_color_pal	col;

}			t_mlx;

void	ft_putchar(char c);
void    ft_putstring(char *str);
void    clearscreen(t_mlx *mlx);
void    print_mandle(int i, int A, int B, t_mlx *mlx);
void    rev_print_mandle(int i, int A, int B, t_mlx *mlx);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_strcmp(char *s1, char*s2);

//mandle.c
int		mandlebroth(t_mlx *mlx);
void	mandle_green(t_mlx *mlx);
void	mandle_blue(t_mlx *mlx);
void	mandle_red(t_mlx *mlx);
void	init_mandle(t_mlx *mlx);
void	mandle_black(t_mlx *mlx);

//julia.c
int		julia_set(t_mlx *mlx);
void	init_julia(t_mlx *mlx);