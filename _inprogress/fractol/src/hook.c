/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/06 05:13:05 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	keyhook(int keysym, t_data *data)
{
	if (keysym == XK_Left || keysym == XK_Right \
		|| keysym == XK_Up || keysym == XK_Down)
		return ((data->ref += move(keysym)), keysym);
	if (keysym == XK_r || keysym == XK_e)
		return (rotate(keysym, data), keysym);
	if (keysym == XK_Escape || keysym == XK_q)
		return (quit(data), keysym);
	if (keysym == XK_x)
		return (reset(data), keysym);
	if (keysym == XK_i || keysym == XK_j)
		return (iter_increment(keysym, data), keysym);
	if (keysym == XK_h)
		return (help_window(keysym, data), keysym);
	return (0);
}

int	mousehook(int button, int x, int y, t_data *data)
{
	int complex	coord;

	coord = x + y * I;
	if (button == 1)
		return (center_on_click(coord, data), button);
	if (button == 2 || button == 3)
		return (new_c_value(data), button);
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
