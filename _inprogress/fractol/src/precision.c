/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/06 03:55:46 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	zoom(int button, int complex coord, t_data *data)
{
	float	val;
	float	newval;

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

	incr = (data->itermax <= 100) + 10 * (data->itermax > 100);
	val = -incr * (keysym == XK_j) \
			+ incr * (keysym == XK_k);
	newval = data->itermax + val;
	if (newval >= 0 && newval <= ITERMAX)
		data->itermax = newval;
}
