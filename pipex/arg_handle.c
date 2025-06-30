/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:09:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/03/28 01:04:39 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	check_args(char *name);

void	init(t_arg *args)
{
	args->infile = NULL;
	args->outfile = NULL;
	args->cmd1 = NULL;
	args->cmd2 = NULL;
	args->path1 = NULL;
	args->path2 = NULL;
}

static void	check_args(char *name)
{
	int	res;

	res = (access(name, F_OK) && access(name, R_OK));
	if (res)
	{
		perror(name);
		exit(errno);
	}
}

void	arg_parse(char **argv, t_arg *args)
{
	char	*cmd1;
	char	*cmd2;

	args->infile = argv[1];
	args->outfile = argv[4];
	cmd1 = argv[2];
	cmd2 = argv[3];
	check_args(args->infile);
	splitcmd(args, cmd1, cmd2);
	buildpath(args);
}

void	free_arg(t_arg *args)
{
	ft_free_str_arr(args->cmd1);
	ft_free_str_arr(args->cmd2);
	ft_free_nul(args->path1);
	ft_free_nul(args->path2);
}
