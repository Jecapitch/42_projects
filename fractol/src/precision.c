/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/10 16:06:33 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	zoom(int button, int complex coord, t_data *data)
{
	double			val;
	double			newval;
	double complex	mouse_pos;

	mouse_pos = (coord - data->ref) / data->zoom;
	val = 0.99 * (button == 5) + 1.10 * (button == 4);
	newval = data->zoom * val;
	if (newval >= 0 && newval <= (double)ZOOM_MAX)
	{
		data->ref = coord - mouse_pos * newval;
		data->zoom = newval;
	}
}

void	iter_increment(int keysym, t_data *data)
{
	int	val;
	int	newval;
	int	incr;
	int	iter;

	iter = data->itermax;
	if (iter > 1000000)
		incr = 100000;
	else if (iter > 100000)
		incr = 10000;
	else if (iter > 10000)
		incr = 1000;
	else if (iter > 1000)
		incr = 100;
	else if (iter > 100)
		incr = 10;
	else
		incr = 1;
	val = -incr * (keysym == XK_i) \
			+ incr * (keysym == XK_o);
	newval = data->itermax + val;
	if (newval > 0 && newval <= ITERMAX)
		data->itermax = newval;
}
