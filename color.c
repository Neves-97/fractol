#include "fractol.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (!data)
		return ;
	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

// void my_pixel_put(t_data *data, int x, int y, int color)
// {
//     if (!data)
//     {
//         printf("Error: null data pointer in my_pixel_put()\n");
//         return ;
//     }

//     if (!data->addr)
//     {
//         printf("Error: null addr pointer in my_pixel_put()\n");
//         return ;
//     }

//     char *pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));

//     printf("my_pixel_put(%d, %d, %d) => pixel=%p\n", x, y, color, pixel);

//     *(unsigned int *)pixel = color;
// }

// void	my_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*pixel;

// 	if (!data || !data->addr)
// 	{
// 		printf("Error: null addr pointer in my_pixel_put()\n");
// 		return ;
// 	}
// 	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int *)pixel = color;
// }


// int	get_rgb(int r, int g, int b)
// {
// 	return (r << 16 | g << 8 | b);
// }