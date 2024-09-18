#include "ft_fractal.h"

int calc_color2(t_coord *cd, int color_flg) 
{
    double distance = sqrt(pow(cd->cx - cd->zx, 2) + pow(cd->cy - cd->zy, 2));  // 距離の計算
    int r = (int)(255 * fmod(distance, 1.0));  // 1.0未満の小数部分で変化
    int g = (int)(255 * fmod(distance * 0.7, 1.0));  // 少し違う割合で変化
    int b = (int)(255 * fmod(distance * 0.4, 1.0));  // 別の割合で変化
    return (r << 16) | (g << 8) | b;
}