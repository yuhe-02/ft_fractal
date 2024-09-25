# フラクタル図形の描画

## 概要
このプロジェクトでは、C言語を利用してフラクタル図形の描画を行いました。
描画できる図形は、マンデルブロ集合、ジュリア集合、ニュートン法です。


## 導入
### インストール

```bash
git clone https://github.com/yuhe-02/ft_fractal.git
cd ft_fractal
tar -xvpf minilibx-linux.tgz
cd minilibx-linux && make && make clean
cd ..
make all && make clean
./ft_fractal mandelbrot -0.63 -0.3
```

### requirement
```requirement
apt-get -y install build-essential gcc make &&
apt-get install libxext-dev -y &&
apt-get install libbsd-dev -y &&
apt-get install -y libreadline-dev
```

## 課題

### 残課題

1. **引数バリデーション**
#### 完了
2. **エラーメッセージ**
#### 適切なメッセージを作成する
3. **norminette**
4. **mandelbrotのパラメータ**


### レポジトリにおける課題

1. **環境の連携をDockerfileにする**
2. **READMEを埋める**
3. **設計の解説とかする**
