/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldpwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/25 09:22:12 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	open_oldpwd(t_shdata *shdata)
{
	int		fd;

	fd = open(shdata->oldpwd_file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open "OLDPWD_FILE);
		return (-1);
	}
	return (fd);
}

int	close_oldpwd(int fd)
{
	if (close(fd) == -1)
	{
		perror("close "OLDPWD_FILE);
		return (-1);
	}
	return (0);
}

int	load_oldpwd(t_shdata *shdata)
{
	int		fd;

	expand_path(shdata->oldpwd_file, "HOME", OLDPWD_FILE);
	fd = open(shdata->oldpwd_file, O_RDONLY | O_CREAT, 0644);
	if (fd == -1)
		return (-1);
	return (fd);
}

int	save_oldpwd(char *oldpwd, int fd)
{
	if (write(fd, oldpwd, ft_strlen(oldpwd)) == -1)
	{
		perror("write oldpwd");
		return (-1);
	}
	return (0);
}
