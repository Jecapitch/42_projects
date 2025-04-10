/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/10 03:19:31 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	new_n_value(int keysym, t_data *data)
{
	int		val;
	int		newval;
	char	type;

	val = -(keysym == XK_w) + (keysym == XK_d);
	newval = (int)data->n + val;
	type = data->type;
	if (newval <= INT_MAX \
		&& ((type != C && newval >= 0) || (type == C && newval > 0)))
		data->n = newval;
}

void	mouse_new_c_value(t_data *data, int x, int y)
{
	double complex	coord;
	double complex	c;
	int complex		center;
	int complex		ref;
	int				zoom;

	c = data->c;
	center = data->w_center;
	ref = data->ref;
	zoom = data->zoom;
	coord = x + y * I;
	data->c = (c * zoom + (coord - center) / ref) - c * zoom;
}

void	key_new_c_value(int keysym, t_data *data)
{
	double complex	val;
	double complex	newval;

	val = data->c;
	newval = val - 0.01 * (keysym == XK_k) + 0.01 * (keysym == XK_l) \
			- 0.01 * (keysym == XK_y) * I + 0.01 * (keysym == XK_u) * I;
	if (data->type == C)
		newval += 0.01 * (creal(newval) == 0) - 0.01 * (creal(newval) == 1);
	data->c = newval;
}

void	change_color(int keysym, t_data *data)
{
	int	*rgb;

	rgb = data->rgb;
	rgb[0] += -(keysym == XK_e || keysym == XK_t) \
			+ (keysym == XK_r || keysym == XK_n);
	rgb[1] += -(keysym == XK_f || keysym == XK_t) \
			+ (keysym == XK_g || keysym == XK_n);
	rgb[2] += -(keysym == XK_v || keysym == XK_t) \
			+ (keysym == XK_b || keysym == XK_n);
}
