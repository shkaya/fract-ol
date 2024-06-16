#include "fractol.h"

// マンデルブロ集合を描画する関数
void	draw_mandelbrot(t_data *data)
{
    int	iter;
    double	(c_re), (c_im), (z_re), (z_im), (z_re2), z_im2;
    int color;

	for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            /*
            	マンデルブロ集合の図を作成するにあたって座標を作り、
        		各点を調べる必要がある。
            */
            // 画面の各ピクセルを -2.0 ~ 2.0 の範囲の座標に変える。(正規化)
            // x(実部), y(虚部(iの係数))をそれぞれ求める。
            c_re = (x - WIDTH / 2) * (4.0 / WIDTH); //実部
            c_im = (y - HEIGHT / 2) * (4.0 / HEIGHT); //虚部
            // 繰り返し計算をし、発散するか確認。
            z_re = c_re;
            z_im = c_im;
            iter = 0;
            while (iter < MAX_ITER)
            {
                iter++;
                z_re2 = z_re * z_re;
                z_im2 = z_im * z_im;
                if (z_re2 * z_im2 > 4.0)
                	break; // 発散した時ループ終了。
                z_re = z_re2 - z_im2 + c_re;
                z_im = 2 * z_re * z_im + c_im;
            }
            /*
            	各点に色をつけていく。
            	反復計算の回数(iter)が多いほど、色が濃くなるようにする。
            */
        	// 反復回数に基づいて色の深さを決める関数。
            color = get_color(iter, MAX_ITER);
        	// 実際に色をつけていく関数。
            put_pixel_to_image(data, x, y, color);
        }
    }
    // windowにimgを適用させる
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}