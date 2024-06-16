#include "fractol.h"

int main(void)
{
	t_data	data;
    init_mlx(&data);
    draw_mandelbrot(&data);
    mlx_loop(data.mlx_ptr);
    return (0);
}