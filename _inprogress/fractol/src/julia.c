/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:12:49 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/05 22:53:28 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	rotatepix(float complex *z, t_data data);
static void	jpoint(float complex pix, t_pic *img, t_data data);
static void	colorize(t_pic *img, float complex pix, int i, int in_set);

static void	rotatepix(float complex *z, t_data data)
{
	float	theta;

	theta = data.rotation;
	*z *= cexp(I * theta);
}

static void	jpoint(float complex pix, t_pic *img, t_data data)
{
	size_t					i;
	float complex			z;

	z = (pix - data.ref) / data.zoom;
	i = 0;
	rotatepix(&z, data);
	while (i++ < data.itermax && cabs(z) <= data.threshold)
	{
		if (*data.title == 'M')
			data.c = pix;
		z = cpow(z, 2.0) + data.c;
	}
	colorize(img, pix, i, i > data.itermax && cabs(z) <= data.threshold);
}

static void	colorize(t_pic *img, float complex pix, int i, int in_set)
{
	int	color;

	(void)i;
	color = 0x00000000;
	if (!in_set)
		color = 19 * 42 * i;
	pixel_put(img, pix, color);
}

int	julia(t_data data)
{
	float complex	pix;
	t_pic			*img;
	int				endl;
	int				w_width;
	int				w_height;

	w_width = data.w_width;
	w_height = data.w_height;
	img = (data.curr_img == &data.img1) * (&data.img2 - &data.img1) \
			+ &data.img1;
	pix = 0;
	endl = 0;
	while (cimag(pix) < w_height)
	{
		jpoint(pix, img, data);
		endl = (creal(pix) == w_width - 1);
		pix = !endl * (creal(pix) + 1) + (cimag(pix) + endl) * I;
	}
	mlx_put_image_to_window(data.mlx, data.win, img->img, 0, 0);
	data.curr_img = img;
	return (0);
}
