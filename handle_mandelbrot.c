#include "fractol.h"

// キーイベントの処理を扱う関数
int	handle_key_mandelbrot(int keycode, t_data *data)
{
	printf("key pass: %d\n", keycode);
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
    if (keycode == KEY_RIGHT)
    	data->offset_x += 0.1 * data->scale;
    if (keycode == KEY_UP)
    	data->offset_y -= 0.1 * data->scale;
    if (keycode == KEY_DOWN)
    	data->offset_y += 0.1 * data->scale;
	draw_mandelbrot(data);
	return (0);
}

// マウスイベントの処理を扱う関数
int	handle_mouse_mandelbrot(int button, int x, int y, t_data *data)
{
	printf("button: %d (%d,%d)\n", button, x, y);
	if (x < WIDTH && y < HEIGHT)
	{
		if (button == MOUSE_SCROLL_UP)
			data->scale /= 1.1;
		if (button == MOUSE_SCROLL_DOWN)
			data->scale *= 1.1;
		draw_julia(data, data->c_re, data->c_im);
	}
	draw_mandelbrot(data);
	return (0);
}
