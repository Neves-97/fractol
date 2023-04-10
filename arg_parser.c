#include "fractol.h"

int display_error_msg(void)
{
	printf("\033[34mError!\n");
	printf("\nProgram Usage:\n");
	printf("\n./fractol <Fractal>\n");
	printf("\nAvailable\n");
	printf("\nmandelbrot or 1\n");
	printf("\njulia or 2\n");
	printf("\nburning_ship or 3\n");
	printf("\n");
	// EXIT_FAILURE;
	exit(0);
	return (0);
}

// void display_fractal(char **av, t_data *data)
// {
// 	if (ft_strncmp(av[1], "mandelbrot", 11) == 0 || ft_strncmp(av[1], "1", 2) == 0)
// 		mandelbrot(data);
// 	else if (ft_strncmp(av[1], "julia", 6) == 0 || ft_strncmp(av[1], "2", 1) == 0)
// 		julia(data);
// 	else if (ft_strncmp(av[1], "burning_ship", 13) == 0 || ft_strncmp(av[1], "3", 2) == 0)
// 		burning_ship(data);
// }

// int arg_parser(int ac, char **av, t_data *data)
// {
// 	if (ac < 2)
// 		return(display_error_msg());
// 	else if (ft_strncmp(av[1], "julia", 6) == 0)
// 		draw_fractal(1, data);
// 	else if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
// 		draw_fractal(2, data);
// 	else if (ft_strncmp(av[1], "burning_ship", 13) == 0)
// 		draw_fractal(3, data);
// 	else
// 		return (display_error_msg());
// 	return (0);
// }

int arg_parser(int ac, char **av, t_data *data)
{
    if (ac < 2)
        return(display_error_msg());
    else if (ft_strncmp(av[1], "julia_1", 8) == 0)
        data->fractal_type = 3;
	else if (ft_strncmp(av[1], "julia_2", 8) == 0)
        data->fractal_type = 4;
	else if (ft_strncmp(av[1], "julia_3", 8) == 0)
        data->fractal_type = 5;
    else if (ft_strncmp(av[1], "mandelbrot", 11) == 0)
        data->fractal_type = 1;
    else if (ft_strncmp(av[1], "burning_ship", 13) == 0)
        data->fractal_type = 2;
    else
        return (display_error_msg());
    
    draw_fractal(data->fractal_type, data);
    
    return (0);
}



// int arg_parser(int ac, char **av, t_data *data)
// {	
// 	(void) data;
// 	(void) ac;
// 	(void) av;
// 	if (ac < 2)
// 	{
// 		return(display_error_msg());
// 		exit(0);
// 	}	
// 	else	
// 		printf("cona\n");
// 	return 1;
// }