/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:09:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/01 23:41:16 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	**pathlist(void);
static char	*binpath(char *cmd);

void	splitcmd(t_arg *args, char *cmd1, char *cmd2)
{
	if (!(*cmd1) || !(*cmd2))
	{
		ft_fprintf(2, "Invalid argument\n");
		exit(EXIT_FAILURE);
	}
	args->cmd1 = ft_split(cmd1, ' ');
	args->cmd2 = ft_split(cmd2, ' ');
	if (!args->cmd1 || !args->cmd2)
	{
		free_arg(args);
		ft_fprintf(2, "Command error\n");
		exit(EXIT_FAILURE);
	}
}

static char	**pathlist(void)
{
	char	*path;
	char	**res;

	path = ft_getenv_val("PATH");
	res = ft_split(path, ':');
	free(path);
	if (!res)
		ft_fprintf(2, "path: error");
	return (res);
}

static char	*binpath(char *cmd)
{
	char	**path;
	char	*fullpath;
	size_t	i;

	if (!cmd)
		return (ft_fprintf(2, "%s: command not found\n", cmd), NULL);
	if (!access(cmd, F_OK))
		return (ft_strdup(cmd));
	path = pathlist();
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		fullpath = ft_strjoin_sep(path[i], cmd, '/');
		if (!fullpath)
			return (ft_free_str_arr(path), NULL);
		if (!access(fullpath, F_OK))
			return (ft_free_str_arr(path), fullpath);
		free(fullpath);
		i++;
	}
	ft_free_str_arr(path);
	ft_fprintf(2, "%s: command not found\n", cmd);
	return (NULL);
}

void	buildpath(t_arg *args)
{
	args->path1 = binpath(args->cmd1[0]);
	args->path2 = binpath(args->cmd2[0]);
	if (!args->path1 || !args->path2)
	{
		free_arg(args);
		exit(EXIT_FAILURE);
	}
}
