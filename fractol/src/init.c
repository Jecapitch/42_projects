/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:24:48 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/10 14:52:16 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	mlxcreate(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		perror("mlx");
		exit(EXIT_FAILURE);
	}
}

void	wincreate(t_data *data)
{
	int				*s_width;
	int				*s_height;
	int				*w_width;
	int				*w_height;
	double complex	*w_center;

	s_width = &data->s_width;
	s_height = &data->s_height;
	w_width = &data->w_width;
	w_height = &data->w_height;
	w_center = &data->w_center;
	mlx_get_screen_size(data->mlx, s_width, s_height);
	*w_width = *s_width * WINFACTOR;
	*w_height = *s_height * WINFACTOR;
	*w_center = *w_width / 2 + (*w_height / 2) * I;
	data->ref = *w_center;
	data->win = mlx_new_window(data->mlx, *w_width, *w_height, TITLE);
}

void	imgcreate(t_data *data, t_pic *img, int width, int height)
{
	img->img = mlx_new_image(data->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, \
								&img->bits_per_pixel, \
								&img->line_length, \
								&img->endian);
}

void	init_data(t_data *data)
{
	wincreate(data);
	imgcreate(data, &data->img1, data->w_width, data->w_height);
	imgcreate(data, &data->img2, data->w_width, data->w_height);
	data->r = M_R * (data->type == M) + J_R * (data->type == J);
	data->rotation = 0;
	data->curr_img = &data->img2;
	data->help.open = 0;
}
