#include "../include/fractol.h"
/* Here the mandelbrot set will be contained in the square 
* (2,-2) (2,2)
* (-2,-2) (-2,2)
* -2 is min_val 2 is max_val below
* The variable i is my iteration up to max_i 
* Max_i is my max iteration which takes care of details
* The variable n decide the size of the fractal
* It affects the lenghts of both loops
* It also affect the mandelbrot loop
* Complexe Squaring:
* (A+iB)^2
* =(A+iB)(A+iB)
* =(AA)+(AB)I+(AB)i-BB
* =(AA-BB)+(2AB)i
*/

int     mandlebroth(t_mlx *mlx)
{
	clearscreen(mlx);
	int A,B,i;
	long double a,b,x,y,t;
	for(B=0;B<=mlx->win_x;B++)
	{
		b=(((float)4.0 * (B - mlx->win_y))) / (mlx->win_y) - (float)0.0;
		for(A=0;A<=mlx->win_y;A++)
		{
			a=(((float)4.0 * (A - mlx->win_x))) / (mlx->win_x) - (float)0.0;
			    x=0.0;
                y=0.0;
                for(i=1;i<=1000;i++)
                {
                    t= ((x*x) - (y*y)) + b;
                    y= (((float)2.0 * x)*y) + a;
                    x = t;
                    if(((x*x)+(y*y)) > (float)4.0)
                        break;
                }
			print_mandle(i,A,B,mlx);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr,mlx->win_ptr,mlx->img.img,0,0);
	printf("Mandelbroth\nThis is min_val %f\n and this is max_val %f\n", mlx->min_val,mlx->max_val);
	printf("This is max iteration %d\nThis is n %f\n", mlx->max_i,mlx->n);
	printf("This is offset_x %d\nThis is offset_y %d\n", mlx->offset_x, mlx->offset_y);
	return (0);
}
void	mandle_green(t_mlx *mlx)
{
	mlx->col.clr_black = COLOR_BLACK;
	mlx->col.clr_10 = COLOR_1;
	mlx->col.clr_20 = COLOR_2;
	mlx->col.clr_30 = COLOR_3;
	mlx->col.clr_40 = COLOR_4;
	mlx->col.clr_50 = COLOR_5;
	mlx->col.clr_60 = COLOR_6;
	mlx->col.clr_70 = COLOR_7;
	mlx->col.clr_80 = COLOR_8;
	mlx->col.clr_90 = COLOR_9;
	mlx->col.clr_wh = COLOR_WHITE;
}
void	mandle_blue(t_mlx *mlx)
{
	mlx->col.clr_black = COLOR_BLACK;
	mlx->col.clr_10 = COLOR_11;
	mlx->col.clr_20 = COLOR_12;
	mlx->col.clr_30 = COLOR_13;
	mlx->col.clr_40 = COLOR_14;
	mlx->col.clr_50 = COLOR_15;
	mlx->col.clr_60 = COLOR_16;
	mlx->col.clr_70 = COLOR_17;
	mlx->col.clr_80 = COLOR_18;
	mlx->col.clr_90 = COLOR_19;
	mlx->col.clr_wh = COLOR_WHITE;
}
void	mandle_red(t_mlx *mlx)
{
	mlx->col.clr_black = COLOR_BLACK;
	mlx->col.clr_10 = COLOR_21;
	mlx->col.clr_20 = COLOR_22;
	mlx->col.clr_30 = COLOR_23;
	mlx->col.clr_40 = COLOR_24;
	mlx->col.clr_50 = COLOR_25;
	mlx->col.clr_60 = COLOR_26;
	mlx->col.clr_70 = COLOR_27;
	mlx->col.clr_80 = COLOR_28;
	mlx->col.clr_90 = COLOR_29;
	mlx->col.clr_wh = COLOR_WHITE;
}
void	mandle_black(t_mlx *mlx)
{
	mlx->col.clr_black = COLOR_BLACK;
	mlx->col.clr_10 = COLOR_31;
	mlx->col.clr_20 = COLOR_32;
	mlx->col.clr_30 = COLOR_33;
	mlx->col.clr_40 = COLOR_34;
	mlx->col.clr_50 = COLOR_35;
	mlx->col.clr_60 = COLOR_36;
	mlx->col.clr_70 = COLOR_37;
	mlx->col.clr_80 = COLOR_38;
	mlx->col.clr_90 = COLOR_39;
	mlx->col.clr_wh = COLOR_WHITE;
}

void	init_mandle(t_mlx *mlx)
{
	mlx->min_val=-2.5,
	mlx->max_val=2.5;
	mlx->n=30;
	mlx->offset_x = 600;
	mlx->offset_y = 350;
	mlx->max_i=60;
	mandle_black(mlx);
	mandlebroth(mlx);
}