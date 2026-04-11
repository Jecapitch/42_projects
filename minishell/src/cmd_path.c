/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:09:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 20:12:15 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**pathlist(void);

static char	**pathlist(void)
{
	char	**res;
	char	*path;

	path = getenv("PATH");
	if (!path)
		res = ft_split("", ' ');
	else
		res = ft_split(path, ':');
	if (!res)
		perror("path");
	return (res);
}

char	*get_path(char **paths, char *name)
{
	size_t	i;
	char	*file_path;

	i = 0;
	while (paths[i])
	{
		file_path = ft_strjoin_sep(paths[i], name, "/");
		if (!file_path)
			return (NULL);
		if (!access(file_path, F_OK))
			return (file_path);
		file_path = ft_free_safe(file_path);
		i++;
	}
	return (ft_strdup(""));
}

char	*get_bin_path(char *name)
{
	char	**paths;
	char	*file_path;

	if (!name)
		return (ft_strdup(""));
	if (ft_strchr(name, '/'))
	{
		if (!access(name, F_OK))
			return (ft_strdup(name));
		return (NULL);
	}
	paths = pathlist();
	if (!paths)
		return (NULL);
	file_path = get_path(paths, name);
	ft_free_str_arr(paths);
	return (file_path);
}

int	is_valid_exec(char *path, char *name)
{
	struct stat	st;

	if (!name)
		return (1);
	if (!(*name) || stat(path, &st))
		return (ft_fprintf(STDERR_FILENO, "'%s': " \
									"command not found\n", name), EX_NOTFOUND);
	if (access(path, X_OK))
		return (errno = EACCES, perror(name), EX_NOTEXEC);
	if (st.st_mode & S_IFDIR)
		return (errno = EISDIR, perror(name), EX_NOTEXEC);
	return (0);
}

int	get_command_bin_path(t_cmd *cmd)
{
	char	*path;

	if (cmd->isbuiltin)
		path = ft_strdup(*cmd->argv);
	else
		path = get_bin_path(*cmd->argv);
	cmd->executable = path;
	if (!path)
		return (perror(*cmd->argv), -1);
	return (0);
}
