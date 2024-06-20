#include "fractol.h"

// バーニングシップフラクタルを作る関数。
void	draw_burning_ship(t_data *data)
{
	int	iter;
	double	c_re, c_im, z_re, z_im, z_re2, z_im2;
	int	color;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			c_re = data->scale * (x - WIDTH / 2.0) * (4.0 / WIDTH) + data->offset_x;
			c_im = data->scale * (y - HEIGHT / 2.0) * (4.0 / WIDTH) + data->offset_y;
			z_re = c_re;
			z_im = c_im;
			iter = 0;
			while (iter < MAX_ITER)
			{
				z_re2 = z_re * z_re;
				z_im2 = z_im * z_im;
				if (z_re2 + z_im2 > 4.0)
					break;
				// fabs() ... 絶対値を取ってくれる関数
				z_re = fabs(z_re);
				z_im = fabs(z_im);
				z_im =	2 * z_re * z_im + c_im;
				z_re = z_re2 - z_im2 + c_re;
				iter++;
			}
			color = get_color(data, iter, MAX_ITER);
			put_pixel_to_image(data, x, y, color);
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return ;
}
