#include "./mlx/mlx.h"
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "keys.h"


#define COLOR_A 0x66ff33
#define COLOR_B 0x39e600
#define COLOR_C 0x2db300
#define COLOR_D 0x1a6600
#define COLOR_E 0x0d3300

//First thing to do to link to the graphical processor
//void    *mlx_init();

//mlx_new_window = manage window

//mlx_pixel_put = draw inside window

//mlx_new_image = manipulate images

//mlx_loop =  handle keyboard or mouse events

//for colors
//https://www.w3schools.com/colors/colors_picker.asp

/*linking Minilibx on MACOS
to use MinilibX functions, you'll need to link you software with the MinilibX library, and several system frameworks:
-lmlx -framewrork OpenGl -framework AppKit
You may also need to specify the path to the MinilibX library, using the -L flag*/

//should I include the fractal related stuff in this struct or should I create an other one ??
typedef struct s_mlx
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     win_x;
    int     win_y;
}          t_mlx;

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

int     deal_key(int key, void *param)
{
    (void)key;
    (void)param;
    ft_putchar('X');
    return (0);
}

void    clearscreen(t_mlx *mlx)
{
    for(int i = 0; i < mlx->win_x; i++)
        for(int j = 0; j < mlx->win_y;j++)
            mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,i, j,0x000000);
}

int     mandlebroth(int key, t_mlx*mlx)
{
    if(key == KEY_W)
    {
        //here a and b represent my min and max value
        //by changing them from 2 and -2 to smaller value i can zoom in my set
        clearscreen(mlx);
        int A,B,max=100;
        double a,b,i,x,y,t,n=300,min_val=-2,max_val=2;
        for(B=0;B<=4*n;B++)
        {
            b=max_val-(B/n);
            for(A=0;A<=4*n;A++)
            {
                a=min_val+(A/n); 
                x=0;
                y=0;
                for(i=1;i<max;i++)
                {
                    t=x;
                    x=(x*x)-(y*y)+a;
                    y=(2*t*y)+b;
                    if ((x*x)+(y*y)>4)
                        break;
                }
                if(i == max/10)
                    mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A-(min_val*100), B+(min_val*100),COLOR_E);
                if(i == max/5)
                    mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A-(min_val*100), B+(min_val*100),COLOR_D);
                if(i == max/4)
                    mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A-(min_val*100), B+(min_val*100),COLOR_C);
                if(i == max/2)
                    mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A-(min_val*100), B+(min_val*100),COLOR_B);
                if(i==max)
                    mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,A-(min_val*100), B+(min_val*100),COLOR_A);
            }
        }
    }
    ft_putstring("Mandelbroth\n");
    return (0);
}
int     keypress(int key, t_mlx *mlx)
{
    printf("This is key = %X\n", key);
    if(key == KEY_A)
        {
            clearscreen(mlx);
            for(int i = mlx->win_x/3; i< (mlx->win_x/3) * 2;i++)
            {
               for(int j = mlx->win_y/3;j < (mlx->win_y/3)*2;j++)
               {
                   if (i < j)
                     mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,i, j,0x66ff99);
               }
            }
            ft_putstring("A\n");
        }
     if(key == KEY_D)
        {
           clearscreen(mlx);
            for(int i = mlx->win_x/3; i< (mlx->win_x/3) * 2;i++)
            {
               for(int j = mlx->win_y/3;j < (mlx->win_y/3) * 2;j++)
               {
                   if (i > j)
                     mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr,i, j,0x66ff99);
               }
            }
            ft_putstring("B\n");
        }
    if(key == KEY_W)
        mandlebroth(KEY_W, mlx);
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