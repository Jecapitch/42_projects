/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:24:48 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/06 04:32:45 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	entitle(t_data *data, char *argv);
static void	n_iter(int argc, char **argv, t_data *data);
static void	c_val(int argc, char **argv, t_data *data);
static void	zoom_init(int argc, char **argv, t_data *data);

static int	entitle(t_data *data, char *argv)
{
	int	arg;

	if (ft_strlen(argv) != 1)
	{
		ft_fprintf(2, "First argument must be a single character\n");
		exit(EXIT_SUCCESS);
	}
	arg = ft_tolower(*argv);
	if (arg == 'm')
		return (ft_strlcpy(data->title, M, TITLE_SIZE));
	if (arg == 'j')
		return (ft_strlcpy(data->title, J, TITLE_SIZE));
	ft_fprintf(2, "%s: invalid argument\n", argv);
	exit(EXIT_SUCCESS);
}

static void	n_iter(int argc, char **argv, t_data *data)
{
	if (argc < 3 || !ft_strncmp(argv[2], "d", ft_strlen(argv[2])))
	{
		data->itermax = ITERDEF;
		return ;
	}
	if (!ft_isint(argv[2]))
		return (ft_fprintf(2, "max_iterations must be int or d\n"), \
				exit(EXIT_SUCCESS));
	data->itermax = ft_atoi(argv[2]);
	if (data->itermax < 1 || data->itermax > ITERMAX)
	{
		ft_fprintf(2, BHRED"/!\\"CRESET" Iterations must in range " \
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

static void	c_val(int argc, char **argv, t_data *data)
{
	char	**arg;
	size_t	len;

	if (argc < 4 || !ft_strncmp(argv[3], "d", ft_strlen(argv[3])))
	{
		data->c = 0.42 - 0.19 * I;
		return ;
	}
	arg = ft_split(argv[3], ' ');
	if (!arg)
		return (perror("Initialisation"), quit(data), exit(EXIT_FAILURE));
	if (!arg[0] || !arg[1] || !arg[2] || !arg[3] || arg[4] \
		|| !ft_isint(arg[0]) || !ft_isint(arg[1]) \
		|| !ft_isint(arg[2]) || !ft_isint(arg[3]))
		return (ft_fprintf(2, "c value must be \"int int int int\" or d\n"), \
				ft_free_all(arg), exit(EXIT_SUCCESS));
	len = ft_strlen(arg[2]) - 1;
	if (arg[2][len] == 'i')
		arg[2][len] = '\0';
	return ((data->c = (float)ft_atoi(arg[0]) / ft_atoi(arg[2]) \
		+ ((float) ft_atoi(arg[1]) / ft_atoi(arg[3])) * I), ft_free_all(arg));
}

static void	zoom_init(int argc, char **argv, t_data *data)
{
	if (argc < 5 || !ft_strncmp(argv[4], "d", ft_strlen(argv[4])))
	{
		(data->zoom = ZOOM);
		return ;
	}
	if (!ft_isint(argv[4]))
		return (ft_fprintf(2, "Zoom must be int\n"), exit(EXIT_SUCCESS));
	data->zoom = ft_atoi(argv[4]);
	if (data->zoom < 0)
		return (ft_fprintf(2, "Zoom < 0\n"), exit(EXIT_SUCCESS));
}

void	argparse(int argc, char **argv, t_data *data)
{
	entitle(data, argv[1]);
	n_iter(argc, argv, data);
	c_val(argc, argv, data);
	zoom_init(argc, argv, data);
}
