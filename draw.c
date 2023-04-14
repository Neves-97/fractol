/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 14:12:33 by roda-min          #+#    #+#             */
/*   Updated: 2023/04/14 11:32:40 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;

	if (!data)
		return ;
	pixel = data->addr + (y * data->line_length)
		+ (x * (data->bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
}

void	draw_fractal(int fractal_type, t_data *data)
{
	ft_memset(data->addr, 0, data->line_length * WINDOW_HEIGHT);
	if (fractal_type == 1)
		mandelbrot(data);
	else if (fractal_type == 2)
		burning_ship(data);
	else if (fractal_type == 3)
	{
		set_julia_params(data, -0.835, 0.232);
		julia(data);
	}
	else if (fractal_type == 4)
	{
		set_julia_params(data, -0.400, 0.600);
		julia(data);
	}
	else if (fractal_type == 5)
	{
		set_julia_params(data, -0.671, 0.401);
		julia(data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}
