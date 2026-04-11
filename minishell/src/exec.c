/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:36:03 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 20:03:10 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_fork(t_shdata *shdata, t_pipeline *pipeline, \
						t_cmd *cmd, t_pipe **pfd);
static int	exec_builtin(t_shdata *shdata, t_pipeline *pipeline, t_cmd *cmd);
static int	exec_cmd(t_cmd *cmd, t_shdata *shdata);
static void	exit_child(t_shdata *shdata, t_pipeline *pipeline, t_pipe **pfd);

static int	exec_builtin(t_shdata *shdata, t_pipeline *pipeline, t_cmd *cmd)
{
	if ((!cmd->ischild && redirect(cmd->redirections) == -1) || !cmd->argv)
		return (EX_FAILURE);
	if (ft_strncmp(cmd->executable, "cd", 3) == 0)
		return (bi_cd(shdata, cmd->argv));
	if (ft_strncmp(cmd->executable, "echo", 5) == 0)
		return (bi_echo(cmd->argv));
	if (ft_strncmp(cmd->executable, "env", 4) == 0)
		return (bi_env(shdata, cmd->argv));
	if (ft_strncmp(cmd->executable, "exit", 5) == 0)
		return (bi_exit(shdata, pipeline, cmd->argv, pipeline->exit_status));
	if (ft_strncmp(cmd->executable, "export", 7) == 0)
		return (bi_export(shdata, cmd->argv));
	if (ft_strncmp(cmd->executable, "pwd", 4) == 0)
		return (bi_pwd());
	if (ft_strncmp(cmd->executable, "unset", 6) == 0)
		return (bi_unset(shdata, cmd->argv));
	return (EX_NOTFOUND);
}

static int	exec_cmd(t_cmd *cmd, t_shdata *shdata)
{
	int	exit_status;

	exit_status = EX_SUCCESS;
	if (!cmd->executable)
		return (exit_status);
	exit_status = is_valid_exec(cmd->executable, *cmd->argv);
	if (!exit_status)
	{
		execve(cmd->executable, cmd->argv, shdata->sh_environ);
		perror("execve");
	}
	return (exit_status);
}

static void	exit_child(t_shdata *shdata, t_pipeline *pipeline, t_pipe **pfd)
{
	int	status;

	status = pipeline->exit_status;
	close_all_fd(*pfd, pipeline->nbr_pipes);
	free_pipeline(pipeline);
	*pfd = ft_free_safe(*pfd);
	end_program(shdata);
	exit(status);
}

static void	exec_fork(t_shdata *shdata, t_pipeline *pipeline, \
						t_cmd *cmd, t_pipe **pfd)
{
	close_if_isopen(shdata->stderrfd);
	close_if_isopen(shdata->stdoutfd);
	close_if_isopen(shdata->stdinfd);
	set_sigquit_handler(SIG_DFL);
	set_sigint_handler(SIG_DFL);
	if (dup_pipes(*pfd, cmd->index, pipeline->nbr_pipes) \
			|| redirect(cmd->redirections))
		exit_child(shdata, pipeline, pfd);
	close_all_fd(*pfd, pipeline->nbr_pipes);
	if (cmd->isbuiltin)
		pipeline->exit_status = exec_builtin(shdata, pipeline, cmd);
	else
		pipeline->exit_status = exec_cmd(cmd, shdata);
}

int	execute(t_shdata *shdata, t_pipeline *pipeline, t_cmd *cmd, t_pipe **pfd)
{
	if (!cmd->ischild)
		return (exec_builtin(shdata, pipeline, cmd));
	cmd->pid = fork();
	if (cmd->pid == -1)
		return (perror("fork"), 1);
	if (cmd->pid == 0)
	{
		exec_fork(shdata, pipeline, cmd, pfd);
		exit_child(shdata, pipeline, pfd);
	}
	pipeline->pids[cmd->index] = cmd->pid;
	if (cmd->index)
		close_if_isopen((*pfd)[cmd->index - 1][0]);
	if (cmd->index < pipeline->nbr_pipes)
		close_if_isopen((*pfd)[cmd->index][1]);
	return (pipeline->exit_status);
}
