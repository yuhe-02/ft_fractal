// #include <mlx.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <complex.h>

// #define WIDTH 400
// #define HEIGHT 400
// #define MAX_ITER 100
// #define EPS 1e-7

// typedef struct s_data {
//     void *mlx_ptr;
//     void *win_ptr;
//     unsigned char *img_data;
//     int bpp;
//     int size_line;
//     int endian;
// } t_data;

// // 多項式の定義
// double complex f(double complex z) {
//     return cpow(z, 3) - 1; // z^3 - 1
// }

// // 導関数の定義
// double complex df(double complex z) {
//     return 3 * cpow(z, 2); // 3z^2
// }

// // ニュートン法
// double complex newton_method(double complex z) {
//     for (int i = 0; i < MAX_ITER; i++) {
//         double complex f_z = f(z);
//         double complex df_z = df(z);

//         if (cabs(df_z) < EPS) {
//             return z; // 導関数がゼロに近い場合
//         }

//         z -= f_z / df_z; // ニュートン法の更新

//         if (cabs(f_z) < EPS) {
//             return z; // 収束した場合
//         }
//     }
//     return z; // 最大反復回数に達した場合
// }

// // 色の設定
// int get_color(double complex root) {
//     if (cabs(root) < 1e-7) return 0xFF0000; // 赤
//     if (cabs(root - 1) < 1e-7) return 0x00FF00; // 緑
//     if (cabs(root + 0.5 + 0.86602540378 * I) < 1e-7) return 0x0000FF; // 青
//     return 0xFFFFFF; // 白
// }

// // フラクタルの計算
// void calculate_fractal(t_data *data) {
//     for (int x = 0; x < WIDTH; x++) {
//         for (int y = 0; y < HEIGHT; y++) {
//             double complex z = ((double)x / WIDTH) * 4.0 - 2.0 + (((double)y / HEIGHT) * 4.0 - 2.0) * I;
//             double complex root = newton_method(z);

//             // 色を決定
//             int color = get_color(root);
//             int pixel_index = (y * WIDTH + x) * 4; // 4はRGBAのサイズ

//             // RGBAの色を設定
//             data->img_data[pixel_index + 0] = (color >> 16) & 0xFF; // R
//             data->img_data[pixel_index + 1] = (color >> 8) & 0xFF;  // G
//             data->img_data[pixel_index + 2] = color & 0xFF;         // B
//             data->img_data[pixel_index + 3] = 255;                   // A
//         }
//     }
// }

// // メイン関数
// int main() {
//     t_data data;

//     // Minilibxの初期化
//     data.mlx_ptr = mlx_init();
//     data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Generalized Newton Fractal");
//     data.img_data = (unsigned char *)malloc(WIDTH * HEIGHT * 4); // RGBA用にメモリを確保

//     // フラクタルを計算
//     calculate_fractal(&data);

//     // 画像を描画
//     void *img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
//     unsigned char *img_data = mlx_get_data_addr(img_ptr, &data.bpp, &data.size_line, &data.endian);
    
//     for (int y = 0; y < HEIGHT; y++) {
//         for (int x = 0; x < WIDTH; x++) {
//             int pixel_index = (y * WIDTH + x) * 4;
//             img_data[pixel_index + 0] = data.img_data[pixel_index + 0]; // R
//             img_data[pixel_index + 1] = data.img_data[pixel_index + 1]; // G
//             img_data[pixel_index + 2] = data.img_data[pixel_index + 2]; // B
//             img_data[pixel_index + 3] = data.img_data[pixel_index + 3]; // A
//         }
//     }

//     // 画像をウィンドウに描画
//     mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img_ptr, 0, 0);

//     // イベントループを開始
//     mlx_loop(data.mlx_ptr);

//     // メモリの解放
//     free(data.img_data);
//     mlx_destroy_image(data.mlx_ptr, img_ptr);
//     mlx_destroy_window(data.mlx_ptr, data.win_ptr);
    
//     return 0;
// }
