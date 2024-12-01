/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyamasak <yyamasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 23:49:48 by yyamasak          #+#    #+#             */
/*   Updated: 2024/12/01 15:02:40 by yyamasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "mlx.h"
# include <stdlib.h>
# include <X11/X.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>
# include <stdint.h>

typedef enum e_keys
{
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_SHIFT = 65505,
	KEY_SPACE = 32,
	KEY_ENTER = 65293
}	t_keys;

typedef enum e_mouses
{
	MOUSE_LEFT_CLICK = 1,
	MOUSE_WHEEL_UP = 4,
	MOUSE_WHEEL_DOWN = 5
}	t_mouses;

# define JULIA_S "julia"
# define MD_S "mandelbrot"
# define BONUS_S "newton"
# define WIDTH 800
# define HEIGHT 800
# define FT_TRUE 1
# define FT_FALSE 0
# define ZOOM_MAG 1.2
# define MOVE_MAG 0.05
# define MAX_ITER 100
# define EPS 1e-10
# define WINDOW_CLOSE 17
# define SENTENCE1 "Below is sample valid parameters.\n"
# define SENTENCE2 "./ft_fractol julia -0.3 -0.63\n"
# define SENTENCE3 "./ft_fractol mandelbrot 0 0\n"
# define SENTENCE4 "./ft_fractol newton 3 -2\n"

typedef struct s_param	t_param;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		eda;
	int		width;
	int		height;
}			t_data;

typedef struct s_param
{
	void				*mlx;
	void				*win;
	t_data				data;
	double				min_re;
	double				min_im;
	double				max_re;
	double				max_im;
	int					max_iter;
	double				z_re;
	double				z_im;
	double				c_re;
	double				c_im;
	int					iteration;
	double				delta_re;
	double				delta_im;
	double				param1;
	double				param2;
	double				zoom;
	int					space_flg;
	t_param				*(*calculator)(t_param*, int, int);
	int					(*calc_color)(t_param*, int);
}			t_param;

typedef struct s_complex
{
	double	real;
	double	imag;
}			t_complex;

// minilibx
int			ft_is_valid_num(const char *str);
int			validate_params(char **argv, int param_num, int start_index);
int			check_params(int ac, char **av);
void		init_images(t_param *img);
void		initialize_param(t_param *param);
int			set_shape_param(t_param *param, char **argv);
void		set_error(char *message, int is_put_sample, int exit_no);
void		display_errorlog(char *message, int is_put_sample);
int			key_hook(int keycode, void *param);
int			mouse_hook(int button, int x, int y, void *param);
void		draw_fractol(t_param *img);
void		put_mlx_pixel(t_param *data, int x, int y, int color);
// void		update_fractol_c(t_param *param);
int			close_window(t_param *data);

// calc colors
t_param		*calc_mandelbrot_set(t_param *img, int x, int y);
t_param		*calc_julia_set(t_param *img, int x, int y);
t_param		*calc_newton5_set(t_param *img, int x, int y);
int			calc_color2(t_param *cd, int color_flg);
int			calc_color1(t_param *cd, int color_flg);
uint32_t	rgb2hex(int r, int g, int b);
uint32_t	hsv2hex(double h, double s, double v);
int			get_colors(int iteration, int max_iter, int color_flg);
void		draw_fractol(t_param *param);

// util
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
double		abs_double(double val);

// math
t_complex	ft_cpow(t_complex z, double power);
double		ft_cabs(t_complex z1);
t_complex	ft_complex_diff(t_complex z1, t_complex z2);
t_complex	ft_complex_add(t_complex z1, t_complex z2);
t_complex	ft_complex_div(t_complex z1, t_complex z2);
t_complex	ft_complex_mul(t_complex z1, t_complex z2);
t_complex	ft_complex_mul_st(t_complex z1, double st_value);
#endif