/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldpwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 23:46:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	open_oldpwd(t_shdata *shdata, int oflag)
{
	shdata->fd_oldpwd = open(shdata->oldpwd_file, oflag, 0644);
	if (shdata->fd_history == -1)
		return (-1);
	return (0);
}

int	load_oldpwd(t_shdata *shdata)
{
	char	*line;
	size_t	len;

	line = NULL;
	if (expand_path(shdata->sh_environ, shdata->oldpwd_file, \
					"HOME", OLDPWD_FILE) == -1 \
		|| open_oldpwd(shdata, O_RDONLY | O_CREAT) == -1)
		return (-1);
	line = get_next_line(shdata->fd_oldpwd);
	len = ft_strlen(line);
	if (len && len <= MAXPATHLEN + 1)
		ft_strlcpy(shdata->oldpwd, line, len - 1);
	ft_free_nul(line);
	return (close(shdata->fd_oldpwd));
}

int	save_oldpwd(t_shdata *shdata)
{
	if (open_oldpwd(shdata, O_WRONLY | O_CREAT | O_TRUNC) == -1)
		return (-1);
	if (ft_fprintf(shdata->fd_oldpwd, "%s\n", shdata->cwd))
		return (close(shdata->fd_oldpwd), -1);
	return (close(shdata->fd_oldpwd));
}
