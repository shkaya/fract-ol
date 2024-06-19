
#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH		800
# define HEIGHT		600
# define MAX_ITER	100

// 環境によってkeyに割り当てられている数字が異なる。
# define KEY_ESC	65307
# define KEY_PLUS	61
# define KEY_MINUS	45
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_UP		65362
# define KEY_DOWN	65364
# define MOUSE_SCROLL_UP	5
# define MOUSE_SCROLL_DOWN	4

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	double	scale;
	double	offset_x;
	double	offset_y;
	double	c_re;
	double	c_im;
	int		what_fractal;
}				t_data;

// mlx,window,imgを作成する関数
void	init_mlx(t_data *data);

// 文字列をdouble型の数値に変換する(atof)
double	my_atof(const char *str);

// マンデルブロ集合を作る関数
void	put_pixel_to_image(t_data *data, int x, int y, int color);
int		get_color(int iter, int max);
void	draw_mandelbrot(t_data *data);

// ジュリア集合に関する関数
void	draw_julia(t_data *data, double c_re, double c_im);
int		handle_key_julia(int keycode, t_data *data);
int		handle_mouse_julia(int button, int x, int y, t_data *data);

// 各イベントに対する処理をする関数
int		handle_close(t_data *data);

// ヘルパー関数
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(const char *s1, const char *s2);

#endif