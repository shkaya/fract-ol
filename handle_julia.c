#include "fractol.h"

/* キーイベントを処理する関数　*/
// なぜか引数に、入力されたkeyに当たる数字が渡されている。
// mlx_key_hookに渡す関数は必ずkeycodeを受け取れるようにしておかなければいけない？
int	handle_key_julia(int keycode, t_data *data)
{
	printf("key pass: %d\n", keycode);
    // ESCキーで終了
    if (keycode == KEY_ESC)
	{
        mlx_destroy_window(data->mlx_ptr, data->win_ptr); // 引数を間違えたことによりsegv発生
        exit(0);
    }
	// 座標の動きが顕微鏡のよう。
    if (keycode == KEY_PLUS)
    	data->scale /= 1.1;
    if (keycode == KEY_MINUS)
    	data->scale *= 1.1;
	// "* scale"によってそのスケールに適した動きになる。
    if (keycode == KEY_LEFT)
    	data->offset_x -= 0.1 * data->scale;
    if (keycode == KEY_RIGHT)
    	data->offset_x += 0.1 * data->scale;
    if (keycode == KEY_UP)
    	data->offset_y -= 0.1 * data->scale;
    if (keycode == KEY_DOWN)
    	data->offset_y += 0.1 * data->scale;
	draw_julia(data, data->c_re, data->c_im);
    return (0);
}

/* マウスイベントを処理する関数　*/
// x, yはマウスイベントが発生した時のwindow内座標(x < WIDTH && y < HEIGHT)
int	handle_mouse_julia(int button, int x, int y, t_data *data)
{
	printf("button: %d (%d,%d)\n", button, x, y);
	if (x < WIDTH && y < HEIGHT)
	{
		if (button == MOUSE_SCROLL_UP)
			data->scale /= 1.1;
		if (button == MOUSE_SCROLL_DOWN)
			data->scale *= 1.1;
		draw_julia(data, data->c_re, data->c_im);
	}
	return (0);
}

/* ウィンドウイベントを処理する関数　*/
int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}