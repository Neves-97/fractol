# include "fractol.h"

// t_data *initialize_data()
// {
//     t_data *pointer = malloc(sizeof(t_data));

//     pointer->mlx_ptr = NULL;
//     pointer->win_ptr = NULL;
//     pointer->img = NULL;
//     pointer->addr = NULL;
//     pointer->bits_per_pixel = 0;
//     pointer->line_length = 0;
//     pointer->endian = 0;
//     pointer->zoom = 4.5;
//     pointer->off_x = 0.0;
//     pointer->off_y = 0.0;

//     return pointer;
// }

t_data *initialize_data()
{
    t_data *pointer = malloc(sizeof(t_data));

    pointer->mlx_ptr = mlx_init();
    pointer->win_ptr = mlx_new_window(pointer->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fractol");
    pointer->img = mlx_new_image(pointer->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
    pointer->addr = mlx_get_data_addr(pointer->img, &pointer->bits_per_pixel, &pointer->line_length, &pointer->endian);
    pointer->zoom = 4.5;
    pointer->off_x = 0.0;
    pointer->off_y = 0.0;
    pointer->fractal_type = 0;

    return pointer;
}

// int main(int ac, char **av)
// {
//     t_data *data = initialize_data();

//     (void) av;
//     if (ac != 2)
//     {
//         display_error_msg();
//         return (0);
//     }
//     arg_parser(ac, av, data);
//     data->mlx_ptr = mlx_init();
//     data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "fractol");
    
//     data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
//     if (!data->img)
//     {
//         printf("Error: Failed to create image.\n");
//         exit(1);
//     }
//     data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);

//     // data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
//     // data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
//     // Fill the image with the fractal
//     mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
//     // mlx_hook(data->win_ptr, 4, 0, mouse_scroll, data);
//     // mlx_hook(data->win_ptr, 5, 0, mouse_scroll, data);
//     // // mlx_hook(data->win_ptr, 17, 0, mouse_scroll, data);
//     hooks(data);
//     mlx_loop(data->mlx_ptr);
//     mlx_destroy_image(data->mlx_ptr, data->img);
//     mlx_destroy_display(data->mlx_ptr);
//     free(data);
//     return (0);
// }

void    free_data(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    mlx_destroy_display(data->mlx_ptr);
    free(data->mlx_ptr);
    free(data);
}

int main(int ac, char **av)
{
    t_data *data = NULL;
    
    data = initialize_data();

    if (ac != 2)
    {
        display_error_msg();
        return (0);
    }
    arg_parser(ac, av, data);
    // Fill the image with the fractal
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
    hooks(data);
    mlx_loop(data->mlx_ptr);

    // mlx_destroy_image(data->mlx_ptr, data->img);
    // mlx_destroy_display(data->mlx_ptr);
    // free_data(&data);
    return (0);
}