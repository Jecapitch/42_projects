/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:46:01 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/20 16:51:43 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	isopen(int fd)
{
	struct stat	st;
	int			tmp;

	tmp = errno;
	if (fd == -1)
		return (0);
	if (fstat(fd, &st) == -1)
	{
		if (errno == EBADF)
			errno = tmp;
		return (0);
	}
	return (1);
}

int	close_if_isopen(int fd)
{
	if (fd > 2 && isopen(fd))
		return (close(fd));
	return (0);
}

int	close_all_fd(t_pipe *pfd, size_t size)
{
	size_t	i;
	int		ret;

	i = 0;
	ret = 0;
	if (!pfd)
		return (0);
	while (i < size)
	{
		ret |= close_if_isopen((pfd)[i][0]);
		ret |= close_if_isopen((pfd)[i][1]);
		i++;
	}
	return (ret);
}

int	dup_std(t_shdata *shdata)
{
	int	ret;

	ret = 0;
	shdata->stdinfd = dup(STDIN_FILENO);
	ret |= shdata->stdinfd;
	if (shdata->stdinfd == -1)
		perror("dup stdin");
	shdata->stdoutfd = dup(STDOUT_FILENO);
	ret |= shdata->stdoutfd;
	if (shdata->stdoutfd == -1)
		perror("dup stdout");
	shdata->stderrfd = dup(STDERR_FILENO);
	ret |= shdata->stderrfd;
	if (shdata->stderrfd == -1)
		perror("dup stderr");
	return (ret);
}

int	reset_std(t_shdata *shdata)
{
	int	ret;

	ret = 0;
	if (dup2(shdata->stdinfd, STDIN_FILENO) == -1)
	{
		ret |= -1;
		perror("dup2 stdin");
	}
	close(shdata->stdinfd);
	if (dup2(shdata->stdoutfd, STDOUT_FILENO) == -1)
	{
		ret |= -1;
		perror("dup2 stdout");
	}
	close(shdata->stdoutfd);
	if (dup2(shdata->stderrfd, STDERR_FILENO) == -1)
	{
		ret |= -1;
		perror("dup2 stderr");
	}
	close(shdata->stderrfd);
	ret |= dup_std(shdata);
	return (ret);
}
