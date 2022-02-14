#include "../include/fractol.h"

int     julia_set(t_mlx *mlx)
{
	clearscreen(mlx);
	int A,B;
	double a,b,i,x,y,t;
	for(B=0;B<=mlx->win_y;B++)
	{
		b=mlx->max_val-(B/mlx->n);
		for(A=0;A<=mlx->win_x;A++)
		{
			a=mlx->min_val+(A/mlx->n); 
			x=a;
			y=b;
			for(i=1;i<mlx->max_i;i++)
			{
				t=x;
				x=(x*x)-(y*y)+mlx->c1;
				y=(2*t*y)+mlx->c2;
				if ((x*x)+(y*y)>4)
					break;
			}
			print_mandle(i,A,B,mlx);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr,mlx->win_ptr,mlx->img.img,0,0);
	printf("Julia's Set\nThis is min_val %f\n and this is max_val %f\n", mlx->min_val,mlx->max_val);
	printf("This is max iteration %d\nThis is n %f\n", mlx->max_i,mlx->n);
	printf("This is win_x %d\nThis is win_y %d\n", mlx->win_x,mlx->win_y);
	printf("This is A %d\nThis is B %d\n", A,B);
	printf("This is base %d\n",mlx->zoom_base);
	return (0);
}

void	init_julia(t_mlx *mlx)
{
	mlx->min_val=-1.882566,
	mlx->max_val=1.094675;
	mlx->n=338;
	mlx->zoom_base = 16;
	mlx->state = 'j';
	mlx->c1 = -0.787545;
	mlx->c2 = -0.134741;
	// mlx->offset_x = 600;
	// mlx->offset_y = 350;
	mlx->max_i=60;
	mandle_black(mlx);
	julia_set(mlx);
}