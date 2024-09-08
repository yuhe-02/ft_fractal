#include "ft_fractal.h"

void draw_julia_set(t_data *img) 
{

	// C の実部と虚部
	double	cx = -0.3;
	double	cy = -0.63;

    // フラクタルの描画処理
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double zx = (x - (WIDTH / 2)) / (0.5 * img->zoom * WIDTH) + img->offsetX;
            double zy = (y - (HEIGHT / 2)) / (0.5 * img->zoom *HEIGHT) + img->offsetY;
            int i = 0;
            while (zx * zx + zy * zy < 4 && i < ACRAC) {
                double tmp = zx * zx - zy * zy + cx;
                zy = 2.0 * zx * zy + cy;
                zx = tmp;
                i++;
            }
            if (i == ACRAC)
                i = 0;
            int color = i * 10000;
            my_mlx_pixel_put(img, x, y, color);
        }
    }
    mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}