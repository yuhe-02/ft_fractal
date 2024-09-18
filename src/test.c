#include <X11/Xlib.h>
#include <stdio.h>

int main() {
    Display *display;
    KeyCode keycode_C, keycode_B;
    KeySym keysym_C, keysym_B;

    // ディスプレイを開く
    display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Unable to open X display\n");
        return 1;
    }

    // キーシンボルをキーコードに変換
    keysym_C = XStringToKeysym("C");
    keysym_B = XStringToKeysym("B");

    keycode_C = XKeysymToKeycode(display, keysym_C);
    keycode_B = XKeysymToKeycode(display, keysym_B);

    // キーコードを表示
    printf("Keycode for 'C': %d\n", keycode_C);
    printf("Keycode for 'B': %d\n", keycode_B);

    // ディスプレイを閉じる
    XCloseDisplay(display);
    return 0;
}
