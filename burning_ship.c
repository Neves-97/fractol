/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:28:47 by roda-min          #+#    #+#             */
/*   Updated: 2023/04/10 20:21:14 by neves            ###   ########.fr       */
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
	int		n;
	double	temp_re;

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

t_complex	calculate_c(int i, int j, t_data *data)
{
	t_complex	c;

	c = (t_complex)
	{
		(i - W_W / 2.0) * data->zoom / W_W + data->off_x,
		(j - W_W / 2.0) * data->zoom / W_W + data->off_y
	};
	return (c);
}

void	burning_ship(t_data *data)
{
	int			i;
	int			j;
	int			n;
	t_complex	c;
	t_complex	z;

	i = 0;
	while (i < W_W)
	{
		j = 0;
		while (j < W_W)
		{
			c = calculate_c(i, j, data);
			z = (t_complex){0, 0};
			n = iterate_ship(&c, &z);
			if (n < 100)
				my_pixel_put(data, i, j, 0x000101 * n * 0x000f0f);
			j++;
		}
		i++;
	}
}

// void	burning_ship(t_data *data)
// {
// 	int	i;
// 	int	j;
// 	int	n;
// 	t_complex c;
// 	t_complex z;

// 	i = 0;
// 	while (i < W_W)
// 	{
// 		j = 0;
// 		while (j < W_W)
// 		{
// 			c = (t_complex)
// 			{
// 				(i - W_W / 2.0) * data->zoom / W_W + data->off_x,
// 				(j - W_W / 2.0) * data->zoom / W_W + data->off_y
// 			};
// 			z = (t_complex){0, 0};

// 			n = iterate_ship(&c, &z);
// 			if (n < 100)
// 				my_pixel_put(data, i, j, 0x000101 * n * 0x000f0f);
// 			j++;
// 		}
// 		i++;
// 	}
// }
