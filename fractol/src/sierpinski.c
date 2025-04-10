/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 01:35:23 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/09 23:52:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void			colorize(t_data *data, t_pic *img, \
						int complex pix, int vertex);
static int complex	midpix(t_data *data, int complex pix, int complex vertex);
static void			pixels(t_data *data, t_pic *img);

static void	colorize(t_data *data, t_pic *img, int complex pix, int vertex)
{
	int		*rgb;
	int		color;

	vertex++;
	rgb = data->rgb;
	color = vertex * (rgb[0] << 16) \
			+ (vertex + 1) * (rgb[1] << 8) \
			+ (vertex + 2) * rgb[2];
	pixel_put(img, pix, color);
}

static int complex	midpix(t_data *data, int complex pix, int complex vertex)
{
	int			x;
	int			y;

	x = (int)((creal(pix) \
		+ creal(vertex)) / fabs(creal(data->c))) % data->w_width;
	y = (int)((cimag(pix) \
		+ cimag(vertex)) / fabs(creal(data->c))) % data->w_height;
	return (x + y * I);
}

static void	pixels(t_data *data, t_pic *img)
{
	int complex	pix;
	int complex	dim;
	int			vertex;
	int complex	vertices[3];
	size_t		i;

	dim = data->w_width + data->w_height * I;
	pix = rand() % (int)creal(dim) + (rand() % (int)cimag(dim)) * I;
	vertices[0] = creal(dim) / 2;
	vertices[1] = creal(dim) + cimag(dim) * I;
	vertices[2] = cimag(dim) * I;
	i = 0;
	while (i++ < data->itermax)
	{
		vertex = rand() % 3;
		pix = midpix(data, pix, vertices[vertex]);
		colorize(data, img, pix, vertex);
	}
}

void	sierpinski(t_data *data)
{
	t_pic		*img;

	img = (data->curr_img == &data->img1) * (&data->img2 - &data->img1) \
			+ &data->img1;
	fill_win(img, data->w_width, data->w_height, 0);
	pixels(data, img);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	data->curr_img = img;
}
