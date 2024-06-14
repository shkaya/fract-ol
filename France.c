#include "minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct	s_data
{
	void	*mlx;
    void	*window;
    void	*img;
	char 	*addr; // 画像データのアドレス
    int		bits_per_pixel; // ピクセルあたりのビット数
    int		line_length; // 画像の一行の長さ(バイト単位)
    int		endian; // エンディアン(バイトオーダー)
}				t_data;

int	render_next_frame(t_data *data)
{
    int width = 800;
    int height = 600;
    int blue = 0x0000FF;
	int white = 0xFFFFFF;
    int red = 0xFF0000;
    char *dst;

	// 画像をフランスにする。
    int x;
	for (int y = 0; y < height; y++)
    {
        x = 0;
        while (x < (width / 3))
        {
            dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
            *(int *)dst = blue;
            x++;
        }
        while(x < (width / 3) * 2)
        {
            dst = data->addr + (y * data->line_length + x++ * (data->bits_per_pixel / 8));
            *(int *)dst = white;
        }
        while (x < width)
        {
            dst = data->addr + (y * data->line_length + x++ * (data->bits_per_pixel / 8));
            *(int *)dst = red;
        }
    }
    // 画像をウィンドウに表示。
    mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
    return (0);
}

int main(void)
{
    t_data	data;

    data.mlx = mlx_init(); // MiniLibXの初期化。コンテキストを取得。
    if (!data.mlx)
    	return (printf("Error: Failed to initalize MiniLinX\n"), 1);
    data.window = mlx_new_window(data.mlx, 800, 600, "Fractol");
    if (!data.window)
    	return(printf("Error: Fialed to create window\n"), 1);
    
    //　新しい画像の作成。　
    data.img = mlx_new_image(data.mlx, 800, 600);
    // 画像データのアドレスを取得。
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    if (!data.addr)
    	return (printf("Error: Failed to obtain img's data address\n"), 1);
    // printf("%p", data.addr);
    // 毎フレーム呼び出される関数を設定。
    mlx_loop_hook(data.mlx, render_next_frame, &data);
    // イベントループの開始。
    mlx_loop(data.mlx);
    return (0);
}

/*　	---------------------MEMO----------------------------

	void *mlx = mlx_init(); MiniLibXの初期化。　*コンテキストを取得。
    コンテキスト: 特定の処理や操作を行うために必要な情報や状態の集まりのこと。
    			メリット: 描画操作を行うための情報を一元管理できる。
                基本的に取得したコンテキストはどのmlx系関数にも必要。(例外あり)
                [例外]　画像データのアドレスを取得するとき。mlx_get_data_addr()

    --------- printfでデバックする画期的な方法求む。-------------------
    mlx_get_data_addr関数で、実際に代入された値が何かprintfで確認したが
    よくわからない大きな値が入っていた。コンパイラやMiniLibXが原因かもとのこと。

	------- [注意] mlx_put_image_to_window関数において --------------------
	引数にx,yを指定するところがあるが、それはwindowに画像を`適当させない`範囲なので
    注意。つまり、基本的に全部表示させたい時は 0,0とする。
*/