/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:40:02 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/07 04:01:26 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <libft.h>
# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <math.h>
# include <complex.h>
# include <time.h>

# define J				'j'
# define M				'm'
# define S				's'
# define JULIA			"Julia"
# define MANDEL			"Mandelbrot"
# define SIERP			"Sierpinski"
# define ITERMAX		100000
# define JITERDEF		1000
# define MITERDEF		100
# define SITERDEF		ITERMAX
# define M_R			M_SQRT2
# define J_R			2.0
# define N				2.0
# define RDEF			19
# define GDEF			42
# define BDEF			1942
# define ZOOM			200
# define ZOOM_MAX		LONG_MAX
# define THETA			0.05
# define TITLE			"fract-ol"
# define TITLE_SIZE		32
# define ARTLINE		42
# define LINESEP		'='
# define FRMBORDER		'+'
# define HELPTITLE		"Help"
# define HELPW			313
# define HELPH			163
# define HELPCOLOR		0x999999
# define HELPFONT		"-adobe-helvetica-*-r-normal-*-13-120-*-*-*-*-*-*"
# define ARGLIST		"Missing argument (-_-)\n" \
						"./fractol fractal_type [max_iterations] [exponent]" \
						"[\"c_x c_y div_x div_y\"]\n" \
						"          [\"factor1 factor2 factor3\"] [zoom]\n" "\n" \
						"Use d or \"\" for default.\n"

typedef struct s_data		t_data;
typedef struct s_winsize	t_wsize;
typedef struct s_pic		t_pic;
typedef struct s_button		t_button;
typedef struct s_help		t_help;

struct s_pic
{
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
};

struct s_help
{
	void	*win;
	t_pic	img;
	int		open;
};

struct s_data
{
	void			*mlx;
	void			*win;
	size_t			itermax;
	long			zoom;
	long			zoom_max;
	t_pic			img1;
	t_pic			img2;
	t_pic			*curr_img;
	t_help			help;
	double complex	ref;
	double complex	c;
	double complex	w_center;
	double			r;
	double			rotation;
	int				n;
	int				s_width;
	int				s_height;
	int				w_width;
	int				w_height;
	int				rgb[3];
	char			type;
	char			title[TITLE_SIZE];
};

// INIT
void		argparse(int argc, char **argv, t_data *data);
void		mlxcreate(t_data *data);
void		init_data(t_data *data);
void		wincreate(t_data *data);
void		imgcreate(t_data *data, t_pic *img, int width, int height);
void		fill_win(t_pic *img, int width, int height, int color);

// FRACTALS
int			fractal(t_data data);
void		julia(t_data data);
void		sierpinski(t_data data);
void		switch_fractal(int keysym, t_data *data);

// TRANSFORMATIONS
void		zoom(int button, int complex coord, t_data *data);
void		iter_increment(int keysym, t_data *data);
void		reset(t_data *data);
void		rotate(int keysym, t_data *data);
int complex	move(int keysym);
void		center_on_click(int complex coord, t_data *data);
void		new_c_value(t_data *data, int x, int y);
void		new_n_value(int keysym, t_data *data);
void		change_color(int keysym, t_data *data);

// WINDOW EVENTS
int			quit(t_data *data);
void		keyquit(t_data *data);
int			open_help(t_data *data);
int			close_help(t_data *data);
int			help_window(int keysym, t_data *data);

// HOOKS
int			keyhook(int keysym, t_data *data);
int			mousehook(int button, int x, int y, t_data *data);

// MISC
void		pixel_put(t_pic *data, int complex pixel, int color);
void		print_data(t_data data);

#endif
