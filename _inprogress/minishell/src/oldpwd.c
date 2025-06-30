/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldpwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 13:41:19 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	open_oldpwd(t_shdata *shdata, int oflag)
{
	shdata->fd_oldpwd = open(shdata->ptr_oldpwd_file, oflag, 0644);
	if (shdata->fd_history == -1)
		return (-1);
	return (0);
}

int	load_oldpwd(t_shdata *shdata)
{
	char	*line;
	char	*oldpwd;
	char	*mark;
	size_t	len;

	line = NULL;
	if (expand_path(shdata->environ, shdata->ptr_oldpwd_file, \
					"HOME", OLDPWD_FILE) == -1 \
		|| open_oldpwd(shdata, O_RDONLY | O_CREAT) == -1)
		return (-1);
	oldpwd = get_next_line(shdata->fd_oldpwd);
	line = ft_strjoin_sep("OLDPWD", oldpwd, "=");
	ft_free_nul(oldpwd);
	export_var(shdata, shdata->environ, line);
	ft_free_nul(line);
	return (close(shdata->fd_oldpwd));
}

int	save_oldpwd(t_shdata *shdata)
{
	if (open_oldpwd(shdata, O_WRONLY | O_CREAT | O_TRUNC) == -1)
		return (-1);
	if (ft_fprintf(shdata->fd_oldpwd, "%s\n", shdata->ptr_cwd))
		return (close(shdata->fd_oldpwd), -1);
	return (close(shdata->fd_oldpwd));
}
