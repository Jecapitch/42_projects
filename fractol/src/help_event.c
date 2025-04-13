/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/10 15:59:51 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	help_txt(t_data *data);

static void	help_txt(t_data *data)
{
	size_t		i;
	int			i_even;
	size_t		y;
	const char	txt[][64] = {"Esc / Q", "quit", "H", "open/close help", \
				"Arrow keys", "move fractal", "A / Z", "rotate left/right", \
				"Scroll up/down", "zoom in/out", \
				"Left click", "center on clicked point", \
				"", "for "SIERP", results", "", " in chaos", \
				"Right click", "use coordinates as c references", \
				"K / L // Y / U", "change x // y value (c = x + yi)", \
				"I / O", "-/+ iterations", \
				"W / D", "-/+ n", "J / M / S / C", \
				"switch type by initial letter", \
				"X", "reset fractal"};

	mlx_set_font(data->mlx, data->help.win, HELPFONT);
	i = 0;
	y = 19;
	while (i < sizeof(txt) / 64)
	{
		i_even = (i % 2 == 0);
		mlx_string_put(data->mlx, data->help.win, \
						19 + 181 * !i_even, y, 0, (char *)txt[i++]);
		y += 23 * !i_even;
	}
}

int	open_help(t_data *data)
{
	t_pic	*img;

	if (!data->help.open)
	{
		img = &data->help.img;
		data->help.win = mlx_new_window(data->mlx, HELPW, HELPH, HELPTITLE);
		imgcreate(data, img, HELPW, HELPH);
		fill_win(img, HELPW, HELPH, HELPCOLOR);
		mlx_put_image_to_window(data->mlx, data->help.win, img->img, 0, 0);
		help_txt(data);
		data->help.open = 1;
		mlx_hook(data->help.win, 17, 1L << 2, close_help, data);
		mlx_hook(data->help.win, 2, 1L << 0, help_window, data);
		mlx_hook(data->help.win, 2, 1L << 0, keyhook, data);
	}
	return (0);
}

int	close_help(t_data *data)
{
	t_pic	*img;
	void	*win;

	if (data->help.open)
	{
		img = data->help.img.img;
		win = data->help.win;
		mlx_destroy_image(data->mlx, img);
		mlx_destroy_window(data->mlx, win);
		img = NULL;
		win = NULL;
		data->help.open = 0;
		mlx_hook(data->help.win, 2, 1L << 0, help_window, data);
	}
	return (0);
}
