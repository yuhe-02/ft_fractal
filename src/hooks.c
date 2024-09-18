#include "ft_fractal.h"

int close_window(t_data *data) 
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}

static void change_centered(t_data *img, int x, int y)
{   
    img->offsetX = (x - WIDTH / 2.0) * (FRACTAL_RANGE / WIDTH) / img->zoom + img->offsetX;
    img->offsetY = (y - HEIGHT / 2.0) * (FRACTAL_RANGE / HEIGHT) / img->zoom + img->offsetY;
    printf("倍率：%f (x, y) = (%f, %f)\n", img->zoom, img->offsetX, img->offsetY);
}

int mouse_hook(int button, int x, int y, void *param) 
{
    t_data *img = (t_data *)param;
    if (button == MOUSE_WHEEL_UP)
        img->zoom *= ZOOM_MAG;
    else if (button == MOUSE_WHEEL_DOWN) 
        img->zoom /= ZOOM_MAG;
    else if (button == MOUSE_LEFT_CLICK)
        change_centered(img, x, y);
    mlx_clear_window(img->mlx, img->win);
    choose_fractal(img);
    return 0;
}

int key_hook(int keycode, void *param) 
{
    t_data *img = (t_data *)param;
    double move_step = MOVE_MAG / img->zoom;

    if (keycode == KEY_ESC) 
    {
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
    else if (keycode == KEY_C) 
        img->color_flg = 10;
    else if (keycode == KEY_B) 
        img->color_flg = 1;
    mlx_clear_window(img->mlx, img->win);
    choose_fractal(img);
    return (0);
}