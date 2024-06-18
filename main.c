#include "fractol.h"
#include <stdio.h>

int	handle_key(int keycode, t_data *data)
{
	printf("key pass: %d\n", keycode);
    // ESCキーで終了
    if (keycode == KEY_ESC)
	{
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    if (keycode == KEY_PLUS)
    	data->scale /= 1.1;
    if (keycode == KEY_MINUS)
    	data->scale *= 1.1;
	// "* scale"によってそのスケールに適した動きになる。
    if (keycode == KEY_LEFT)
    	data->offset_x -= 0.1 * data->scale;
    if (keycode == KEY_RIHGT)
    	data->offset_x += 0.1 * data->scale;
    if (keycode == KEY_UP)
    	data->offset_y -= 0.1 * data->scale;
    if (keycode == KEY_DOWN)
    	data->offset_y += 0.1 * data->scale;
	draw_julia(data, -0.7, 0.27015);
    return (0);
}

int main(void)
{
	// // マンデルブロ集合
	// t_data	data;
    // init_mlx(&data);
    // draw_mandelbrot(&data);

	// ジュリア集合
    t_data	data;
	init_mlx(&data);
    draw_julia(&data, -0.7, 0.27015);

	// キーボードイベントハンドラを設定
	mlx_key_hook(data.win_ptr, handle_key, &data);
	mlx_loop(data.mlx_ptr);
    return (0);
}
