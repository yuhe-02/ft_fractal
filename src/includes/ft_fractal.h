/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:49:48 by yyamasak          #+#    #+#             */
/*   Updated: 2024/09/29 14:37:31 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTAL_H
# define FT_FRACTAL_H

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>
// # include <complex.h>

typedef enum e_keys
{
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_C = 99,
	KEY_B = 98
}	t_keys;

typedef enum e_mouses
{
	MOUSE_LEFT_CLICK = 1,
	MOUSE_WHEEL_UP = 4,
	MOUSE_WHEEL_DOWN = 5
}	t_mouses;

typedef enum e_shapes
{
	JULIA = 0,
	MANDELBROT = 1,
	BONUS = 2
}	t_shapes;

# define JULIA_S "julia"
# define MD_S "mandelbrot"
# define BONUS_S "bonus"
# define WIDTH 400
# define HEIGHT 400
# define ACRAC 1000
# define FT_TRUE 1
# define FT_FALSE 0
# define ZOOM_MAG 1.2
# define MOVE_MAG 0.05
# define F_RAN 2.0
# define DEPTH 20
# define MAX_ITER 300
# define EPS 1e-10
# define WINDOW_CLOSE 17
# define SENTENCE1 "Below is sample valid parameters.\n"
# define SENTENCE2 "./ft_fractal julia -0.3 -0.63\n"
# define SENTENCE3 "./ft_fractal mandelbrot 0 0\n"
# define SENTENCE4 "./ft_fractal bonus 3 -2\n"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		eda;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		set_type;
	double	param1;
	double	param2;
	int		color_flg;
}			t_data;

typedef struct s_coord
{
	double	cx;
	double	cy;
	double	zx;
	double	zy;
	int		iterations;
}			t_coord;

typedef struct s_complex 
{
	double	real;
	double	imag;
}			t_complex;

typedef t_coord	*(*t_fractal_func)(t_data *, int, int);
typedef int		(*t_calc_color)(t_coord *, int);

void		init_images(t_data *img, int argc, char **argv);
int			key_hook(int keycode, void *param);
int			mouse_hook(int button, int x, int y, void *param);
void		choose_fractal(t_data *img);
t_coord		*calc_mandelbrot_set(t_data *img, int x, int y);
t_coord		*calc_julia_set(t_data *img, int x, int y);
int			close_window(t_data *data);
void		put_mlx_pixel(t_data *data, int x, int y, int color);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
double		ft_atob(const char *str);
char		*ft_strchr(const char *s, int c);
int			ft_strlen(char *str);
char		*ft_strrchr(const char *s, int c);
int			ft_is_num(int c);
int			ft_isspace(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy(char *dest, char const *src, size_t n);
char		*ft_delete_space(const char *str);
int			ft_is_valid_num(const char *str);
t_coord		*calc_newton5_set(t_data *img, int x, int y);
int			calc_color2(t_coord *cd, int color_flg);
int			calc_color1(t_coord *cd, int color_flg);
void		set_error(char *message, int is_put_sample, int exit_no);
void		put_mlx_pixel(t_data *data, int x, int y, int color);
t_complex	ft_cpow(t_complex z, double power);
double	ft_cabs(t_complex z1);
t_complex	ft_complex_diff(t_complex z1, t_complex z2);
t_complex	ft_complex_add(t_complex z1, t_complex z2);
t_complex	ft_complex_div(t_complex z1, t_complex z2);
t_complex	ft_complex_mul(t_complex z1, t_complex z2);
t_complex	ft_complex_mul_st(t_complex z1, double st_value);
#endif