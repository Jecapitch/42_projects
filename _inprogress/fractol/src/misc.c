/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:24:48 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/07 02:18:33 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	fractal(t_data data)
{
	char	type;

	type = data.type;
	if (type == J || type == M)
		return (julia(data), type);
	if (type == S)
		return (sierpinski(data), type);
	return (0);
}

void	pixel_put(t_pic *img, int complex pixel, int color)
{
	int		x;
	int		y;
	char	*dst;

	x = creal(pixel);
	y = cimag(pixel);
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	fill_win(t_pic *img, int width, int height, int color)
{
	int complex	pix;
	int			endl;

	pix = 0;
	endl = 0;
	while (cimag(pix) < height)
	{
		pixel_put(img, pix, color);
		endl = (creal(pix) == width - 1);
		pix = !endl * (creal(pix) + 1) + (cimag(pix) + endl) * I;
	}
}

void	print_data(t_data data)
{
	ft_putendl_fd("", 1);
	ft_fill_line(0, ARTLINE, LINESEP, LINESEP);
	ft_fill_line(ft_printf("#                FRACT-OL"), ARTLINE, ' ', '#');
	ft_fill_line(0, ARTLINE, LINESEP, LINESEP);
	ft_fill_line(0, ARTLINE, FRMBORDER, FRMBORDER);
	ft_fill_line(ft_printf("%c", FRMBORDER), ARTLINE, ' ', FRMBORDER);
	ft_fill_line(ft_printf("%c   Fractal type : %s", FRMBORDER, data.title), \
				ARTLINE, ' ', FRMBORDER);
	ft_fill_line(ft_printf("%c   Iterations   : %d", FRMBORDER, data.itermax), \
				ARTLINE, ' ', FRMBORDER);
	ft_fill_line(ft_printf("%c   n            : %d", FRMBORDER, data.n), \
				ARTLINE, ' ', FRMBORDER);
	ft_fill_line(ft_printf("+"), ARTLINE, ' ', FRMBORDER);
	ft_fill_line(0, ARTLINE, FRMBORDER, FRMBORDER);
	ft_fill_line(0, ARTLINE, LINESEP, LINESEP);
	ft_printf("Screen size : %d x %d\n", data.s_width, data.s_height);
	ft_printf("Window size : %d x %d\n", data.w_width, data.w_height);
	ft_fill_line(0, ARTLINE, LINESEP, LINESEP);
}
