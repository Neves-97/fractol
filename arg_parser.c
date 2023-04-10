#include "fractol.h"

int display_error_msg(void)
{
	// printf("\033[38;5;27;48;5;118mError!\n");
	printf("\033[34mError!\n");
	printf("\nProgram Usage:\n");
	printf("\n./fractol <Fractal>\n");
	printf("\nAvailable\n");
	printf("\nmandelbrot or 1\n");
	printf("\njulia or 2\n");
	printf("\nburning_ship or 3\n");
	printf("\n");
	EXIT_FAILURE;
	return (0);
}

void display_fractal(const char *fractal_name, t_data *data)
{
	if (strncmp(fractal_name, "mandelbrot", 11) == 0 || strncmp(fractal_name, "1", 2) == 0)
		mandelbrot(data);
	else if (strncmp(fractal_name, "julia", 6) == 0 || strncmp(fractal_name, "2", 1) == 0)
		julia(data);
	else if (strncmp(fractal_name, "burning_ship", 13) == 0 || strncmp(fractal_name, "3", 2) == 0)
		burning_ship(data);
	else
	{
		printf("\033[34mError: Invalid fractal name!\n");
		printf("\nAvailable:\n");
		printf("\nmandelbrot or 1\n");
		printf("\njulia or 2\n");
		printf("\nburning_ship or 3\n");
		printf("\n");
		exit(0);
	}
}

int arg_parser(int ac, char **av, t_data *data)
{
	if (ac < 2)
		return(display_error_msg());
	else if (ac == 2)
		display_fractal(av[1], data);
	else
		return (display_error_msg());
	return (0);
}


