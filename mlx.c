#include "fractol.h"

// MiniLibXの初期化とwindowの作成を行う関数
// 出力処理はしない。mlx,window,imgを作り、addrを取得するだけ
void	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init(); // コンテキストの取得。
    if (!data->mlx_ptr)
    {
        fprintf(stderr, "Error: Failed to obtain context\n");
    	exit(EXIT_FAILURE);
    }
    data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "Fractol");
    if (!data->win_ptr)
    {
        fprintf(stderr, "Error: Failed to create window\n");
        exit(EXIT_FAILURE);
    }
    data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->size_line, &data->endian);
}

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
    	return (0x000000);
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
    	return (r << 16 | g << 8 | b);
    }
}