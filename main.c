#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	char	*p;

	i = 0;
	if (s == (char *)0)
		return ;
	p = s;
	while (*s++)
		i++;
	write(fd, p, i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// イベントハンドリングを関数化
void	setup_hooks(t_data *data)
{
	// キーボードイベントハンドラを設定
	mlx_key_hook(data->win_ptr, handle_key, data);
	// マウスイベントハンドラを設定
	mlx_mouse_hook(data->win_ptr, handle_mouse, data);
	// ウィンドウの×ボタンイベントハンドラを設定
	// '17': 'DestroyNotify' ウィンドウが閉じられた時のイベント。監視対象のだった時に検証される。
	// '1L<<17': 'StructureNotifyMask' ウィンドウの構造に関連するイベント(閉じる、サイズ変更など)を監視。
	mlx_hook(data->win_ptr, 17, 1L<<17, handle_close, data);
}

#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
	{
		ft_putstr_fd("Error", 1);
		exit(EXIT_FAILURE);
	}
	init_mlx(&data);
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		draw_mandelbrot (&data);
	else if (ft_strcmp(argv[1], "julia") == 0 && argc == 4)
	{
		data.c_re = my_atof(argv[2]);
		data.c_im = my_atof(argv[3]);
		draw_julia(&data, data.c_re, data.c_im);
	}
	else
	{
		ft_putstr_fd("Error", 1);
		exit(EXIT_FAILURE);
	}
	setup_hooks(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
