/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:12:49 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/09 23:54:05 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	rotatepix(double complex *z, t_data *data);
static void	jpoint(int complex pix, t_pic *img, t_data *data);
static void	colorize(t_data *data, t_pic *img, int complex pix, \
					double complex abs_z_i);

static void	rotatepix(double complex *z, t_data *data)
{
	double	theta;

	theta = data->rotation;
	*z *= cexp(I * theta);
}

static void	jpoint(int complex pix, t_pic *img, t_data *data)
{
	size_t			i;
	double complex	z;
	double complex	c;
	double			abs_z;
	double			n;

	z = (pix - data->ref) / data->zoom;
	c = data->c * (data->type == J) + z * (data->type == M);
	z = z * (data->type == J);
	n = data->n;
	i = 0;
	rotatepix(&z, data);
	while (i++ < data->itermax && cabs(z) < pow(data->r, n))
		z = cpow(z, n) + c;
	abs_z = cabs(z);
	i = (i != data->itermax) * i;
	colorize(data, img, pix, abs_z + i * I);
}

static void	colorize(t_data *data, t_pic *img, int complex pix, \
					double complex abs_z_i)
{
	double	abs_z;
	int		i;
	int		color;
	int		*rgb;

	abs_z = creal(abs_z_i);
	i = cimag(abs_z_i);
	rgb = data->rgb;
	color = 0;
	if (i)
	{
		i++;
		color = (rgb[0] << 16) * i + (rgb[1] << 8) * i + rgb[2] * i;
		color -= log(log(abs_z)) / log(data->n);
	}
	pixel_put(img, pix, color);
}

void	julia(t_data *data)
{
	double complex	pix;
	t_pic			*img;
	int				endl;
	int				w_width;
	int				w_height;

	w_width = data->w_width;
	w_height = data->w_height;
	img = (data->curr_img == &data->img1) * (&data->img2 - &data->img1) \
			+ &data->img1;
	pix = 0;
	endl = 0;
	while (cimag(pix) < w_height)
	{
		jpoint(pix, img, data);
		endl = (creal(pix) == w_width - 1);
		pix = !endl * (creal(pix) + 1) + (cimag(pix) + endl) * I;
	}
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	data->curr_img = img;
}
