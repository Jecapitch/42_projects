/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:34:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/14 00:11:59 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	fractal(t_data *data)
{
	char	type;

	type = data->type;
	if (type == J || type == M)
		return (julia(data), type);
	if (type == S)
		return (sierpinski(data), type);
	if (type == C)
		return (chaos(data), type);
	return (0);
}

void	switch_fractal(int keysym, t_data *data)
{
	char	*type;

	type = &data->type;
	*type = J * (keysym == XK_j) + M * (keysym == XK_m) \
			+ S * (keysym == XK_s) + C * (keysym == XK_c);
	data->itermax = JITERDEF * (*type == J) + MITERDEF * (*type == M) \
					+ SITERDEF * (*type == S) + CITERDEF * (*type == C);
	data->n = data->n * (*type != C) + NC * (*type == C);
	data->c = JCDEF * (*type == J) + SCDEF * (*type == S) \
				+ ((double)data->n / (data->n + 3)) * (*type == C);
	data->r = M_R * (*type == M) + J_R * (*type == J);
	data->rgb[0] = data->rgb[0] * (*type == J || *type == M) \
					+ CBDEF * (*type == S || *type == C);
	data->rgb[1] = data->rgb[1] * (*type == J || *type == M) \
					+ CBDEF * (*type == S || *type == C);
	data->rgb[2] = data->rgb[2] * (*type == J || *type == M) \
					+ CBDEF * (*type == S || *type == C);
	ft_strlcpy(data->title, JULIA, TITLE_SIZE);
	if (*type == M)
		ft_strlcpy(data->title, MANDEL, TITLE_SIZE);
	else if (*type == S)
		ft_strlcpy(data->title, SIERP, TITLE_SIZE);
	else if (*type == C)
		ft_strlcpy(data->title, CHAOS, TITLE_SIZE);
	print_data(*data);
}

void	reset(t_data *data)
{
	char	type;

	type = data->type;
	data->ref = data->w_center;
	data->itermax = JITERDEF * (type == J) \
					+ MITERDEF * (type == M) \
					+ SITERDEF * (type == S) \
					+ CITERDEF * (type == C);
	data->n = data->n * (type != C) + NC * (type == C);
	data->c = data->c * (type == J) + SCDEF * (type == S) \
				+ ((double)data->n / (data->n + 3)) * (type == C);
	data->r = M_R * (type == M) + J_R * (type == J);
	data->rotation = 0;
	data->zoom = ZOOM;
	if (type == S)
		data->c = SCDEF;
}
