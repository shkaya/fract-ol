#include "fractol.h"

// ジュリア集合を作る関数
void	draw_julia(t_data *data, double c_re, double c_im)
{
    double z_re, z_im, z_re2, z_im2;
    int iter;
    int color;

	for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            /* 
            	画面を複素平面とみなし、各点を集合の初項とし,
            	複素数cは固定したまま反復計算して発散するかどうか調べる。
            */
            // 実験結果: scaleを小さくすれば座標が拡大される。　直感的にはわからん。
			z_re = data->scale * (x - WIDTH / 2.0) * (4.0 / WIDTH) + data->offset_x;
            z_im = data->scale * (y - HEIGHT / 2.0) * (4.0 / HEIGHT) + data->offset_y;
            iter = 0;
            while (iter < MAX_ITER)
            {
                z_re2 = z_re * z_re;
                z_im2 = z_im * z_im;
                if (z_re2 + z_im2 > 4.0)
                	break;
                z_im = 2.0 * z_re * z_im + c_im;
                z_re = z_re2 - z_im2 + c_re;
                iter++;
            }
        	color = get_color(iter, MAX_ITER);
        	put_pixel_to_image(data, x, y, color);
        }
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return;
}
