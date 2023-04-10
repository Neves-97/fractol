#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include "mlx_linux/mlx.h"
// #include <mlx.h>
#include <X11/Xlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>
#include <unistd.h>
#include <string.h>

# define ESC_KEY XK_Escape
# define LEFT_ARROW XK_Left
# define RIGHT_ARROW XK_Right
# define UP_ARROW XK_Up
# define DOWN_ARROW XK_Down
# define MOUSE_LEFT_CLICK 1
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
#define W_W 1200
#define WINDOW_HEIGHT 1200
#define EXIT exit(0)
#define MLX_ERROR 1
#define Destroy_Notify 17
#define SCROLL_UP 5
# define SCROLL_DOWN 4


#define IT_MAX 100
#define FOLDED_EPSILON 0.001
#define SCALE 2.0

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif




#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define WHITE_PIXEL 0xFFFFFF
#define ORANGE_PIXEL 0xFF8000

typedef struct	s_data 
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	off_x;
	double	off_y;
	double	julia_re;
	double	julia_im;
	int		fractal_type;
}	t_data;

typedef struct		s_complex
{
	double			re;
	double			im;
}			t_complex;

typedef struct s_vars
{
	t_data *img;

} t_vars;

void    free_data(t_data *data);

int display_error_msg(void);

int	ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memset(void *b, int c, size_t len);


void	my_pixel_put(t_data *data, int x, int y, int color);
int move_pos(int keysum, t_data *pointer);
void    hooks(t_data *pointer);

int mouse_scroll(int keycode, int x, int y, void *param);


void julia(t_data *data);
int iterate_julia(t_complex c, t_complex z);
void set_julia_params(t_data *data, double re, double im);


int	iterate_ship(t_complex *c, t_complex *z);
void	burning_ship(t_data *data);




void	mandelbrot(t_data *data);
int	iterate_mandelbrot(t_complex *c, t_complex *z);


void	zoom_in(t_vars *vars, int x, int y);
void	zoom_out(t_vars *vars, int x, int y);
int	handle_mouse_scroll(int button, int x, int y, t_vars *vars);


// void draw_fractal(t_data *data);

void draw_fractal(int fractal_type, t_data *data);


// agr parser

// void display_fractal(char **av, t_data *data);

int arg_parser(int ac, char **av, t_data *data);

#endif

/*If you don't have sudo access on your system, you can still update the include statement by following these steps:

    Copy the "mlx.h" header file from /home/neves/Documents/42projects/fractol/mlx_linux/ to a directory where you have write access. For example, you can create a directory called include in your home directory and copy the file there:

shell

$ mkdir ~/include
$ cp /home/neves/Documents/42projects/fractol/mlx_linux/mlx.h ~/include/

    Set the C_INCLUDE_PATH environment variable to include the directory where you copied the "mlx.h" header file:

shell

$ export C_INCLUDE_PATH=$HOME/include

    Update the include statement in your source code from "mlx_linux/mlx.h" to <mlx.h>:

Before:

c

#include "mlx_linux/mlx.h"

After:

c

#include <mlx.h>

    Recompile your code and make sure it compiles without any errors or warnings.

Note that setting the C_INCLUDE_PATH environment variable will only work for the current terminal session. If you want to make the change permanent, you'll need to add the export command to your shell configuration file (e.g. .bashrc or .zshrc).*/