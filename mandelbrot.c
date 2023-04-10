#include "fractol.h"


int	iterate_mandelbrot(t_complex *c, t_complex *z)
{
    int n = 0;
    while (n < 100 && z->re * z->re + z->im * z->im < 4)
    {
        double temp_re = z->re * z->re - z->im * z->im + c->re;
        z->im = 2 * z->re * z->im + c->im;
        z->re = temp_re;
        n++;
    }
    return n;
}

void	mandelbrot(t_data *data)
{
    int i = 0;
    while (i < WINDOW_WIDTH)
    {
        int j = 0;
        while (j < WINDOW_WIDTH)
        {
            t_complex c = {
                (i - WINDOW_WIDTH / 2.0) * data->zoom / WINDOW_WIDTH + data->off_x,
                (j - WINDOW_WIDTH / 2.0) * data->zoom / WINDOW_WIDTH + data->off_y
            };
            t_complex z = {0, 0};
            int n = iterate_mandelbrot(&c, &z);
            if (n < 100)
                my_pixel_put(data, i, j, 0x000101 * n * n + 0x002020 * n + 0x000c0c);

            j++;
        }
        i++;
    }

    // data->zoom *= 0.9;
    // data->off_x += (WINDOW_WIDTH / 2.0 - data->off_x) * 0.1;
    // data->off_y += (WINDOW_WIDTH / 2.0 - data->off_y) * 0.1;
}

