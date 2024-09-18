#include "ft_fractal.h"

// ニュートン法での計算
double complex newton_method(double complex z) 
{
    double complex f = cpow(z, 5) + 1;
    double complex df = 5 * cpow(z, 4);
    if (creal(df) != 0 || cimag(df) != 0) {
        return z - f / df;
    } else {
        return 0;
    }
}

// 関数の根を収束するまで計算する
double complex root_of_func(double complex z, int *iterations) 
{
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
    *iterations = counter; // 反復回数を返す
    return z_new;
}

// 距離に基づいて色を計算する関数
int calc_color_by_distance(double cx, double cy, double px, double py) 
{
    double distance = sqrt(pow(cx - px, 2) + pow(cy - py, 2));  // 距離の計算
    int r = (int)(255 * fmod(distance, 1.0));  // 1.0未満の小数部分で変化
    int g = (int)(255 * fmod(distance * 0.7, 1.0));  // 少し違う割合で変化
    int b = (int)(255 * fmod(distance * 0.4, 1.0));  // 別の割合で変化
    return (r << 16) | (g << 8) | b;
}

// ニュートン法で計算し、座標に基づいて色を決定する
t_coord *calc_newton5_set(t_data *img, int x, int y) 
{
    t_coord *cd;
    int iterations;

    cd = (t_coord *)malloc(sizeof(t_coord));
    if (!cd)
        exit(1);

    // 座標を計算
	// printf("%f %f %f %f\n", img->param1, img->param2, img->param3, img->param4);
    // double real = (img->param1 + (img->param2 - img->param1) * x / WIDTH - img->offsetX) / img->zoom;
    // double im = (img->param3 + (img->param4 - img->param3) * y / HEIGHT - img->offsetY) / img->zoom;
    double real = (x - WIDTH / 2.0) * (FRACTAL_RANGE / WIDTH) / img->zoom + img->offsetX;
    double im = (y - HEIGHT / 2.0) * (FRACTAL_RANGE / HEIGHT) / img->zoom + img->offsetY;
    double complex z = real + im * I;

    // 根を計算
    double complex root = root_of_func(z, &iterations);

    // 座標をそれぞれcx, cy, px, pyに格納
    cd->cx = creal(z);  // zの実部
    cd->cy = cimag(z);  // zの虚部
    cd->zx = creal(root);  // rootの実部
    cd->zy = cimag(root);  // rootの虚部
    return cd;
}
