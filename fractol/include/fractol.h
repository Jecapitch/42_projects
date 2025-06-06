/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:40:02 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/14 00:04:25 by jpiscice         ###   ########.fr       */
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
# define C				'c'
# define JULIA			"Julia"
# define MANDEL			"Mandelbrot"
# define SIERP			"Sierpinski triangle"
# define CHAOS			"Chaos game"
# define ITERMAX		20000000
# define JITERDEF		1000
# define MITERDEF		100
# define SITERDEF		100000
# define CITERDEF		100000
# define JCDEF			(0.42 + 0.19 * I)
# define SCDEF			(2 + 2 * I)
# define M_R			M_SQRT2
# define J_R			2.0
# define N				2
# define NC				3
# define RDEF			2
# define GDEF			3
# define BDEF			5
# define CRDEF			50
# define CGDEF			100
# define CBDEF			200
# define ZOOM			200.0
# define ZOOM_MAX		LONG_MAX
# define THETA			0.05
# define WINFACTOR		0.33333333333333
# define TITLE			"fract-ol"
# define TITLE_SIZE		32
# define ARTLINE		42
# define LINESEP		'='
# define FRMBORDER		'+'
# define HELPTITLE		"Help"
# define HELPW			567
# define HELPH			333
# define HELPCOLOR		0x999999
# define HELPFONT		"-*-clean-*-r-normal-*-23-140-*-*-*-*-*-*"

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
	double			zoom;
	double			zoom_max;
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

// PARSE
void		get_type(t_data *data, char *argv);
void		n_iter(int argc, char **argv, t_data *data);
void		get_n(int argc, char **argv, t_data *data);
void		c_val(int argc, char **argv, t_data *data);
void		rgb_init(int argc, char **argv, t_data *data);
void		zoom_init(int argc, char **argv, t_data *data);

// INIT
void		mlxcreate(t_data *data);
void		init_data(t_data *data);
void		wincreate(t_data *data);
void		imgcreate(t_data *data, t_pic *img, int width, int height);
void		fill_win(t_pic *img, int width, int height, int color);

// FRACTALS
int			fractal(t_data *data);
void		julia(t_data *data);
void		sierpinski(t_data *data);
void		chaos(t_data *data);
void		switch_fractal(int keysym, t_data *data);

// TRANSFORMATIONS
void		zoom(int button, int complex coord, t_data *data);
void		iter_increment(int keysym, t_data *data);
void		reset(t_data *data);
void		rotate(int keysym, t_data *data);
int complex	move(int keysym);
void		center_on_click(int complex coord, t_data *data);
void		mouse_new_c_value(t_data *data, int x, int y);
void		key_new_c_value(int keysym, t_data *data);
void		new_n_value(int keysym, t_data *data);
void		change_color(int keysym, t_data *data);

// WINDOW EVENTS
int			quit(t_data *data);
void		keyquit(t_data *data);
int			open_help(t_data *data);
int			close_help(t_data *data);
int			help_window(int keysym, t_data *data);
void		destroy_window(t_data *data);

// HOOKS
int			keyhook(int keysym, t_data *data);
int			mousehook(int button, int x, int y, t_data *data);

// MISC
void		pixel_put(t_pic *data, int complex pixel, int color);
void		print_data(t_data data);

#endif
