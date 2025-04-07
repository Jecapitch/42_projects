/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:24:48 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/07 03:53:23 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static void	get_type(t_data *data, char *argv);
static void	n_iter(int argc, char **argv, t_data *data);
static void	get_n(int argc, char **argv, t_data *data);
static void	c_val(int argc, char **argv, t_data *data);
static void	color_input(int rgb[3], int r, int g, int b);
static void	rgb_init(int argc, char **argv, t_data *data);
static void	zoom_init(int argc, char **argv, t_data *data);

static void	get_type(t_data *data, char *argv)
{
	int	arg;

	if (ft_strlen(argv) != 1)
	{
		ft_fprintf(STDERR, "First argument must be a single character\n");
		exit(EXIT_SUCCESS);
	}
	arg = ft_tolower(*argv);
	if (arg != J && arg != M && arg != S)
	{
		ft_fprintf(STDERR, "%s: invalid argument\n" \
		"> fractal_type (char): "BHRED"m"CRESET"andelbrot " \
		BHRED"j"CRESET"ulia "BHRED"s"CRESET"ierpinski\n", argv);
		exit(EXIT_SUCCESS);
	}
	data->type = arg;
	if (data->type == J)
		ft_strlcpy(data->title, JULIA, TITLE_SIZE);
	else if (data->type == M)
		ft_strlcpy(data->title, MANDEL, TITLE_SIZE);
	else if (data->type == S)
		ft_strlcpy(data->title, SIERP, TITLE_SIZE);
}

static void	n_iter(int argc, char **argv, t_data *data)
{
	if (argc < 3 || !ft_strncmp(argv[2], "d", ft_strlen(argv[2])))
	{
		data->itermax = JITERDEF * (data->type == J) \
						+ MITERDEF * (data->type == M) \
						+ SITERDEF * (data->type == S);
		return ;
	}
	if (!ft_isint(argv[2]))
		return (ft_fprintf(STDERR, "max_iterations must be int or d\n"), \
				exit(EXIT_SUCCESS));
	data->itermax = ft_atoi(argv[2]);
	if (data->itermax < 1 || data->itermax > ITERMAX)
	{
		ft_fprintf(STDERR, BHRED"/!\\"CRESET" Iterations must in range " \
						BHMAG"1-%d"CRESET".\n", ITERMAX);
		if (data->itermax > ITERMAX)
			ft_printf("\nRemember: "BHRED"higher is slower"CRESET" _O_%\n\n" \
						"           .----.   @   @\n" \
						"          / .-\"-.`.  \\v/\n" \
						"          | | '\\ \\ \\_/ )\n" \
						"        ,-\\ `-.' /.'  /\n" \
						"-------'---`----'----'-------------------\n");
		exit(EXIT_SUCCESS);
	}
}

static void	get_n(int argc, char **argv, t_data *data)
{
	if (argc < 4 || !ft_strncmp(argv[3], "d", ft_strlen(argv[3])))
	{
		data->n = N;
		return ;
	}
	if (!ft_isint(argv[3]))
		return (ft_fprintf(STDERR, "n must be int or d\n"), \
				exit(EXIT_SUCCESS));
	data->n = ft_atoi(argv[3]);
}

static void	check_c_arg(char **arg)
{
	if (!arg[0] || !arg[1] || !arg[2] || !arg[3] || arg[4] \
		|| !ft_isint(arg[0]) || !ft_isint(arg[1]) \
		|| !ft_isint(arg[2]) || !ft_isint(arg[3]))
		return (ft_fprintf(STDERR, \
				"c_value must be \"int int int int\" or d\n"), \
				ft_free_all(arg), exit(EXIT_SUCCESS));
}

static void	c_val(int argc, char **argv, t_data *data)
{
	char	**arg;
	double	x;
	double	y;
	int		divx;
	int		divy;

	data->c = 0.42 - 0.19 * I;
	if (argc < 5 || !ft_strncmp(argv[4], "d", ft_strlen(argv[4])))
		return ;
	arg = ft_split(argv[4], ' ');
	if (!arg)
		return (perror("Initialisation"), quit(data), exit(EXIT_FAILURE));
	check_c_arg(arg);
	x = ft_atoi(arg[0]);
	y = ft_atoi(arg[1]);
	divx = ft_atoi(arg[2]);
	divy = ft_atoi(arg[3]);
	if (!divx || !divy)
		return (ft_fprintf(STDERR, \
				BRED"Argl!"CRESET" Why are you dividing by 0?\n"), \
				ft_free_all(arg), exit(EXIT_SUCCESS));
	return ((data->c = x / divx + (y / divy) * I), ft_free_all(arg));
}

static void	color_input(int rgb[3], int r, int g, int b)
{
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
}

static void	rgb_init(int argc, char **argv, t_data *data)
{
	char	**arg;
	int		r;
	int		g;
	int		b;

	if (argc < 6 || !ft_strncmp(argv[5], "d", ft_strlen(argv[5])))
		return (color_input(data->rgb, RDEF, GDEF, BDEF));
	arg = ft_split(argv[5], ' ');
	if (!arg)
		return (perror("Initialisation"), quit(data), exit(EXIT_FAILURE));
	if (!arg[0] || !arg[1] || !arg[2] || arg[3] || !ft_isint(arg[0]) \
		|| !ft_isint(arg[1]) || !ft_isint(arg[2]))
		return (ft_fprintf(STDERR, \
				"color_factor must be \"int int int\" or d\n"), \
				ft_free_all(arg), exit(EXIT_SUCCESS));
	r = ft_atoi(arg[0]);
	g = ft_atoi(arg[1]);
	b = ft_atoi(arg[2]);
	if (r < 0 || g < 0 || b < 0)
		return (ft_fprintf(STDERR, "color_factor < 0\n"), ft_free_all(arg), \
				exit(EXIT_SUCCESS));
	return (color_input(data->rgb, r, g, b), ft_free_all(arg));
}

static void	zoom_init(int argc, char **argv, t_data *data)
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

void	argparse(int argc, char **argv, t_data *data)
{
	get_type(data, argv[1]);
	get_n(argc, argv, data);
	n_iter(argc, argv, data);
	c_val(argc, argv, data);
	rgb_init(argc, argv, data);
	zoom_init(argc, argv, data);
}
