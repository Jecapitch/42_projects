/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:40:02 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/06 05:13:40 by jpiscice         ###   ########.fr       */
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

typedef struct s_data		t_data;
typedef struct s_winsize	t_wsize;
typedef struct s_pic		t_pic;
typedef struct s_button		t_button;
typedef struct s_help		t_help;

# define TITLE_SIZE		32
# define ITERMAX		1000
# define ITERDEF		800
# define ARTLINE		42
# define LINESEP		'='
# define FRMBORDER		'+'
# define ZOOM			100
# define ZOOM_MAX		LONG_MAX
# define THETA			0.05
# define M				"Mandelbrot"
# define J				"Julia"
# define HELPTITLE		"Help"
# define HELPW			313
# define HELPH			163
# define HELPCOLOR		0x999999
# define HELPFONT		"-adobe-helvetica-*-r-normal-*-13-120-*-*-*-*-*-*"

struct s_pic
{
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
};

struct s_button
{
	int	x_min;
	int	y_min;
	int	x_max;
	int	y_max;
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
	float complex	ref;
	float complex	c;
	float complex	w_center;
	float			threshold;
	float			rotation;
	int				s_width;
	int				s_height;
	int				w_width;
	int				w_height;
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
int			julia(t_data data);

// TRANSFORMATIONS
void		zoom(int button, int complex coord, t_data *data);
void		iter_increment(int keysym, t_data *data);
void		reset(t_data *data);
void		rotate(int keysym, t_data *data);
int complex	move(int keysym);
void		center_on_click(int complex coord, t_data *data);
void		new_c_value(t_data *data);

// WINDOW EVENTS
int			quit(t_data *data);
void		keyquit(t_data *data);
int			open_help(t_data *data);
int 		close_help(t_data *data);
int			help_window(int keysym, t_data *data);

// HOOKS
int			keyhook(int keysym, t_data *data);
int			mousehook(int button, int x, int y, t_data *data);

// MISC
void		pixel_put(t_pic *data, int complex pixel, int color);
void		print_data(t_data data);

#endif
