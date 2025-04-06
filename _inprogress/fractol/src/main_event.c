/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/06 04:11:57 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	destroy_window(t_data *data);

static void	destroy_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img1.img);
	mlx_destroy_image(data->mlx, data->img2.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	data->img1.img = NULL;
	data->img2.img = NULL;
	data->win = NULL;
}

int	quit(t_data *data)
{
	close_help(data);
	destroy_window(data);
	free(data->mlx);
	data->mlx = NULL;
	ft_fill_line(0, ARTLINE, '=', '=');
	ft_printf("Program ended successfully\n\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	keyquit(t_data *data)
{
	quit(data);
}
