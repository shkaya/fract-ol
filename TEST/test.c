#include <stdio.h>
#include "minilibx-linux/mlx.h"

int main(void)
{
    void	*mlx_ptr = mlx_init();
    void	*win_ptr = mlx_new_window(mlx_ptr, 800, 600, "TEST");
    if (!win_ptr)
    	return (printf("Error: Failed to create window\n"), 1);
    void	*img_ptr = mlx_new_image(mlx_ptr, 800, 600);
    int bpp;
    int size_line;
    int endian;
    char *addr = mlx_get_data_addr(img_ptr, &bpp, &size_line, &endian);
    int pixel;
    for (int y = 0; y < 600; y++)
    {
        for (int x = 0; x < 800; x++)
        {
            pixel = (y * size_line) + (x * bpp / 8);
            addr[pixel] = 0xFF; // 青成分?
    		addr[pixel + 1] = 0xFF; // 緑成分?
            addr[pixel + 2] = 0x00; // 赤成分?
        }
    }
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    mlx_loop(mlx_ptr);
    return (0);
}