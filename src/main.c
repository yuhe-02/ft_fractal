#include "ft_fractal.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

    if (keycode == KEY_ESC) { // ESCキーを押したとき（プログラム終了）
        mlx_destroy_window(img->mlx, img->win);
        exit(0);
    }
    else if (keycode == KEY_LEFT) { // 左矢印キー
        img->offsetX -= move_step;
    }
    else if (keycode == KEY_RIGHT) { // 右矢印キー
        img->offsetX += move_step;
    }
    else if (keycode == KEY_UP) { // 上矢印キー
        img->offsetY -= move_step;
    }
    else if (keycode == KEY_DOWN) { // 下矢印キー
        img->offsetY += move_step;
    }

    mlx_clear_window(img->mlx, img->win);
    choose_fractal(img);
    return 0;
}

void init_images(t_data *img, int argc) 
{
    img->mlx = mlx_init();
    img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Some Set");
    img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
    img->zoom = 1.0;
    img->offsetX = 0.0;
    img->offsetY = 0.0;
    if (argc % 2 == 1)
        img->set_type = 0;
    else
        img->set_type = 1;
} 

int	main(int argc, char **argv)
{
    t_data	img;

    init_images(&img, argc);
    choose_fractal(&img);
    mlx_hook(img.win, 17, 0, close_window, &img);
    mlx_key_hook(img.win, key_hook, &img);
    mlx_mouse_hook(img.win, mouse_hook, &img);
    mlx_loop(img.mlx);
    return (0);
}