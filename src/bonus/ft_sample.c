#include <math.h>
#include "ft_fractal.h"

static void clear_image(t_data *img) {
    int total_pixels = WIDTH * HEIGHT * (img->bits_per_pixel / 8);
    ft_memset(img->addr, 0, total_pixels); // メモリ全体をゼロでクリア
}

void    draw_line(t_data *img, int x1, int y1, int x2, int y2, int color) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (1) 
    {
        if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT)
            put_mlx_pixel(img, x1, y1, color);
        if (x1 == x2 && y1 == y2) 
            break;
        int e2 = err * 2;
        if (e2 > -dy) 
        { 
            err -= dy; 
            x1 += sx; 
        }
        if (e2 < dx) 
        { 
            err += dx; 
            y1 += sy; 
        }
    }
}

void    generate_ccurve(t_data *img, int x1, int y1, int x2, int y2, int depth) 
{
    x1 = (x1 - WIDTH / 2) * img->zoom + WIDTH / 2;
    y1 = (y1 - HEIGHT / 2) * img->zoom + HEIGHT / 2;
    x2 = (x2 - WIDTH / 2) * img->zoom + WIDTH / 2;
    y2 = (y2 - HEIGHT / 2) * img->zoom + HEIGHT / 2;
    if (depth == 0) 
    {
        draw_line(img, x1, y1, x2, y2, 0xFFFFFF);
    } else {
        int mx = (x1 + x2) / 2;
        int my = (y1 + y2) / 2;

        int nx1 = (x1 + mx) / 2 - (y1 - my) / 2;
        int ny1 = (y1 + my) / 2 + (x1 - mx) / 2;
        int nx2 = (x2 + mx) / 2 - (y2 - my) / 2;
        int ny2 = (y2 + my) / 2 + (x2 - mx) / 2;

        generate_ccurve(img, x1, y1, nx1, ny1, depth - 1);
        generate_ccurve(img, nx1, ny1, nx2, ny2, depth - 1);
        generate_ccurve(img, nx2, ny2, x2, y2, depth - 1);
    }
}

void draw_fractal_re(t_data *img, t_coord *(*func)(t_data *, int, int)) 
{
    int x1 = (50 - WIDTH / 2.0) * img->zoom + WIDTH / 2.0 + img->offsetX;
    int y1 = (200 - HEIGHT / 2.0) * img->zoom + HEIGHT / 2.0 + img->offsetY;
    int x2 = (350 - WIDTH / 2.0) * img->zoom + WIDTH / 2.0 + img->offsetX;
    int y2 = (200 - HEIGHT / 2.0) * img->zoom + HEIGHT / 2.0 + img->offsetY;

    printf("x1=%f y1=%f \n", img->offsetX, img->offsetY);
    printf("x1=%d y1=%d x2=%d y2=%d\n", x1, y1, x2, y2);
    // クリア処理が不要なら削除
    clear_image(img);  
    
    // フラクタルを描画
    generate_ccurve(img, x1, y1, x2, y2, 17);

    // ウィンドウに描画
    mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
}
