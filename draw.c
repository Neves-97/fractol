#include "fractol.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (!data)
		return ;
	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

// void draw_fractal(t_data *data)
// {
//     //Clear the image
//     ft_memset(data->addr, 0, data->line_length * WINDOW_HEIGHT);

//     // Draw the fractal
// 	set_julia_params(data, -0.835, 0.232);
//     set_julia_params(data, -0.941, 0.252);
// 	set_julia_params(data, -0.645, 0.415);
//     julia(data);

//     //image on the screen
//     mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
// }

// void draw_fractal(int fractal_type, t_data *data)
// {
//     //Clear the image
//     ft_memset(data->addr, 0, data->line_length * WINDOW_HEIGHT);

//     // Draw the fractal
//     if (fractal_type == 1) {
//         set_julia_params(data, -0.835, 0.232);
//         julia(data);
//     } else if (fractal_type == 2) {
//         mandelbrot(data);
//     } else if (fractal_type == 3) {
//         burning_ship(data);
// 	}
//     //image on the screen
//     mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
// }

void draw_fractal(int fractal_type, t_data *data)
{
    //Clear the image
    ft_memset(data->addr, 0, data->line_length * WINDOW_HEIGHT);

    // Draw the fractal
    if (fractal_type == 1) {
        mandelbrot(data);
    } else if (fractal_type == 2) {
        burning_ship(data);
    } else if (fractal_type == 3) {
        set_julia_params(data, -0.835, 0.232);
        julia(data);
    } else if (fractal_type == 4) {
        set_julia_params(data, -0.321, 0.271);
        julia(data);
    } else if (fractal_type == 5) {
        set_julia_params(data, -0.671, 0.401);
        julia(data);
    }
    //image on the screen
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
