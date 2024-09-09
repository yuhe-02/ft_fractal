#include "ft_fractal.h"

int close_window(t_data *data) 
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}

int mouse_hook(int button, int x, int y, void *param) 
{
    t_data *img = (t_data *)param;
    if (button == 4) { // マウスホイールアップ（ズームイン）
        img->zoom *= 1.2;
    } else if (button == 5) { // マウスホイールダウン（ズームアウト）
        img->zoom /= 1.2;
    }
    mlx_clear_window(img->mlx, img->win);
    choose_fractal(img);
    return 0;
}

int key_hook(int keycode, void *param) 
{
    t_data *img = (t_data *)param;
    double move_step = 0.05 / img->zoom; // ズームに応じて移動量を調整

    if (keycode == KEY_ESC) {
        mlx_destroy_window(img->mlx, img->win);
        exit(0);
	}
    else if (keycode == KEY_LEFT) 
        img->offsetX -= move_step;
    else if (keycode == KEY_RIGHT) 
        img->offsetX += move_step;
    else if (keycode == KEY_UP) 
        img->offsetY -= move_step;
    else if (keycode == KEY_DOWN) 
        img->offsetY += move_step;
    mlx_clear_window(img->mlx, img->win);
    choose_fractal(img);
    return (0);
}