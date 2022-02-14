#include "../include/fractol.h"

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
int	ft_strcmp(char *s1, char*s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}

int     keypress(int key, t_mlx *mlx)
{
	printf("%x\n",key);
	//init and clearing
	if (key == KEY_M)
		init_mandle(mlx);
	if (key == KEY_C)
			clearscreen(mlx);
	//zoom in could regroup zoom and zoom out in one if then function parse
	if(key == KEY_Z)
	{
		mlx->n = mlx->n * 1.3;
		mlx->max_val = mlx->max_val / 1.3;
		mlx->min_val = mlx->min_val / 1.02;
		mlx->zoom_base = mlx->zoom_base * 1.3;
		// mlx->max_val = mlx->max_val * 1.08;
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
	//zoom out
	if(key == KEY_X)
	{
		mlx->n = mlx->n / 1.3;
		mlx->max_val = mlx->max_val * 1.3;
		mlx->min_val = mlx->min_val * 1.02;
		mlx->zoom_base = mlx->zoom_base / 1.3;
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
	//iteration +
	if(key == KEY_I)
	{
		mlx->max_i =  mlx->max_i * 2;
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}	
	//iteration -
	if(key == KEY_O)
	{
		mlx->max_i = mlx->max_i / 2;
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit (0);
	}
	//colors
	if(key == KEY_1)
	{
		printf("Life should be bluer\n");
		mandle_blue(mlx);
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
	if(key == KEY_2)
	{
		printf("Life should be RED RED RED\n");
		mandle_red(mlx);
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
	if(key == KEY_3)
	{
		printf("Life with the green\n");
		mandle_green(mlx);
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
	if(key == KEY_4)
	{
		printf("Life with the green\n");
		mandle_black(mlx);
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
	if(key == KEY_PLUS)
	{
		mlx->zoom_base = mlx->zoom_base * 10;
	}
	if(key == KEY_MINUS)
	{
		mlx->zoom_base = mlx->zoom_base / 10;
	}
	if(key == KEY_W)
	{
		//  mlx->min_val += 0.1;
		mlx->max_val -= (1.0/mlx->zoom_base);
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
	if(key == KEY_S)
	{
		// mlx->min_val -= 0.1;
		mlx->max_val += (1.0/mlx->zoom_base);
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
		if(key == KEY_A)
	{
		mlx->min_val += (1.0/mlx->zoom_base);
		// mlx->max_val -= 0.1;
		if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}
	if(key == KEY_D)
	{
		mlx->min_val -= (1.0/mlx->zoom_base);
		// mlx->max_val += 0.1;
	if (mlx->state == 'm')
			mandlebroth(mlx);
		else 
			julia_set(mlx);
	}

	//JULIA FUNCTIONS
	if(key == KEY_J)
	{
		init_julia(mlx);
	}
	if(key == KEY_UP)
	{
		//  mlx->min_val += 0.1;
		if(mlx->state =='j')
		{
			mlx->c1 = mlx->c1  * 1.1;
			julia_set(mlx);
		}
	}
	if(key == KEY_DOWN)
	{
		// mlx->min_val -= 0.1;
	if(mlx->state == 'j')
		{
			mlx->c1 = mlx->c1  * 0.9;
			julia_set(mlx);
		}
	}
		if(key == KEY_LEFT)
	{
		if(mlx->state == 'j')
		{
			mlx->c2 = mlx->c2  * 1.1;
			julia_set(mlx);
		}
	}
	if(key == KEY_RIGHT)
	{
		if(mlx->state == 'j')
		{
			mlx->c2 = mlx->c2  * 0.9;
			julia_set(mlx);
		}
	}
	
	return (0);
}


int main()
{   
	t_mlx mlx;

	mlx.win_x = 1280;
	mlx.win_y = 720;
	//mlx init renvoie un void étoile qui est l'identifiant de la connection au serveur graphique
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.win_x,mlx.win_y, "fract-OL");

	mlx.img.img = mlx_new_image(mlx.mlx_ptr,mlx.win_x,mlx.win_y);
	mlx.img.addr = mlx_get_data_addr(mlx.img.img, &mlx.img.bits_per_pixel, &mlx.img.line_length, &mlx.img.endian);
	mlx_key_hook(mlx.win_ptr, keypress, &mlx);
	mlx_loop(mlx.mlx_ptr);
}