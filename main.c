#include "fractol.h"

int main(void)
{
	// マンデルブロ集合
	// t_data	data;
    // init_mlx(&data);
    // draw_mandelbrot(&data);
    // mlx_loop(data.mlx_ptr);

	// ジュリア集合
    t_data	data;
	init_mlx(&data);
    draw_julia(&data, -0.4, 0.6);
	mlx_loop(data.mlx_ptr);
    return (0);
}