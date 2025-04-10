/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:35:23 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/10 02:39:42 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int complex	*init_shape(t_data *data);
static void			colorize(t_data *data, int x, int y, int vertex);
static void			pixels(t_data *data, double x, double y, \
								int complex *vertices);

static void	colorize(t_data *data, int x, int y, int vertex)
{
	int		*rgb;
	int		color;

	vertex++;
	rgb = data->rgb;
	color = vertex * ((rgb[0] << 16) \
			+ (rgb[1] << 8) \
			+ rgb[2] \
			+ (100 << 24));
	pixel_put(data->curr_img, x + y * I, color);
}

static int complex	*init_shape(t_data *data)
{
	int			i;
	double		radian;
	double		r;
	double		s;
	int complex	*vertices;

	vertices = ft_calloc(data->n, sizeof(int complex));
	if (!vertices)
		return (perror("init_shape: ft_calloc"), close_help(data), \
				destroy_window(data), free(data->mlx), data->mlx = NULL, \
				exit(EXIT_FAILURE), NULL);
	i = 0;
	r = data->w_width / 2.0;
	s = data->w_height / 2.0;
	while (i < data->n)
	{
		radian = (180 + i * 360.0 / data->n) * M_PI / 180;
		vertices[i++] = (data->w_width / 2.0 + r * sin(radian)) \
					+ (data->w_height / 2.0 + s * cos(radian)) * I;
	}
	return (vertices);
}

static void	pixels(t_data *data, double x, double y, int complex *vertices)
{
	int				vertex;
	size_t			i;
	double			factor;

	i = 0;
	factor = creal(data->c);
	while (i++ < data->itermax)
	{
		vertex = rand() % data->n;
		x += (creal(vertices[vertex]) - x) * factor;
		y += (cimag(vertices[vertex]) - y) * factor;
		if (x >= 0 && x < data->w_width && y >= 0 && y < data->w_height)
			colorize(data, x, y, vertex);
	}
}

void	chaos(t_data *data)
{
	int complex	*vertices;

	vertices = NULL;
	vertices = init_shape(data);
	data->curr_img = (data->curr_img == &data->img1) \
						* (&data->img2 - &data->img1) \
					+ &data->img1;
	fill_win(data->curr_img, data->w_width, data->w_height, 0);
	pixels(data, data->w_width / 2, data->w_height / 2, vertices);
	free(vertices);
	mlx_put_image_to_window(data->mlx, data->win, data->curr_img->img, 0, 0);
}
