#include "./mlx/mlx.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "keys.h"
#include "colors.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_x;
	int		win_y;
	double	min_val;
	double	max_val;
	int		max_iteration;
	double	n;
	int		offset_x;
	int		offset_y;
	t_data	img;
}			t_mlx;

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstring(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void    clearscreen(t_mlx *mlx)
{
	for(int i = 0; i < mlx->win_x; i++)
		for(int j = 0; j < mlx->win_y;j++)
			mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,i, j,0x000000);
}

void    print_mandle(int i, int A, int B, t_mlx *mlx)
{
	if(i > 1 && i <= 10)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_0);
	if(i > 10 && i <= 20)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_1);
	if(i > 20 && i <= 30)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_2);
	if(i > 30 && i <= 40)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_3);
	if(i > 40 && i <= 50)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_4);
	if(i > 50 && i <= 60)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_5);
	if(i > 60 && i <= 70)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_6);
	if(i > 70 && i <= 80)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_7);
	if(i > 80 && i <= 90)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_8);
	if(i > 90 && i < 100)
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_9);
	if(i==mlx->max_iteration)
	// {
	// 	my_mlx_pixel_put(&mlx->img,A+mlx->offset_x,B+mlx->offset_y,COLOR_10);
	// 	mlx_put_image_to_window(mlx->mlx_ptr,mlx->win_ptr,mlx->img.img,0,0);
	// }
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A+mlx->offset_x, B+mlx->offset_y,COLOR_10);
}
int     mandlebroth(t_mlx *mlx)
{
	clearscreen(mlx);
	int A,B;
	double a,b,i,x,y,t;
	for(B=0;B<=4*mlx->n;B++)
	{
		b=mlx->max_val-(B/mlx->n);
		for(A=0;A<=4*mlx->n;A++)
		{
			a=mlx->min_val+(A/mlx->n); 
			x=0;
			y=0;
			for(i=1;i<mlx->max_iteration;i++)
			{
				t=x;
				x=(x*x)-(y*y)+a;
				y=(2*t*y)+b;
				if ((x*x)+(y*y)>4)
					break;
			}
			print_mandle(i,A,B,mlx);
		}
	}
	ft_putstring("Mandelbroth\n");
	printf("This is min_val %f\n and this is max_val %f\n", mlx->min_val,mlx->max_val);
	return (0);
}

int     keypress(int key, t_mlx *mlx)
{
	if(key == KEY_C)
			clearscreen(mlx);
	if(key == KEY_M)
	{
		mlx->min_val=-2,
		mlx->max_val=2;
		mlx->n=30;
		mlx->offset_x = 450;
		mlx->offset_y = 300;
		mlx->max_iteration=100;
		mandlebroth(mlx);
	}
	if (key == KEY_W)
	{
		mlx->offset_y -= 100;
		mandlebroth(mlx);
	}
	if (key == KEY_A)
	{
		mlx->offset_x -= 100;
		mandlebroth(mlx);
	}
	if (key == KEY_S)
	{
		mlx->offset_y += 100;
		mandlebroth(mlx);
	}
	if (key == KEY_D)
	{
		mlx->offset_x += 100;
		mandlebroth(mlx);
	}
	if(key == KEY_Z)
	{
		// mlx->min_val = mlx->min_val - 0.1;
		// mlx->max_val = mlx->max_val + 0.1;
		mlx->n = mlx->n + 30;
		mlx->offset_x -= 30;
		mlx->offset_y -= 55;
		printf("This is min_val %f\n and this is max_val %f\n", mlx->min_val,mlx->max_val);
		mandlebroth(mlx);
		printf("Zommed in\n");
	}
	if(key == KEY_X)
	{
		// mlx->min_val = mlx->min_val + 0.1;
		// mlx->max_val = mlx->max_val - 0.1;
		mlx->n-=100;
		printf("This is min_val %f\n and this is max_val %f\n", mlx->min_val,mlx->max_val);
		mandlebroth(mlx);
		printf("Zommed in\n");
	}
	if(key == KEY_V)
	{
		mlx->min_val = mlx->min_val + 0.1;
		mlx->max_val = mlx->max_val + 0.1;
		mandlebroth(mlx);
	}
	if(key == KEY_B)
	{
		mlx->min_val = mlx->min_val - 0.1;
		mlx->max_val = mlx->max_val - 0.1;
		mandlebroth(mlx);
	}
	if(key == KEY_I)
	{
		mlx->max_iteration +=100;
		mandlebroth(mlx);
	}	
	if(key == KEY_O)
	{
		mlx->max_iteration -=100;
		mandlebroth(mlx);
	}
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit (0);
	}
	return (0);
}


int main()
{   
	t_mlx mlx;

	mlx.win_x = 1080;
	mlx.win_y = 720;
	//mlx init renvoie un void étoile qui est l'identifiant de la connection au serveur graphique
	mlx.mlx_ptr = mlx_init();
	//for the mlx_new_window man
	//man /usr/share/man/man3/mlx_new_window.1
	//void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
	//int   mlx_clear_window(void *mlx_ptr, void *win_ptr);
	//int   mlx_destroy_window(void *mlx_ptr, void *win_ptr);
	// MLX new window renvoie aussi un void /toile qui est l'identifiant de la nouvelle fenêtre
	// Cet identifiant est suceptible d'être utilisé par la suite par exemple pour dessiner dedans
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_x,mlx.win_y, "mlx 42");

	mlx.img.img = mlx_new_image(mlx.mlx_ptr,mlx.win_x,mlx.win_y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	//Cette fonction est en charge de dessiner et d'ouvrir la fenetre
	//Elle s'occupera aussi de gerer les evenements genre clic souris;bouger souris; clic clavier
	/*  int mlx_loop ( void *mlx_ptr );

	   int  mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
	   int  mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
	   int  mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
	   int  mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );*/
		//to draw in a window :
	//man /usr/share/man/man3/mlx_pixel_put.1
	mlx_key_hook(mlx.win_ptr, keypress, &mlx);
	// for(int i = 50;i<100;i++)
	//         {
	//            for(int j = 50;j < 100;j++)
	//                mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr,i, j,0x66ff99);
	//         }

	mlx_loop(mlx.mlx_ptr);

}