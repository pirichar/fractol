#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

int     keypress(int key, t_mlx *mlx)
{
	//init and clearing
	if (key == KEY_M)
		init_mandle(mlx);
	if (key == KEY_C)
			clearscreen(mlx);
	//movement could regroup them under one if then function parse
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
	//zoom in could regroup zoom and zoom out in one if then function parse
	if(key == KEY_Z)
	{
		mlx->n = mlx->n + 30;
		mlx->offset_x -= 30;
		mlx->offset_y -= 55;
		mandlebroth(mlx);
	}
	//zoom out
	if(key == KEY_X)
	{
		mlx->n-=100;
		printf("This is min_val %f\n and this is max_val %f\n", mlx->min_val,mlx->max_val);
		mandlebroth(mlx);
		printf("Zommed in\n");
	}
	//iteration +
	if(key == KEY_I)
	{
		mlx->max_i +=50;
		mandlebroth(mlx);
	}	
	//iteration -
	if(key == KEY_O)
	{
		mlx->max_i -=50;
		mandlebroth(mlx);
	}
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit (0);
	}
	//colors
	if(key == KEY_B)
	{
		printf("Life should be bluer\n");
		mandle_blue(mlx);
		mandlebroth(mlx);
	}
	if(key == KEY_R)
	{
		printf("Life should be RED RED RED\n");
		mandle_red(mlx);
		mandlebroth(mlx);
	}
	if(key == KEY_G)
	{
		printf("Life with the green\n");
		mandle_green(mlx);
		mandlebroth(mlx);
	}
	if(key == KEY_UP)
	{
		mlx->min_val += 0.25;
		mlx->max_val -= 0.25;
		mandlebroth(mlx);
	}
	if(key == KEY_DOWN)
	{
		mlx->min_val -= 0.25;
		mlx->max_val += 0.25;
		mandlebroth(mlx);
	}
	if(key == KEY_G)
	{
		mandle_green(mlx);
		mandlebroth(mlx);
	}
	return (0);
}


int main()
{   
	t_mlx mlx;

	mlx.win_x = 1440;
	mlx.win_y = 875;
	//mlx init renvoie un void étoile qui est l'identifiant de la connection au serveur graphique
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_x,mlx.win_y, "fract-OL");

	mlx.img.img = mlx_new_image(mlx.mlx_ptr,mlx.win_x,mlx.win_y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx_key_hook(mlx.win_ptr, keypress, &mlx);
	mlx_loop(mlx.mlx_ptr);

}