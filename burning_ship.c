/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:28:47 by roda-min          #+#    #+#             */
/*   Updated: 2023/04/10 19:00:36 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	iterate_ship(t_complex *c, t_complex *z)
// {
//     int n;
//     n = 0;

//     while (n < 100 && z->re * z->re + z->im * z->im < 4)
//     {
//         double temp_re = z->re * z->re - z->im * z->im + c->re;
//         z->im = fabs(2 * z->re * z->im) - c->im;
//         z->re = temp_re;
//         n++;
//     }
//     return n;
// }

// void burning_ship(t_data *data)
// {
//     int i = 0;
//     while (i < W_W)
//     {
//         int j = 0;
//         while (j < W_W)
//         {
//             t_complex c = {
//                 (i - W_W / 2.0) * data->zoom / W_W + data->off_x,
//                 (j - W_W / 2.0) * data->zoom / W_W + data->off_y
//             };
//             t_complex z = {0, 0};
//             int n = iterate_ship(&c, &z);
//             if (n < 100)
//                 my_pixel_put(data, i, j, 0x000101 * n * 0x000f0f);
//             j++;
//         }
//         i++;
//     }
// }

int	iterate_ship(t_complex *c, t_complex *z)
{
    int	    n;
	double  temp_re;

	n = 0;
	while (n < 100 && z->re * z->re + z->im * z->im < 4)
	{
        temp_re = z->re * z->re - z->im * z->im + c->re;
		z->im = fabs(2 * z->re * z->im) - c->im;
		z->re = temp_re;
		n++;
	}
	return (n);
}

void	burning_ship(t_data *data)
{
	int i;

	i = 0;
	while (i < W_W)
	{
		int j;

		j = 0;
		while (j < W_W)
		{
            t_complex c = {
                (i - W_W / 2.0) * data->zoom / W_W + data->off_x,
                (j - W_W / 2.0) * data->zoom / W_W + data->off_y};
            t_complex z = {0, 0};
			int n = iterate_ship(&c, &z);
			if (n < 100)
				my_pixel_put(data, i, j, 0x000101 * n * 0x000f0f);
			j++;
		}
		i++;
	}
}
