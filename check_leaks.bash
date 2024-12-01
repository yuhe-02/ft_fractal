make re
make clean

(sleep 15 && xdotool search --name bonus windowclose) &
# プログラムをバックグラウンドで実行
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --sim-hints=lax-ioctls ./fractol mandelbrot 0 0
