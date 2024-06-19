#include "fractol.h"

/*  mlx系関数の引数を間違えて渡すと大体segvが起きます　*/

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

// イベントハンドリングを関数化
void	setup_hooks(t_data *data)
{
	if (data->what_fractal == 2)
	{
		// キーボードイベントハンドラを設定
		mlx_key_hook(data->win_ptr, handle_key_julia, data);
		// マウスイベントハンドラを設定
		mlx_mouse_hook(data->win_ptr, handle_mouse_julia, data);
	}
	else if (data->what_fractal == 1)
	{
		mlx_key_hook(data->win_ptr, handle_key_mandelbrot, data);
		mlx_mouse_hook(data->win_ptr, handle_mouse_mandelbrot, data);
	}
	// ウィンドウの×ボタンイベントハンドラを設定
	// '17': 'DestroyNotify' ウィンドウが閉じられた時のイベント。監視対象のだった時に検証される。
	// '1L<<17': 'StructureNotifyMask' ウィンドウの構造に関連するイベント(閉じる、サイズ変更など)を監視。
	mlx_hook(data->win_ptr, 17, 1L<<17, handle_close, data);
	return;
}

// 受け取った文字列がどのフラクタルか判断する関数。
// error -> -1, mandelbrot -> 1, fractol -> 2
static int	decide_fractol(int argc, char **argv, t_data *data)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		draw_mandelbrot (data);
		return (1);
	}
	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
	{
		data->c_re = my_atof(argv[2]);
		data->c_im = my_atof(argv[3]);
		draw_julia(data, data->c_re, data->c_im);
		return (2);
	}
	else
	{
		ft_putstr_fd("Error:\n", 1);
		return (-1);
	}
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	init_mlx(&data);
	data.what_fractal = decide_fractol(argc, argv, &data);
	if (data.what_fractal == -1)
		exit(EXIT_FAILURE);
	setup_hooks(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
