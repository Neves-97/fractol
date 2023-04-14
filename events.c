/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:25:49 by roda-min          #+#    #+#             */
/*   Updated: 2023/04/14 11:32:48 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *pointer)
{
	free_data(pointer);
	exit(0);
}

int	mouse_scroll(int keycode, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
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

int	move_pos(int keysum, t_data *pointer)
{
	if (keysum == XK_Escape)
		close_window(pointer);
	else if (keysum == XK_Right)
		pointer->off_x -= 0.01;
	else if (keysum == XK_Left)
		pointer->off_x += 0.01;
	else if (keysum == XK_Up)
		pointer->off_y += 0.01;
	else if (keysum == XK_Down)
		pointer->off_y -= 0.01;
	draw_fractal(pointer->fractal_type, pointer);
	return (0);
}

void	hooks(t_data *pointer)
{
	mlx_mouse_hook(pointer->win_ptr, &mouse_scroll, pointer);
	mlx_hook(pointer->win_ptr, 17, StructureNotifyMask, &close_window, pointer);
	mlx_key_hook(pointer->win_ptr, move_pos, pointer);
}
