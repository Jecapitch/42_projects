/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:09:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/15 21:06:39 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <string.h>

/*
Environment is declared in header file, cf. man execve : "the use of a third
argument to the main function is not specified in POSIX.1; according to
POSIX.1, the environment should be accessed via the external variable 
environ(7)."
*/

int	main(int argc, char **argv)
{
	t_arg	args;
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		errno = -1;
		return (ft_fprintf(STDERR, "./pipex: number of arguments must be 4\n"), 1);
	}
	init(&args);
	arg_parse(argv, &args);
	if (pipe(pipe_fd) < 0)
		return (perror("pipe"), free_arg(&args), errno);
	pid1 = fork();
	fork_process(pid1, pipe_fd, 0, &args);
	pid2 = fork();
	fork_process(pid2, pipe_fd, 1, &args);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (close(pipe_fd[0]), close(pipe_fd[1]), \
				free_arg(&args), EXIT_SUCCESS);
}
