#include "minilibx-linux/mlx.h"
#include <stdio.h>

typedef struct	s_data
{
	void	*mlx;
    void	*window;
    void	*img;
    char 	*addr;
	int		size_line;
    int 	bits_per_pixel;
    int		endian;
}				t_data;

int	put_img(t_data	*Italia)
{
    int hight = 600;
    int width = 800;
    int white = 0xFFFFFF;
	int green = 0x00FF00;
    int red = 0xFF0000;
    char *dst;

	int x = 0;
    for (int y = 0; y < hight; y++)
    {
        x = 0;
        while (x < (width / 3))
        {
			dst = Italia->addr + (y * Italia->size_line + x++ * (Italia->bits_per_pixel / 8));
            *(int *)dst = green;
        }
        while (x < (width / 3) * 2)
        {
			dst = Italia->addr + (y * Italia->size_line + x++ * (Italia->bits_per_pixel / 8));
            *(int *)dst = white;
        }
        while (x < width)
        {
			dst = Italia->addr + (y * Italia->size_line + x++ * (Italia->bits_per_pixel / 8));
            *(int *)dst = red;
        }
    }

    mlx_put_image_to_window(Italia->mlx, Italia->window, Italia->img, 0, 0);
    return(0);
}

int main(void)
{
    t_data	Italia;

	Italia.mlx = mlx_init(); // コンテキストの取得
    if (!Italia.mlx)
    	return (printf("Error: Failed to obtain context\n"), 1);
    // windowの作成
	Italia.window = mlx_new_window(Italia.mlx, 800, 600, "Italia");
	// imgの作成
    Italia.img = mlx_new_image(Italia.mlx, 800, 600);
    //  画像データのアドレスを取得
    Italia.addr = mlx_get_data_addr(Italia.img, &Italia.bits_per_pixel, &Italia.size_line, &Italia.endian);

	// 毎フレーム呼び出される関数を設定。
    mlx_loop_hook(Italia.mlx, put_img, &Italia);
    // イベントループの開始
    mlx_loop(Italia.mlx);
    return (0);
}