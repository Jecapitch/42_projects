/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 02:03:33 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 14:25:53 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_redir(t_flag flag)
{
	if (flag & (F_IN_REDIR | F_HEREDOC | F_OUT_REDIR | F_OUT_APPEND))
		return (1);
	return (0);
}

int	open_redir_file(t_redir *redir)
{
	if (redir->type & F_OUT_REDIR)
		redir->fd = open(redir->name, OUT_OPEN, 0644);
	else if (redir->type & F_OUT_APPEND)
		redir->fd = open(redir->name, APP_OPEN, 0644);
	else
		redir->fd = open(redir->name, IN_OPEN);
	if (redir->fd == -1)
		return (perror(NAME), 1);
	return (0);
}

int	dup_redir(t_redir *redir)
{
	if (redir->type & (F_IN_REDIR | F_HEREDOC) \
			&& dup2(redir->fd, STDIN_FILENO) == -1)
		return (perror("dup2 stdin"), 1);
	if (redir->type & (F_OUT_REDIR | F_OUT_APPEND) \
			&& dup2(redir->fd, STDOUT_FILENO) == -1)
		return (perror("dup2 stdout"), 1);
	close_if_isopen(redir->fd);
	return (0);
}

int	redirect(t_list *redir)
{
	t_node	*node;

	node = NULL;
	if (!redir || !redir->size)
		return (0);
	node = redir->first;
	while (node)
	{
		if (!node->content \
				|| open_redir_file(node->content) \
				|| dup_redir(node->content))
			return (1);
		node = node->next;
	}
	return (0);
}

int	add_redir(t_shdata *shdata, t_cmd *cmd, size_t index)
{
	t_redir	*redir;
	t_node	*node;

	redir = ft_calloc(1, sizeof(t_redir));
	node = ft_newnode(redir);
	if (!redir || !node)
		return (ft_listdelone(node, free_redir), 1);
	redir->isquoted = (ft_strchr_set(cmd->cmdflag[index]->line, "\"'") \
						!= NULL);
	redir->type = *cmd->cmdflag[index]->flags;
	expand_arg_rm_quote(shdata, cmd->cmdflag, index);
	redir->name = cmd->cmdflag[index]->line;
	if (redir->type & F_HEREDOC)
	{
		redir->delim = cmd->cmdflag[index]->line;
		if (!name_heredoc(redir) || prepare_heredoc(shdata, redir))
			return (ft_listdelone(node, free_redir), 1);
	}
	ft_append(cmd->redirections, node);
	return (0);
}
