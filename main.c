#include "src/fractol.h"

/*  mlx系関数の引数を間違えて渡すと大体segvが起きます　*/

// イベントハンドリングを関数化
void	setup_hooks(t_data *data)
{
	mlx_key_hook(data->win_ptr, handle_key, data);
	mlx_mouse_hook(data->win_ptr, handle_mouse, data);
	// ウィンドウの×ボタンイベントハンドラを設定
	// '17': 'DestroyNotify' ウィンドウが閉じられた時のイベント。監視対象のだった時に検証される。
	// '1L<<17': 'StructureNotifyMask' ウィンドウの構造に関連するイベント(閉じる、サイズ変更など)を監視。
	mlx_hook(data->win_ptr, 17, 1L<<17, handle_close, data);
	return;
}

static int	is_num(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || '9' < *str)
			return (0);
		str++;
	}
	return (1);
}

// 受け取った文字列がどのフラクタルか判断する関数。改
static int	decide_fractol(int argc, char **argv, t_data *data)
{
	// [正規表現]　./fractol mandelbrot
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && argc == 2)
	{
		return (1);
	}
	// [正規表現] ./fractol julia <数値> <数値>
	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4 && is_num(argv[2]) && is_num(argv[3]))
	{
		data->c_re = my_atof(argv[2]);
		data->c_im = my_atof(argv[3]);
		return (2);
	}
	else
	{
		ft_putstr_fd("[Valid] ./fractol mandelbrot\n", 1);
		ft_putstr_fd("        ./fractol julia <num> <num>\n", 1);
		free(data->name);
		return (-1);
	}
}

// 受け取った文字列がどのフラクタルか判断する関数。
// error -> -1, mandelbrot -> 1, julia -> 2, burningship -> 3
// static int	decide_fractol(int argc, char **argv, t_data *data)
// {
// 	if (ft_strcmp(argv[1], "mandelbrot") == 0)
// 	{
// 		draw_mandelbrot (data);
// 		return (1);
// 	}
// 	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
// 	{
// 		data->c_re = my_atof(argv[2]);
// 		data->c_im = my_atof(argv[3]);
// 		draw_julia(data, data->c_re, data->c_im);
// 		return (2);
// 	}
// 	else if (ft_strcmp(argv[1], "burningship") == 0)
// 	{
// 		draw_burning_ship(data);
// 		return (3);
// 	}
// 	else
// 	{
// 		ft_putstr_fd("Error:\n", 1);
// 		return (-1);
// 	}
// }

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", 1);
		exit(EXIT_FAILURE);
	}
	data.name = ft_strdup(argv[1]);
	if (!data.name)
		exit(EXIT_FAILURE);
	data.what_fractal = decide_fractol(argc, argv, &data);
	if (data.what_fractal == -1)
		exit(EXIT_FAILURE);
	init_mlx(&data);
	draw_fractal(&data);
	//data.what_fractal = decide_fractol(argc, argv, &data);
	// ウィンドウが再表示された時に再描画する関数. "expose" = 現れる？
	mlx_expose_hook(data.win_ptr, draw_fractal, &data);
	setup_hooks(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
