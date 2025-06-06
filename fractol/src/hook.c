/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/10 02:04:38 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	keyhook(int keysym, t_data *data)
{
	if (keysym == XK_e || keysym == XK_f || keysym == XK_v || keysym == XK_t \
		|| keysym == XK_r || keysym == XK_g || keysym == XK_b || keysym == XK_n)
		return (change_color(keysym, data), keysym);
	if (keysym == XK_Left || keysym == XK_Right \
		|| keysym == XK_Up || keysym == XK_Down)
		return ((data->ref += move(keysym)), keysym);
	if (keysym == XK_a || keysym == XK_z)
		return (rotate(keysym, data), keysym);
	if (keysym == XK_w || keysym == XK_d)
		return (new_n_value(keysym, data), keysym);
	if (keysym == XK_y || keysym == XK_u || keysym == XK_k || keysym == XK_l)
		return (key_new_c_value(keysym, data), keysym);
	if (keysym == XK_i || keysym == XK_o)
		return (iter_increment(keysym, data), keysym);
	if (keysym == XK_x)
		return (reset(data), keysym);
	if (keysym == XK_j || keysym == XK_m || keysym == XK_s || keysym == XK_c)
		return (switch_fractal(keysym, data), keysym);
	if (keysym == XK_h)
		return (help_window(keysym, data), keysym);
	if (keysym == XK_Escape || keysym == XK_q)
		return (quit(data), keysym);
	return (0);
}

int	mousehook(int button, int x, int y, t_data *data)
{
	int complex	coord;

	coord = x + y * I;
	if (button == 1)
		return (center_on_click(coord, data), button);
	if (data->type != M && data->type != C && (button == 2 || button == 3))
		return (mouse_new_c_value(data, x, y), button);
	if (button == 4 || button == 5)
		return (zoom(button, coord, data), button);
	return (0);
}

int	help_window(int keysym, t_data *data)
{
	if (keysym == XK_h)
	{
		if (data->help.open)
			return (close_help(data), keysym);
		return (open_help(data), keysym);
	}
	if (keysym == XK_Escape || keysym == XK_q)
		return (keyquit(data), keysym);
	return (0);
}
