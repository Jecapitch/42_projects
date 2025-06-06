/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/07 04:30:58 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int complex	move(int keysym)
{
	if (keysym == XK_Left)
		return (-5 + 0 * I);
	if (keysym == XK_Right)
		return (+5 + 0 * I);
	if (keysym == XK_Down)
		return (0 - 5 * I);
	if (keysym == XK_Up)
		return (0 + 5 * I);
	return (0);
}

void	rotate(int keysym, t_data *data)
{
	double	r;
	double	l;

	r = THETA * (keysym == XK_z);
	l = THETA * (keysym == XK_a);
	data->rotation -= (r - l);
}

void	center_on_click(int complex coord, t_data *data)
{
	data->ref -= (coord - data->w_center);
}

void	new_n_value(int keysym, t_data *data)
{
	int	val;
	int	newval;

	val = -(keysym == XK_w) + (keysym == XK_c);
	newval = (int)data->n + val;
	if (newval >= 0)
		data->n = newval;
}

void	new_c_value(t_data *data, int x, int y)
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

void	reset(t_data *data)
{
	data->ref = data->w_center;
	data->itermax = JITERDEF * (data->type == J) \
					+ MITERDEF * (data->type == M) \
					+ SITERDEF * (data->type == S);
	data->rotation = 0;
	data->zoom = ZOOM;
}
