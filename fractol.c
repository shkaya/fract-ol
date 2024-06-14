#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

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

// MiniLibXの初期化とwindowの作成を行う関数
// 出力処理はしない。mlx,window,imgを作り、addrを取得するだけ
void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init(); // コンテキストの取得。
    if (!data->mlx_ptr)
    {
        fprintf(stderr, "Error: Failed to obtain context\n");
    	exit(EXIT_FAILURE);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fractol");
    if (!data->win_ptr)
    {
        fprintf(stderr, "Error: Failed to create window\n");
        exit(EXIT_FAILURE);
    }
    data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->size_line, &data->endian);
}

// マンデルブロ集合を描画する関数
void	draw_mandelbrot()
{
}

int main(void)
{
	t_data	data;
    init_mlx(&data);
    mlx_loop(data.mlx_ptr);
    return (0);
}