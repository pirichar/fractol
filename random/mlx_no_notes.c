#include "./mlx/mlx.h"
#include <unistd.h>


int main()
{
	//Identity of mlx to the graphical server
	void	*mlx_ptr;
	//Identity of the window
	void	*win_ptr;

	//init connection and create window
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 500, "my window");

	//Function that ask macOS to draw on screen and manage events 


	for (int i = 266; i < 532; i++)
	{
		for (int j = 166; j < 332; j++)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i,j, 0x66ff99);
		}
	}

	mlx_loop(mlx_ptr);
}
