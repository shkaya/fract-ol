
#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 600
# define	MAX_ITER 100

typedef struct s_data
{
    void	*mlx_ptr;
	void	*win_ptr;
    void	*img_ptr;
    char 	*addr;
	int		bpp;
    int		size_line;
    int		endian;
}				t_data;

// mlx,window,imgを作成する関数
void	init_mlx(t_data *data);
void	put_pixel_to_image(t_data *data, int x, int y, int color);
int	get_color(int iter, int max);


// マンデルブロ集合を作る関数
void	draw_mandelbrot(t_data *data);


#endif