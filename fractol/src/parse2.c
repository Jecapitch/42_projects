/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:24:48 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/10 15:39:43 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	color_input(int rgb[3], int r, int g, int b);

static void	color_input(int rgb[3], int r, int g, int b)
{
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
}

void	rgb_init(int argc, char **argv, t_data *data)
{
	char	**arg;
	char	type;
	int		r;
	int		g;
	int		b;

	type = data->type;
	type = (type == J || type == M);
	if (argc < 6 || !ft_strncmp(argv[5], "d", ft_strlen(argv[5])))
		return (color_input(data->rgb, RDEF * type + CRDEF * !type, \
				GDEF * type + CGDEF * !type, BDEF * type + CBDEF * !type));
	arg = ft_split(argv[5], ' ');
	if (!arg)
		return (perror("Initialisation"), quit(data), exit(EXIT_FAILURE));
	if (!arg[0] || !arg[1] || !arg[2] || arg[3] || !ft_isint(arg[0]) \
		|| !ft_isint(arg[1]) || !ft_isint(arg[2]))
		return (ft_fprintf(STDERR, "color_factor must be " \
		"\"int int int\" or d\n"), ft_free_str_arr(arg), exit(EXIT_SUCCESS));
	r = ft_atoi(arg[0]);
	g = ft_atoi(arg[1]);
	b = ft_atoi(arg[2]);
	if (r < 0 || g < 0 || b < 0)
		return (ft_fprintf(STDERR, "color_factor < 0\n"), ft_free_str_arr(arg), \
				exit(EXIT_SUCCESS));
	return (color_input(data->rgb, r, g, b), ft_free_str_arr(arg));
}

void	zoom_init(int argc, char **argv, t_data *data)
{
	if (argc < 7 || !ft_strncmp(argv[6], "d", ft_strlen(argv[6])))
	{
		(data->zoom = ZOOM);
		return ;
	}
	if (!ft_isint(argv[6]))
		return (ft_fprintf(STDERR, "zoom must be int\n"), exit(EXIT_SUCCESS));
	data->zoom = ft_atoi(argv[6]);
	if (data->zoom < 0)
		return (ft_fprintf(STDERR, "zoom < 0\n"), exit(EXIT_SUCCESS));
}
