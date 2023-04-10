#include "fractol.h"

int close_window(t_data *pointer)
{
    free_data(pointer);
    exit(0);
}

int mouse_scroll(int keycode, int x, int y, void *param)
{
	t_data *data = (t_data *)param;
    (void)x;
	(void)y;
	if (keycode == SCROLL_DOWN || keycode == SCROLL_UP)
	{
		if (keycode == SCROLL_UP)
			data->zoom /= 0.8;
		else if (keycode == SCROLL_DOWN)
			data->zoom *= 0.8;
	}
    draw_fractal(data->fractal_type, data);
    return (0);
}



// int move_pos(int keysum, t_data *pointer)
// {
//     if (keysum == ESC_KEY)
//         close_window(pointer);
//     else if (keysum == RIGHT_ARROW)
//         pointer->off_x -= 0.01;
//     else if (keysum == LEFT_ARROW)
//         pointer->off_x += 0.01;
//     else if (keysum == UP_ARROW)
//         pointer->off_y += 0.01;
//     else if (keysum == DOWN_ARROW)
//         pointer->off_y -= 0.01;
//     draw_fractal(1, pointer);
//     return (0);
// }

int move_pos(int keysum, t_data *pointer)
{
    if (keysum == ESC_KEY)
        close_window(pointer);
    else if (keysum == RIGHT_ARROW)
        pointer->off_x -= (0.16 / (3 * pointer->zoom));
    else if (keysum == LEFT_ARROW)
        pointer->off_x += (0.16 / (3 * pointer->zoom));
    else if (keysum == UP_ARROW)
        pointer->off_y += (0.16 / (3 * pointer->zoom));
    else if (keysum == DOWN_ARROW)
        pointer->off_y -= (0.16 / (3 * pointer->zoom));
    
    draw_fractal(pointer->fractal_type, pointer);
    
    return (0);
}


void hooks(t_data *pointer)
{
    // Set up callback for MouseScroll event 
    // Set up callback for other events as needed
    mlx_mouse_hook(pointer->win_ptr, &mouse_scroll, pointer);
    mlx_hook(pointer->win_ptr, 17, StructureNotifyMask, &close_window, pointer);
    mlx_key_hook(pointer->win_ptr, move_pos, pointer);
}

