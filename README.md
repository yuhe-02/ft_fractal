# フラクタル図形の描画

## 概要
このプロジェクトでは、C言語を利用してフラクタル図形の描画を行いました。
描画できる図形は、マンデルブロ集合、ジュリア集合、ニュートン法です。


## 導入
### インストール

```bash
git clone https://github.com/yuhe-02/ft_fractol.git
cd ft_fractol
tar -xvpf minilibx-linux.tgz
cd minilibx-linux && make && make clean
cd ..
make all && make clean
./ft_fractol mandelbrot -0.63 -0.3
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
	- 状態: ✅ 完了
2. **エラーメッセージ**
	- 状態: ✅ 完了
3. **norminette**
	- 状態: ✅ 完了
4. **mandelbrotのパラメータ**
	- 状態: ✅ 完了
5. **メモリリーク**
	- 状態: ✅ 完了
	- 課題：t_data型周りでのリークがある（解決可能？）
6. **解説周り**
	- 状態: 🔄 実施中
	- 課題：図形描画の計算部分、複素数の計算
	

### レポジトリにおける課題

1. **環境の連携をDockerfileにする**
	- 状態: 🔄 着手前
	- 課題１：必要なライブラリ、依存関係のインストール
	- 課題２：このレポジトリをcp
	- 課題３：今回課題だった、X11周りをどう解決するか（ホストOS側の問題）
2. **READMEを埋める**
	- 課題１：使い方の部分
3. **設計の解説とかする**
