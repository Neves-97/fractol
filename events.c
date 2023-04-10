#include "fractol.h"

// int move_pos(int keysum, t_data *pointer)
// {
//     if (keysum == ESC_KEY || keysum == 17)
//     {
//         mlx_destroy_window(pointer->mlx_ptr, pointer->win_ptr);
//         EXIT;
//     }
//     return (0);
// }

// int close_window(void *mlx_ptr, void *win_ptr)
// {
//     mlx_destroy_window(mlx_ptr, win_ptr);
//     exit(0);
// }

// void    hooks(t_data *pointer)
// {
//     mlx_key_hook(pointer->win_ptr, move_pos, pointer);
// }

int close_window(t_data *pointer)
{
    mlx_destroy_window(pointer->mlx_ptr, pointer->win_ptr);
    exit(0);
}

void draw_fractal(t_data *data)
{
    // Clear the image
    ft_memset(data->addr, 0, data->line_length * WINDOW_HEIGHT);

    
    // Draw the fractal
    julia(data);

    // Put the image on the screen
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}


int move_pos(int keysum, t_data *pointer)
{
    if (keysum == ESC_KEY)
        close_window(pointer);
    else if (keysum == RIGHT_ARROW)
        pointer->off_x -= 0.01;
    else if (keysum == LEFT_ARROW)
        pointer->off_x += 0.01;
    else if (keysum == UP_ARROW)
        pointer->off_y += 0.01;
    else if (keysum == DOWN_ARROW)
        pointer->off_y -= 0.01;
    draw_fractal(pointer);
    return (0);
}




// void hooks(t_data *pointer)
// {
    
//     mlx_hook(pointer->win_ptr, 17, StructureNotifyMask, &close_window, pointer);
//     mlx_key_hook(pointer->win_ptr, move_pos, pointer);
// }


void hooks(t_data *pointer)
{
    printf("setting yp hooks\n");
    // Set up callback for MouseScroll event 
    // Set up callback for other events as needed
    mlx_mouse_hook(pointer->win_ptr, &mouse_scroll, pointer);
    mlx_hook(pointer->win_ptr, 17, StructureNotifyMask, &close_window, pointer);
    mlx_key_hook(pointer->win_ptr, move_pos, pointer);
}

