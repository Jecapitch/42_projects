/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:09:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/16 18:50:30 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	process(int pipe_fd[2], int pipe_end, t_arg *args);
static int	openfd(char *file, int mode);

static int	openfd(char *file, int mode)
{
	int	fd;

	if (mode == O_RDONLY)
		fd = open(file, mode, 0444);
	else
		fd = open(file, mode, 0644);
	if (fd == -1)
		perror(file);
	return (fd);
}

void	fork_process(pid_t pid, int pipe_fd[2], int pipe_end, t_arg *args)
{
	if (pid < 0)
	{
		perror("fork");
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		free_arg(args);
		exit(EXIT_FAILURE);
	}
	if (!pid)
		process(pipe_fd, pipe_end, args);
	close(pipe_fd[!pipe_end]);
}

static void	process(int pipe_fd[2], int pipe_end, t_arg *args)
{
	int		fd;
	int		open_end;
	char	*file;
	char	**cmd;
	char	*path;

	close(pipe_fd[pipe_end]);
	open_end = !pipe_end;
	file = open_end * (args->infile - args->outfile) + args->outfile;
	fd = openfd(file, open_end * O_RDONLY \
		+ !open_end * (O_WRONLY | O_CREAT | O_TRUNC));
	if (fd == -1 || dup2(pipe_fd[open_end], open_end) == -1 \
			|| dup2(fd, pipe_end) == -1)
		return (perror("fd"), close(pipe_fd[open_end]), close(fd), \
				free_arg(args), exit(EXIT_FAILURE));
	close(pipe_fd[open_end]);
	close(fd);
	path = open_end * (args->path1 - args->path2) + args->path2;
	cmd = open_end * (args->cmd1 - args->cmd2) + args->cmd2;
	if (execve(path, cmd, environ) == -1)
		return (perror("execve"), free_arg(args), exit(EXIT_FAILURE));
	exit(EXIT_SUCCESS);
}
