#include "./mlx/mlx.h"
#include <unistd.h>


//First thing to do to link to the graphical processor
//void    *mlx_init();

//mlx_new_window = manage window

//mlx_pixel_put = draw inside window

//mlx_new_image = manipulate images

//mlx_loop =  handle keyboard or mouse events



/*linking Minilibx on MACOS
to use MinilibX functions, you'll need to link you software with the MinilibX library, and several system frameworks:
-lmlx -framewrork OpenGl -framework AppKit
You may also need to specify the path to the MinilibX library, using the -L flag*/
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     deal_key(int key, void *param)
{
    (void)key;
    (void)param;
    ft_putchar('X');
    return (0);
}

int     print_rectangle(int key, void *param)
{
    if(key == 'a')
        {
            for(int i = 0;i<5;i++)
            {
               for(int j = 0;j < 5;j++)
                   mlx_pixel_put(mlx_ptr, win_ptr,i, j,0x00FF0000);
            }
        }
}

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;
    //mlx init renvoie un void étoile qui est l'identifiant de la connection au serveur graphique
    mlx_ptr = mlx_init();
    //for the mlx_new_window man
    //man /usr/share/man/man3/mlx_new_window.1
    //void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title)
    //int   mlx_clear_window(void *mlx_ptr, void *win_ptr);
    //int   mlx_destroy_window(void *mlx_ptr, void *win_ptr);
    // MLX new window renvoie aussi un void /toile qui est l'identifiant de la nouvelle fenêtre
    // Cet identifiant est suceptible d'être utilisé par la suite par exemple pour dessiner dedans
    win_ptr = mlx_new_window(mlx_ptr, 500,500, "mlx 42");
    //Cette fonction est en charge de dessiner et d'ouvrir la fenetre
    //Elle s'occupera aussi de gerer les evenements genre clic souris;bouger souris; clic clavier
    /*  int mlx_loop ( void *mlx_ptr );

       int  mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
       int  mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
       int  mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );
       int  mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );*/
        //to draw in a window :
    //man /usr/share/man/man3/mlx_pixel_put.1
    mlx_key_hook(win_ptr, deal_key, (void *)0);


    mlx_loop(mlx_ptr);

    

}