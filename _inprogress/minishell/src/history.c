/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 01:07:37 by jpiscice         ###   ########.fr       */
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
	expand_path(shdata->environ, shdata->ptr_history_file, \
				"HOME", HISTORY_FILE);
	shdata->history = ft_init_list();
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

int	history_add(t_shdata *shdata, char *line)
{
	size_t	size;

	size = ft_strtol(get_var_val(search_var("HISTSIZE", shdata->history)));
	if (!line || !*line)
		return (-1);
	add_history(line);
	ft_append(shdata->history, ft_newnode(line));
	if (shdata->history->size > size)
		ft_listdelone(ft_dequeue(shdata->history), (void (*))ft_free_nul);
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
