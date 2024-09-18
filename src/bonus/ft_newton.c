#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>

#define WIDTH 400
#define HEIGHT 400
#define MAX_ITER 100
#define EPS 1e-10

typedef struct {
    void    *mlx;
    void    *win;
    void    *img;
    char    *data;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_data;

typedef struct {
    double  real_min;
    double  real_max;
    double  im_min;
    double  im_max;
} t_range;

// ニュートン法で方程式の根を求める関数
double complex newton_method(double complex z) {
    double complex f = cpow(z, 5) + 1;
    double complex df = 5 * cpow(z, 4);
    if (creal(df) != 0 || cimag(df) != 0) {
        return z - f / df;
    } else {
        return 0;
    }
}

// 関数の根を収束するまで計算する
double complex root_of_func(double complex z) {
    int counter = 0;
    double complex z_new;
    while (1) {
        z_new = newton_method(z);
        double eps = cabs(z_new - z);
        if (eps < EPS) {
            break;
        }
        if (counter == MAX_ITER) {
            break;
        }
        z = z_new;
        counter++;
    }
    return z_new;
}

// カラー値を計算する関数
int get_color(double angle) {
    int r, g, b;
    angle = fmod(angle, 360.0);
    angle /= 360.0;
    r = (int)(255 * (angle < 0.5 ? 2 * angle : 2 * (1 - angle)));
    g = (int)(255 * (angle < 0.5 ? 2 * (angle - 0.5) : 2 * (1 - angle) + 0.5));
    b = (int)(255 * (angle < 0.5 ? 1.0 : 2.0 - angle));
    return (r << 16) | (g << 8) | b;
}

void	put_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// メイン描画関数
void draw_fractal(t_data *data, t_range *range) {
    int x, y;
    for (x = 0; x < WIDTH; x++) {
        for (y = 0; y < HEIGHT; y++) {
            double real = range->real_min + (range->real_max - range->real_min) * x / WIDTH;
            double im = range->im_min + (range->im_max - range->im_min) * y / HEIGHT;
            double complex z = real + im * I;
            double complex root = root_of_func(z);
            double angle = atan2(cimag(root), creal(root)) * 180 / M_PI;
            if (angle < 0) angle += 360;
            int color = get_color(angle);
			put_mlx_pixel(data, x, y, color);

        }
    }
}

int main() {
    t_data data;
    t_range range = {-1, 1, -1, 1};
    
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractal");
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    data.data = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    
    draw_fractal(&data, &range);
    mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
    mlx_loop(data.mlx);
    
    return 0;
}
