/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:36:03 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/25 21:04:26 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_pipes(t_pipe **pfd, size_t nbr_pipes)
{
	size_t	i;

	i = 0;
	*pfd = NULL;
	if (!nbr_pipes)
		return (0);
	*pfd = ft_calloc(nbr_pipes, sizeof(t_pipe));
	if (!(*pfd))
		return (perror("pipe malloc"), -1);
	ft_memset(*pfd, -1, nbr_pipes * sizeof(t_pipe));
	while (i < nbr_pipes)
	{
		if (pipe((*pfd)[i]) == -1)
			return (perror("open pipe"), close_all_fd(*pfd, i), \
					*pfd = ft_free_safe(*pfd), -1);
		i++;
	}
	return (0);
}

void	close_pipes(t_pipe *pfd, size_t index)
{
	if (!pfd)
		return ;
	close_if_isopen(pfd[index][0]);
	close_if_isopen(pfd[index][1]);
	pfd[index][0] = -1;
	pfd[index][1] = -1;
}

int	checkstatus(int status)
{
	int	sig;

	sig = 0;
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGQUIT)
			ft_printf("QUIT ");
		if (WCOREDUMP(status))
			ft_printf("(core dumped)");
		ft_printf("\n");
		return (sig + EX_INVALID);
	}
	return ((unsigned char)status);
}

int	wait_all_children(t_pipeline *pipeline, size_t n)
{
	size_t	i;

	i = 0;
	if (!pipeline->pids)
		return ((unsigned char)pipeline->exit_status);
	while (i < n)
	{
		if (pipeline->pids[i] != -1 \
			&& waitpid(pipeline->pids[i], &pipeline->exit_status, 0) == -1)
			perror("waitpid");
		pipeline->pids[i] = -1;
		i++;
	}
	pipeline->pids = ft_free_safe(pipeline->pids);
	pipeline->exit_status = (unsigned char)checkstatus(pipeline->exit_status);
	return (pipeline->exit_status);
}

int	dup_pipes(t_pipe *pfd, size_t index, size_t nbr_pipes)
{
	int	ret;

	ret = 0;
	if (!pfd || !nbr_pipes)
		return (0);
	if (index)
	{
		if (dup2(pfd[index - 1][0], STDIN_FILENO) == -1)
		{
			ret |= -1;
			perror("dup2 stdin");
		}
		close_if_isopen(pfd[index - 1][0]);
	}
	if (index < nbr_pipes)
	{
		if (dup2(pfd[index][1], STDOUT_FILENO) == -1)
		{
			ret |= -1;
			perror("dup2 stdout");
		}
		close_if_isopen(pfd[index][1]);
	}
	return (ret);
}
