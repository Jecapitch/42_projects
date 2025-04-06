/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/06 05:00:16 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	help_txt(t_data *data);

static void	help_txt(t_data *data)
{
	size_t		i;
	int			i_even;
	size_t		y;
	static char	txt[][64] = {"Esc / Q", "quit", \
							"H", "open/close help", \
							"Left click", "center on clicked point", \
							"Right click", "use coordinates for c", \
							"Scroll up/down", "zoom in/out", \
							"Arrow keys", "move fractal", \
							"E / R", "rotate left/right", \
							"I / J", "more/less iterations", \
							"X", "reset fractal"};

	mlx_set_font(data->mlx, data->help.win, HELPFONT);
	i = 0;
	y = 19;
	while (i < sizeof(txt) / 64)
	{
		i_even = (i % 2 == 0);
		mlx_string_put(data->mlx, data->help.win, \
						19 + 113 * !i_even, y, 0, txt[i]);
		y += 17 * !i_even;
		i++;
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
		mlx_hook(data->help.win, 17, 1L << 2, open_help, data);
	}
	return (0);
}
