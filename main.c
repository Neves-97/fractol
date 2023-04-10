# include "fractol.h"

// t_data *initialize_data()
// {
//     t_data *pointer = malloc(sizeof(t_data));

//     pointer->img = NULL;
//     pointer->addr = NULL;
//     pointer->bits_per_pixel = 0;
//     pointer->line_length = 0;
//     pointer->endian = 0;
//     pointer->zoom = 4;
//     pointer->off_x = 0.0;
//     pointer->off_y = 0.0;
    
//     return pointer;
// }


t_data *initialize_data()
{
    t_data *pointer = malloc(sizeof(t_data));

    pointer->mlx_ptr = NULL;
    pointer->win_ptr = NULL;
    pointer->img = NULL;
    pointer->addr = NULL;
    pointer->bits_per_pixel = 0;
    pointer->line_length = 0;
    pointer->endian = 0;
    pointer->zoom = 4;
    pointer->off_x = 0.0;
    pointer->off_y = 0.0;

    return pointer;
}



// int main(int ac, char **av)
// {
// 	t_data *pointer = initialize_data();

//     int img_width;
//     int img_height;
//     (void) av;
// 	if (ac != 2)
// 		display_error_msg();

//     pointer->mlx_ptr = mlx_init();
// 	pointer->win_ptr = mlx_new_window(pointer->mlx_ptr, 800, 800, "fractol");
//     // pointer->img = mlx_xpm_file_to_image(pointer->mlx_ptr, "/home/neves/Downloads/Screenshot-from-2023-02-27-20-04-23_1.xpm", &img_width, &img_height);
// 	// mlx_string_put(pointer->mlx_ptr, pointer->win_ptr, 100, 100, 0xFFFFFF, "Use mouse wheel to zoom in/out");
    
//     mlx_put_image_to_window(pointer->mlx_ptr, pointer->win_ptr, pointer->img, 0, 0);
//     mlx_hook(pointer->win_ptr, 4, 0, handle_mouse_scroll, pointer);
//     mlx_hook(pointer->win_ptr, 5, 0, handle_mouse_scroll, pointer);

//     mlx_hook(pointer->win_ptr, 17, 0, handle_mouse_scroll, pointer);


// 	hooks(pointer);
// 	mlx_loop(pointer->mlx_ptr);
//     mlx_destroy_image(pointer->mlx_ptr, pointer->img);

// 	free(pointer);

//     return (0);
// }

int main(int ac, char **av)
{
    t_data *data = initialize_data();

    (void) av;
    if (ac != 2)
    {
        display_error_msg();
        return (0);
    }
    // arg_parser(ac, av, data);
    data->mlx_ptr = mlx_init();
    data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fractol");
    
    data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    if (!data->img)
    {
        printf("Error: Failed to create image.\n");
        exit(1);
    }
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);

    // data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    // data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
    // Fill the image with the fractal
    set_julia_params(data, -0.835, 0.232);
    julia(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
    // mlx_hook(data->win_ptr, 4, 0, mouse_scroll, data);
    // mlx_hook(data->win_ptr, 5, 0, mouse_scroll, data);
    // // mlx_hook(data->win_ptr, 17, 0, mouse_scroll, data);
    hooks(data);
    mlx_loop(data->mlx_ptr);
    mlx_destroy_image(data->mlx_ptr, data->img);
    mlx_destroy_display(data->mlx_ptr);
    free(data);
    return (0);
}