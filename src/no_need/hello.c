#include <mlx.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    void *mlx;
    void *win;

	write(1, "hello\n", 6);
    // Initialize the Minilibx library
    mlx = mlx_init();
    if (!mlx) {
		printf("init faild\n");
        return (1);
    }

    // Create a new window
    win = mlx_new_window(mlx, 800, 600, "Minilibx Window");
    if (!win) {
		printf("new window faild\n");
        return (1);
    }

    // Fill the window with a red color
    mlx_clear_window(mlx, win);
    mlx_pixel_put(mlx, win, 400, 300, 0xFF0000); // A single red pixel

    // Enter the event loop
    mlx_loop(mlx);

    return (0);
}
