/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:46:33 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 20:57:07 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	cmd_is_builtin(char *cmd, char **builtin);
static int	add_arg(t_shdata *shdata, t_cmd *cmd, size_t i, size_t *j);

int	make_struct_cmd(t_shdata *shdata, t_pipeline *pipeline, \
					t_cmd *cmd, size_t index)
{
	size_t	i;
	t_line	*line;

	line = pipeline->pipeline[index];
	i = 0;
	if (!cmd || !line || !line->line || !line->flags)
		return (EX_FAILURE);
	cmd->ischild |= (pipeline->nbr_pipes != 0);
	cmd->cmdflag = split_line(line, F_SPACE);
	cmd->redirections = ft_init_list();
	cmd->index = index;
	if (!cmd->cmdflag || !cmd->redirections)
		return (EX_FAILURE);
	while (cmd->cmdflag[i])
	{
		if (!is_redir(*cmd->cmdflag[i]->flags))
			cmd->argc++;
		i++;
	}
	if (get_cmd_args(shdata, cmd) || get_command_bin_path(cmd))
		return (free_cmd(cmd), EX_FAILURE);
	return (EX_SUCCESS);
}

void	expand_arg_rm_quote(t_shdata *shdata, t_line **arg, size_t index)
{
	if (!(*arg[index]->flags & F_HEREDOC))
		arg[index]->line = expand_variable(shdata, arg[index]);
	remove_quotes(arg[index]);
}

static int	add_arg(t_shdata *shdata, t_cmd *cmd, size_t i, size_t *j)
{
	t_line	**arg;
	size_t	k;

	expand_arg_rm_quote(shdata, cmd->cmdflag, i);
	arg = split_line(cmd->cmdflag[i], F_SPACE);
	if (!arg)
		return (EX_FAILURE);
	k = get_pipe_nbr(arg) + 1;
	cmd->argv = ft_realloc(cmd->argv, cmd->argc * sizeof(char *), \
							(cmd->argc + k + 1) * sizeof(char *));
	if (!cmd->argv)
		return (free_splitline(arg), EX_FAILURE);
	cmd->argc += k - 1;
	k = 0;
	while (arg[k])
	{
		cmd->argv[*j] = ft_strdup(arg[k]->line);
		if (!cmd->argv[*j])
			return (free_splitline(arg), EX_FAILURE);
		++*j;
		k++;
	}
	free_splitline(arg);
	return (EX_SUCCESS);
}

int	get_cmd_args(t_shdata *shdata, t_cmd *cmd)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!cmd || !cmd->cmdflag)
		return (EX_FAILURE);
	cmd->argv = ft_calloc(cmd->argc + 1, sizeof(char *));
	if (!cmd->argv)
		return (EX_FAILURE);
	while (cmd->cmdflag[i])
	{
		if (!is_redir(*cmd->cmdflag[i]->flags))
		{
			if (add_arg(shdata, cmd, i, &j))
				return (EX_FAILURE);
		}
		else if (add_redir(shdata, cmd, i))
			return (EX_FAILURE);
		i++;
	}
	cmd->isbuiltin = cmd_is_builtin(*cmd->argv, shdata->builtin);
	cmd->ischild |= !cmd->isbuiltin;
	return (EX_SUCCESS);
}

static int	cmd_is_builtin(char *cmd, char **builtin)
{
	if (!cmd || !builtin)
		return (0);
	while (*builtin)
	{
		if (ft_strncmp(*builtin, cmd, ft_strlen(*builtin) + 1) == 0)
			return (1);
		builtin++;
	}
	return (0);
}
