/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 13:12:51 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_history(t_shdata *shdata, int oflag)
{
	shdata->fd_history = open(shdata->ptr_history_file, oflag, 0644);
	if (shdata->fd_history == -1)
		return (-1);
	return (0);
}

int	history_close_quotes(t_shdata *shdata, char **line)
{
	char	*next_line;
	size_t	len;
	t_line	line_struct;

	next_line = NULL;
	len = ft_strlen(*line);
	ft_bzero(&line_struct, sizeof(t_line));
	line_struct.line = *line;
	while (check_quotes(&line_struct, len))
	{
		next_line = get_next_line(shdata->fd_history);
		if (!next_line)
			break ;
		ft_strappend(line, next_line);
		next_line = ft_free_safe(next_line);
		if (!(*line))
			return (perror("history"), 1);
		len = ft_strlen(*line);
		line_struct.line = *line;
	}
	history_add(shdata, *line);
	line = ft_free_safe(*line);
	return (0);
}

int	load_history(t_shdata *shdata)
{
	char	*line;
	char	*histvar;
	char	*histfile;

	line = NULL;
	histfile = expand_path(shdata->variables, "HOME", HISTORY_FILE);
	histvar = ft_strjoin("HISTFILE=", histfile);
	if (!histfile || !histvar || set_var(shdata, histvar, 0) == -1 \
		|| set_var(shdata, "HISTSIZE="HISTORY_SIZE, 0) == -1)
		return (histfile = ft_free_safe(histfile), \
				histvar = ft_free_safe(histvar), -1);
	histvar = ft_free_safe(histvar);
	histfile = ft_free_safe(histfile);
	shdata->history = ft_init_list();
	if (!shdata->history || open_history(shdata, O_RDONLY | O_CREAT) == -1)
		return (1);
	line = get_next_line(shdata->fd_history);
	while (line)
	{
		if (history_close_quotes(shdata, &line))
			return (1);
		line = get_next_line(shdata->fd_history);
	}
	close_if_isopen(shdata->fd_history);
	return (0);
}

int	history_add(t_shdata *shdata, char *line)
{
	size_t	len;
	char	*linecpy;

	linecpy = NULL;
	len = ft_strlen(line);
	if (!line || !(*line))
		return (0);
	if (line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len--;
	}
	if (!len || (shdata->history && shdata->history->size \
		&& ft_strncmp(line, (char *)shdata->history->last->content, len) == 0))
		return (-1);
	linecpy = ft_strdup(line);
	if (!linecpy)
		return (-1);
	add_history(linecpy);
	ft_append(shdata->history, ft_newnode(linecpy));
	if (shdata->history->size > shdata->history_size)
		ft_listdelone(ft_dequeue(shdata->history), ft_free_nul);
	return (0);
}

int	save_history(t_shdata *shdata)
{
	t_node	*node;

	node = NULL;
	if (open_history(shdata, O_WRONLY | O_CREAT | O_TRUNC))
		return (-1);
	node = shdata->history->first;
	while (node)
	{
		ft_fprintf(shdata->fd_history, "%s\n", (char *)node->content);
		node = node->next;
	}
	if (close_if_isopen(shdata->fd_history))
		return (-1);
	return (0);
}
