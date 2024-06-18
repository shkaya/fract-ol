#include "fractol.h"

int	handle_key(int keycode, t_data *data)
{
    // ESCキーで終了
    if (keycode == 65307)
	{
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    return (0);
}

int main(void)
{
	// マンデルブロ集合
	// t_data	data;
    // init_mlx(&data);
    // draw_mandelbrot(&data);
    // mlx_loop(data.mlx_ptr);

	// ジュリア集合
    t_data	data;
	init_mlx(&data);
    draw_julia(&data, -0.7, 0.27015);
	// キーボードイベントハンドラを設定
	mlx_key_hook(data.win_ptr, handle_key, &data);
	mlx_loop(data.mlx_ptr);
    return (0);
}
