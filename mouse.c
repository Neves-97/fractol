#include "fractol.h"

// void zoom_in(t_data *pointer, int x, int y)
// {
//     double zoom_factor = 1.1;
//     double new_zoom = pointer->zoom / zoom_factor;

//     double center_x = (double)x / pointer->zoom + pointer->off_x;
//     double center_y = (double)y / pointer->zoom + pointer->off_y;

//     pointer->off_x = center_x - (double)x / new_zoom;
//     pointer->off_y = center_y - (double)y / new_zoom;

//     pointer->zoom = new_zoom;
// }

// void zoom_out(t_data *pointer, int x, int y)
// {
//     double zoom_factor = 1.1;
//     double new_zoom = pointer->zoom * zoom_factor;

//     double center_x = (double)x / pointer->zoom + pointer->off_x;
//     double center_y = (double)y / pointer->zoom + pointer->off_y;

//     pointer->off_x = center_x - (double)x / new_zoom;
//     pointer->off_y = center_y - (double)y / new_zoom;

//     pointer->zoom = new_zoom;
// }

// void zoom_in(t_data *pointer, int x, int y)
// {
//     double zoom_factor = 1.1;
//     double new_zoom = pointer->zoom / zoom_factor;

//     double center_x = (double)x / pointer->zoom + pointer->off_x;
//     double center_y = (double)y / pointer->zoom + pointer->off_y;

//     pointer->off_x = center_x - (double)x / new_zoom;
//     pointer->off_y = center_y - (double)y / new_zoom;

//     pointer->zoom = new_zoom;

//     // Adjust offsets based on mouse position
//     if (pointer->mlx_ptr != NULL) {
//         int *mouse_x = (int *)pointer->mlx_ptr;
//         int *mouse_y = (int *)pointer->mlx_ptr + 1;
//         double delta_x = (x - *mouse_x) * pointer->zoom;
//         double delta_y = (y - *mouse_y) * pointer->zoom;
//         pointer->off_x += delta_x;
//         pointer->off_y += delta_y;
//     }
// }

// void zoom_out(t_data *pointer, int x, int y)
// {
//     double zoom_factor = 1.1;
//     double new_zoom = pointer->zoom * zoom_factor;

//     double center_x = (double)x / pointer->zoom + pointer->off_x;
//     double center_y = (double)y / pointer->zoom + pointer->off_y;

//     pointer->off_x = center_x - (double)x / new_zoom;
//     pointer->off_y = center_y - (double)y / new_zoom;

//     pointer->zoom = new_zoom;

//     // Adjust offsets based on mouse position
//     if (pointer->mlx_ptr != NULL) {
//         int *mouse_x = (int *)pointer->mlx_ptr;
//         int *mouse_y = (int *)pointer->mlx_ptr + 1;
//         double delta_x = (x - *mouse_x) * pointer->zoom;
//         double delta_y = (y - *mouse_y) * pointer->zoom;
//         pointer->off_x -= delta_x;
//         pointer->off_y -= delta_y;
//     }
// }

// void zoom_in(t_data *pointer, int x, int y)
// {
//     double zoom_factor = 1.1;
//     double new_zoom = pointer->zoom / zoom_factor;

//     double center_x = (double)x / pointer->zoom + pointer->off_x;
//     double center_y = (double)y / pointer->zoom + pointer->off_y;

//     pointer->off_x = center_x - (double)x / new_zoom;
//     pointer->off_y = center_y - (double)y / new_zoom;

//     pointer->zoom = new_zoom;

//     // Adjust offsets based on mouse position
//     if (pointer->win_ptr != NULL) {
//         int *mouse_x = (int *)pointer->win_ptr;
//         int *mouse_y = (int *)pointer->win_ptr + 1;
//         double delta_x = (x - *mouse_x) * pointer->zoom;
//         double delta_y = (y - *mouse_y) * pointer->zoom;
//         pointer->off_x += delta_x;
//         pointer->off_y += delta_y;
//     }
// }

// void zoom_out(t_data *pointer, int x, int y)
// {
//     double zoom_factor = 1.1;
//     double new_zoom = pointer->zoom * zoom_factor;

//     double center_x = (double)x / pointer->zoom + pointer->off_x;
//     double center_y = (double)y / pointer->zoom + pointer->off_y;

//     pointer->off_x = center_x - (double)x / new_zoom;
//     pointer->off_y = center_y - (double)y / new_zoom;

//     pointer->zoom = new_zoom;

//     // Adjust offsets based on mouse position
//     if (pointer->win_ptr != NULL) {
//         int *mouse_x = (int *)pointer->win_ptr;
//         int *mouse_y = (int *)pointer->win_ptr + 1;
//         double delta_x = (x - *mouse_x) * pointer->zoom;
//         double delta_y = (y - *mouse_y) * pointer->zoom;
//         pointer->off_x -= delta_x;
//         pointer->off_y -= delta_y;
//     }
// }



// int	handle_mouse_scroll(int button, int x, int y, t_vars *vars)
// {
// 	if (button == 4)
// 		zoom_out(vars, x, y);
// 	if (button == 5)
// 		zoom_in(vars, x, y);

// 	return (0);
// }

// int mouse_scroll(int keycode, int x, int y, void *param)
// {
//     t_data *data = (t_data *)param;

//     if (keycode == SCROLL_DOWN)
//     {
//         data->zoom *= 0.8;
//         data->off_x += (x - data->width / 2) * 0.1 / data->zoom;
//         data->off_y += (y - data->height / 2) * 0.1 / data->zoom;
//     }
//     else if (keycode == SCROLL_UP)
//     {
//         data->zoom *= 1.25;
//         data->off_x -= (x - data->width / 2) * 0.1 / data->zoom;
//         data->off_y -= (y - data->height / 2) * 0.1 / data->zoom;
//     }

// 	draw_fractal(data);
//     return (0);
// }

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
    draw_fractal(data);
    return (0);
}




