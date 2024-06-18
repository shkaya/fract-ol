#include "fractol.h"

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
	data->scale = 1.0;
    data->offset_x = 0.0;
    data->offset_y = 0.0;
}
