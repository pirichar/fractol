
#include "../include/fractol.h" 

//https://www.geeksforgeeks.org/sierpinski-triangle/ 
// to compile with its own main ; replace mlx->n for n in main
// gcc -Wall -Werror -Wextra -Lmlx -lmlx -framework OpenGL -framework AppKit sierpinski.cx
 
int sierpinski(t_mlx *mlx)
{
	int y;
	int i;
	int x;

	clearscreen(mlx);
	y = (mlx->n - 1) + mlx->n;
	x = 0;
    while(y >= 0) 
	{
 
        // printing space till
        // the value of y
		i = 0;
        while (i < y) 
		{
			mlx_pixel_put(mlx->mlx_ptr,mlx->win_ptr,x,y,mlx->col.clr_black);
            // printf(" ");
			i++;
        }
 
        // printing '*'
		x = 0;
        while (x + y < mlx->n)
		{
        // printing '*' at the appropriate position
        // is done by the and value of x and y
        // wherever value is 0 we have printed '*'
        	if(x & y)
			{
				mlx_pixel_put(mlx->mlx_ptr,mlx->win_ptr,x,y,mlx->col.clr_black);
				mlx_pixel_put(mlx->mlx_ptr,mlx->win_ptr,x+1,y,mlx->col.clr_black);
            	// printf("  ");
			}
        	else
			{
				mlx_pixel_put(mlx->mlx_ptr,mlx->win_ptr,x,y,mlx->col.clr_wh);
				mlx_pixel_put(mlx->mlx_ptr,mlx->win_ptr,x+1,y,mlx->col.clr_black);
            	// printf("* ");
			}
			x++;
        }
        // printf("\n");
		y--;
    }
	printf("This is mlx->n %f\n", mlx->n);
	return (0);
}

void	init_sierpinski(t_mlx *mlx)
 {
	mlx->z_state = 'o';
	mlx->n = mlx->win_y / 2;
	mlx->f_state = 's';
	sierpinski(mlx);
 }

// // Driver code
// int main()
// {
//     int n = 800;
//  	t_mlx mlx;
// 	mlx.win_x = 1280;
// 	mlx.win_y = 720;
// 	mlx.mlx_ptr = mlx_init();
// 	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_x,mlx.win_y, "fract-OL");
//     // Function calling
//     printSierpinski(n, &mlx);
// 	mlx_loop(mlx.mlx_ptr);
//     return 0;
// }