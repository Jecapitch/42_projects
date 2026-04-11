/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:46:33 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 19:06:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		init_pipeline_data(t_pipeline *pipeline, t_line *line);

static int	init_pipeline_data(t_pipeline *pipeline, t_line *line)
{
	pipeline->pipeline = split_line(line, F_PIPE);
	pipeline->cmdlist = ft_init_list();
	pipeline->nbr_pipes = get_pipe_nbr(pipeline->pipeline);
	pipeline->pids = ft_calloc(pipeline->nbr_pipes + 1, sizeof(pid_t));
	if (!pipeline->pipeline || !pipeline->pids || !pipeline->cmdlist)
		return (free_pipeline(pipeline), \
				EX_FAILURE);
	ft_memset(pipeline->pids, -1, (pipeline->nbr_pipes + 1) * sizeof(pid_t));
	return (EX_SUCCESS);
}

int	prepare_cmds(t_shdata *shdata, t_pipeline *pipeline, t_line *line)
{
	t_cmd	*cmd;
	size_t	i;

	i = 0;
	cmd = NULL;
	if (init_pipeline_data(pipeline, line))
		return (perror("init pipeline"), \
				EX_FAILURE);
	while (i < pipeline->nbr_pipes + 1)
	{
		cmd = ft_calloc(1, sizeof(t_cmd));
		if (!cmd)
			return (perror("prepare commands: ft_calloc"), \
					(EX_FAILURE));
		if (make_struct_cmd(shdata, pipeline, cmd, i))
			return (perror("make_struct_cmd"), \
					(EX_FAILURE));
		ft_append(pipeline->cmdlist, ft_newnode(cmd));
		i++;
	}
	return (EX_SUCCESS);
}

int	execute_cmds(t_shdata *shdata, t_pipeline *pipeline)
{
	t_pipe	*pfd;
	t_node	*node;
	t_cmd	*cmd;

	pfd = NULL;
	node = NULL;
	cmd = NULL;
	if (!pipeline || pipeline->exit_status)
		return (EX_FAILURE);
	if (open_pipes(&pfd, pipeline->nbr_pipes) == -1)
		return (EX_FAILURE);
	node = pipeline->cmdlist->first;
	while (node)
	{
		cmd = (t_cmd *)node->content;
		pipeline->exit_status = execute(shdata, pipeline, cmd, &pfd);
		set_exit_var(shdata, pipeline->exit_status);
		reset_std(shdata);
		node = node->next;
	}
	wait_all_children(pipeline, pipeline->nbr_pipes + 1);
	set_exit_var(shdata, pipeline->exit_status);
	close_all_fd(pfd, pipeline->nbr_pipes);
	pfd = ft_free_safe(pfd);
	return (pipeline->exit_status);
}

int	process_cmds(t_shdata *shdata, t_line *line)
{
	size_t		i;
	t_pipeline	pipeline;

	i = 0;
	ft_bzero(&pipeline, sizeof(t_pipeline));
	if (!line || !line->line)
		return (1);
	shdata->cmds = split_line(line, F_SEMICOLON);
	free_cmdline(line);
	if (!shdata->cmds)
		return (1);
	while (shdata->cmds[i])
	{
		if (flag_line(shdata->cmds[i]) == -1)
			return (ft_fprintf(STDERR_FILENO, NAME": parse error\n"), \
					shdata->cmds = free_splitline(shdata->cmds), 1);
		if (prepare_cmds(shdata, &pipeline, shdata->cmds[i]))
			return (free_pipeline(&pipeline), \
					shdata->cmds = free_splitline(shdata->cmds), 1);
		set_exit_var(shdata, execute_cmds(shdata, &pipeline));
		free_pipeline(&pipeline);
		i++;
	}
	shdata->cmds = free_splitline(shdata->cmds);
	return (0);
}

size_t	get_pipe_nbr(t_line **pipeline)
{
	size_t	size;

	size = 0;
	if (!pipeline)
		return (0);
	while (pipeline[size])
		size++;
	if (size)
		size--;
	return (size);
}
