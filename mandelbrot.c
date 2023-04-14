/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:46:09 by roda-min          #+#    #+#             */
/*   Updated: 2023/04/14 11:33:12 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iterate_mandelbrot(t_complex *c, t_complex *z)
{
	int		n;
	double	temp_re;

	n = 0;
	while (n < 100 && z->re * z->re + z->im * z->im < 4)
	{
		temp_re = z->re * z->re - z->im * z->im + c->re;
		z->im = 2 * z->re * z->im + c->im;
		z->re = temp_re;
		n++;
	}
	return (n);
}

void	mandelbrot(t_data *data)
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
			n = iterate_mandelbrot(&c, &z);
			if (n < 100)
				my_pixel_put(data, i, j, 0x000101 * n * 0x000f0f);
			j++;
		}
		i++;
	}
}