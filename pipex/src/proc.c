/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:09:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/03/27 23:47:45 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static int	openfd(char *file, int mode)
{
	int	res;

	if (mode == O_RDONLY)
		res = open(file, mode, 0444);
	else
		res = open(file, mode, 0666);
	if (res == -1)
		perror(file);
	return (res);
}

void	process(pid_t pid, int pipe_fd[2], t_arg *args)
{
	int		fd;
	char	*file;
	char	**cmd;
	char	*path;
	int		ischild;

	ischild = (pid == 0);
	close(pipe_fd[!ischild]);
	if (!ischild)
		wait(NULL);
	file = ischild * (args->infile - args->outfile) + args->outfile;
	fd = openfd(file, ischild * O_RDONLY \
		+ !ischild * (O_WRONLY | O_CREAT | O_TRUNC));
	if (fd == -1 || dup2(pipe_fd[ischild], ischild) == -1 \
			|| dup2(fd, !ischild) == -1)
		return (perror("fd"), close(pipe_fd[ischild]), close(fd), \
				free_arg(args), exit(errno));
	close(pipe_fd[ischild]);
	close(fd);
	path = ischild * (args->path1 - args->path2) + args->path2;
	cmd = ischild * (args->cmd1 - args->cmd2) + args->cmd2;
	if (execve(path, cmd, environ) == -1)
		return (free_arg(args), exit(errno));
}
