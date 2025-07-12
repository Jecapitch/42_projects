/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/12 13:50:29 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	open_history(t_shdata *shdata, int oflag)
{
	shdata->fd_history = open(shdata->ptr_history_file, oflag, 0644);
	if (shdata->fd_history == -1)
		return (-1);
	return (0);
}

int	load_history(t_shdata *shdata)
{
	char	*line;

	line = NULL;
	expand_path(shdata->variables, shdata->ptr_history_file, \
				"HOME", HISTORY_FILE);
	shdata->history = ft_init_list();
	if (!shdata->history)
		return (-1);
	if (open_history(shdata, O_RDONLY | O_CREAT) == -1)
		return (-1);
	line = get_next_line(shdata->fd_history);
	while (line)
	{
		history_add(shdata, line);
		line = get_next_line(shdata->fd_history);
	}
	if (close(shdata->fd_history))
		return (-1);
	return (0);
}

char	*convert_nl(char *line)
{
	char	*res;
	char	*tmp;
	char	**split_nl;

	tmp = NULL;
	res = NULL;
	split_nl = NULL;
	split_nl = ft_split(line, '\n');
	if (!split_nl)
		return (NULL);
	while (*split_nl)
	{
		tmp = res;
		res = ft_strjoin_sep(res, *split_nl, "\\n");
		tmp = ft_free_safe(tmp);
		if (!res)
			break ;
		split_nl++;
	}
	ft_free_str_arr(split_nl);
	return (res);
}

int	history_add(t_shdata *shdata, char *line)
{
	size_t	size;
	char	*oneline;

	oneline = NULL;
	size = shdata->history_size;
	if (!line || !(*line))
		return (-1);
	if (shdata->history->last \
		&& ft_strncmp(line, (char *)shdata->history->last->content, \
						ft_strlen(line)) != 0)
	{
		add_history(line);
		oneline = convert_nl(line);
		if (!oneline)
			return (-1);
		ft_append(shdata->history, ft_newnode(oneline));
	}
	if (shdata->history->size > size)
		ft_listdelone(ft_dequeue(shdata->history), ft_free_nul);
	return (0);
}

int	save_history(t_shdata *shdata)
{
	t_node	*node;
	char	*line;

	node = NULL;
	line = NULL;
	if (open_history(shdata, O_WRONLY | O_CREAT | O_TRUNC))
		return (-1);
	node = shdata->history->first;
	while (node)
	{
		line = (char *)node->content;
		ft_fprintf(shdata->fd_history, "%s\n", line);
		node = node->next;
	}
	if (close(shdata->fd_history))
		return (-1);
	return (0);
}
