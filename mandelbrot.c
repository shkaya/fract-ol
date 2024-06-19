#include "fractol.h"

// colorのデータを各ピクセルに設定していく関数。
void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
    int	pixel;

    // 先頭からの対象のピクセルまでのバイト数。
    pixel = ((y * data->size_line) + x * (data->bpp / 8));
	// 通常は1ピクセル = 4バイトなので一倍とずつ色のデータを格納していく。
    // MiniLibxにはBGRの順が多い。
	data->addr[pixel] = color; // 青成分
    data->addr[pixel + 1] = color >> 8; // 緑成分
    data->addr[pixel + 2] = color >> 16; // 赤成分
    return;
}

// カラーマッピングをする関数
int	get_color(int iter, int max)
{
    if (iter == max)
    	return (0x00000000);
    /*
		発散する点(0<t<1)は*色付きで、発散していない点(t = 1)は黒で表現する。
        発散しない点: tが0または1に近い時　-> 成分は0に近くなる(黒に近づく)
    
        多項式関数(3次や2次)にすることで滑らかな曲線、グラデーションを作る?
    */
   	else
    {
		// 反復回数の割合を0 ~ 255(1byte)で表す。
    	double t = (double)iter / max;
        // (double)でキャストしていない -> intで処理されて0になってた?
    
    	int	r = (int)(9 * t * t * t * 256); //　赤色成分の計算
    	int	g = (int)(15 * (1 - t) * t * t * 256); // 緑色成分の計算
    	int	b = (int)(8.5 * (1 - t) * (1 - t) * t * 256); // 青色成分の計算
    	// (1 - t)とtがあることで、どちらかに偏っていた時、必ず0に近くなる。
        // いい感じのグラデーションになるらしい。
    	return (r << 16 | g << 8 | b);
    }
}

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
            c_re = data->scale * (x - WIDTH / 2) * (4.0 / WIDTH) + data->offset_x; //実部
            c_im = data->scale * (y - HEIGHT / 2) * (4.0 / HEIGHT) + data->offset_y;//虚部
            // 繰り返し計算をし、発散するか確認。
            z_re = c_re;
            z_im = c_im;
            iter = 0;
            while (iter < MAX_ITER)
            {
                z_re2 = z_re * z_re;
                z_im2 = z_im * z_im;
                if (z_re2 + z_im2 > 4.0)
                	break; // 発散した時ループ終了。
                z_re = z_re2 - z_im2 + c_re;
                z_im = 2 * z_re * z_im + c_im;
                iter++;
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
