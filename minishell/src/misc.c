/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:43:18 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 19:01:17 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shdata(t_shdata *shdata)
{
	ft_listclear(&shdata->history, ft_free_nul);
	ft_listclear_2(&shdata->variables, free_var);
	shdata->cmds = free_splitline(shdata->cmds);
	ft_free_str_arr(shdata->sh_environ);
	ft_free_str_arr(shdata->builtin);
	shdata->ptr_prompt = ft_free_safe(shdata->ptr_prompt);
	close_if_isopen(shdata->fd_history);
	close_if_isopen(shdata->stdinfd);
	close_if_isopen(shdata->stdoutfd);
	close_if_isopen(shdata->stderrfd);
	ft_bzero(shdata, sizeof(t_shdata));
}

void	free_cmd(void *cmd)
{
	t_cmd	*c;

	c = (t_cmd *)cmd;
	if (!c)
		return ;
	ft_listclear(&c->redirections, free_redir);
	c->cmdflag = free_splitline(c->cmdflag);
	ft_free_str_arr(c->argv);
	c->executable = ft_free_safe(c->executable);
	c = ft_free_safe(c);
	return ;
}

void	free_pipeline(t_pipeline *pipeline)
{
	if (pipeline)
	{
		ft_listclear(&pipeline->cmdlist, free_cmd);
		pipeline->pids = ft_free_safe(pipeline->pids);
		pipeline->pipeline = free_splitline(pipeline->pipeline);
		ft_bzero(pipeline, sizeof(t_pipeline));
	}
}

void	free_redir(void *redir_struct)
{
	t_redir	*redir;

	redir = (t_redir *)redir_struct;
	if (!redir)
		return ;
	close_if_isopen(redir->fd);
	if (redir->type & F_HEREDOC)
	{
		if (redir->name)
			unlink(redir->name);
		redir->name = ft_free_safe(redir->name);
	}
	redir = ft_free_safe(redir);
}

char	*expand_path(t_list_2 *var_list, char *to_expand, char *path_end)
{
	t_node_2	*node;

	node = NULL;
	node = search_var(var_list, to_expand);
	if (!node)
		return (ft_strdup(path_end));
	return (ft_strjoin_sep(get_var_val(node), path_end, "/"));
}
