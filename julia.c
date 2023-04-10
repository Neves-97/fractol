/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: neves <neves@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:14:37 by neves             #+#    #+#             */
/*   Updated: 2023/04/10 19:46:41 by neves            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int iterate_julia(t_complex c, t_complex z)
{
    int n = 0;
    while (n < 100 && (z.re * z.re + z.im * z.im) < 4.0)
    {
        double x = z.re;
        double y = z.im;
        z.re = x * x - y * y + c.re;
        z.im = 2 * x * y + c.im;
        n++;
    }
    return n;
}

void set_julia_params(t_data *data, double re, double im)
{
    data->julia_re = re;
    data->julia_im = im;
}

void julia(t_data *data)
{
    t_complex c = { data->julia_re, data->julia_im };
    int i = 0;
    while (i < W_W)
    {
        int j = 0;
        while (j < W_W)
        {
            t_complex z = {
                (i - W_W / 2.0) * data->zoom / W_W + data->off_x,
                (j - W_W / 2.0) * data->zoom / W_W + data->off_y
            };
            int n = iterate_julia(c, z);
            if (n < 100)
                my_pixel_put(data, i, j, 0x000101 * n * 0x000f0f);

            j++;
        }
        i++;
    }
}
