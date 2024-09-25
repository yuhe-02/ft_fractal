#include "ft_fractal.h"

int calc_color2(t_coord *cd, int color_flg) 
{
    double ratio;
    int red;
    int green;
    int blue;
    // double distance = sqrt(pow(cd->cx - cd->zx, 2) + pow(cd->cy - cd->zy, 2)) * color_flg;  // 距離の計算
    // int r = (int)(255 * fmod(distance, 1.0));  // 1.0未満の小数部分で変化
    // int g = (int)(255 * fmod(distance * 0.7, 1.0));  // 少し違う割合で変化
    // int b = (int)(255 * fmod(distance * 0.4, 1.0));  // 別の割合で変化
    // return (r << 16) | (g << 8) | b;

    ratio = ((double)cd->iterations / MAX_ITER) * (double)color_flg;
    red = (int)(9 * (1 - ratio) * ratio * ratio * ratio * 255);  // 色のグラデーション (赤)
    green = (int)(15 * (1 - ratio) * (1 - ratio) * ratio * ratio * 255);  // 色のグラデーション (緑)
    blue = (int)(8.5 * (1 - ratio) * (1 - ratio) * (1 - ratio) * ratio * 255);  // 色のグラデーション (青)
    return (red << 16) | (green << 8) | blue;  // RGB値の設定
    
}