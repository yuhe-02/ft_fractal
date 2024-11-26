#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
# include "mlx.h"

#define KEY_ESC 65307

typedef struct s_param
{
    void *mlx;
    void *win;
    int color_flg;
    int offset_x;
    int offset_y;
} t_param;

// キーイベントが発生したときに呼ばれるコールバック関数
int key_hook(int keycode, t_param *param)
{
    printf("Keycode: %d\n", keycode);  // 押されたキーのキーコードを表示

    if (keycode == KEY_ESC)
    {
        // ESCキーが押された場合、終了
        printf("Exit key pressed\n");
        exit(0);
    }

    // 他のキーが押された場合の処理
    // ここに追加の処理を記述できます

    return (0);
}

int main(void)
{
    t_param param;

    param.mlx = mlx_init();
    param.win = mlx_new_window(param.mlx, 800, 600, "Keycode Display");

    // キーイベントを処理するフックを設定
    mlx_key_hook(param.win, key_hook, &param);

    mlx_loop(param.mlx);  // イベントループを開始

    return 0;
}
