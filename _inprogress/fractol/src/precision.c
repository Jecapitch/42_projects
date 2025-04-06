/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/06 17:33:20 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	zoom(int button, int complex coord, t_data *data)
{
	double	val;
	double	newval;

	(void)coord;
	val = -1 * (button == 4) + 1 * (button == 5);
	newval = data->zoom + val;
	if (newval >= 0 && newval <= ZOOM_MAX)
		data->zoom = newval;
}

void	iter_increment(int keysym, t_data *data)
{
	int	val;
	int	newval;
	int	incr;

	if (data->itermax > 10000)
		incr = 1000;
	else if (data->itermax > 1000)
		incr = 100;
	else if (data->itermax > 100)
		incr = 10;
	else
		incr = 1;
	val = -incr * (keysym == XK_i) \
			+ incr * (keysym == XK_o);
	newval = data->itermax + val;
	if (newval >= 0 && newval <= ITERMAX)
		data->itermax = newval;
}
