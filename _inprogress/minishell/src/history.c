/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/25 14:11:05 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	open_history(t_shdata *shdata)
{
	int		fd;

	expand_path(shdata->history_file, "HOME", HISTORY_FILE);
	fd = open(shdata->history_file, O_RDWR | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("open "HISTORY_FILE);
		return (-1);
	}
	return (fd);
}

int	close_history(int fd)
{
	if (close(fd) == -1)
	{
		perror("close "HISTORY_FILE);
		return (-1);
	}
	return (0);
}

int	load_history(t_shdata *shdata)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open_history(shdata);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		add_history(line);
		ft_free_nul(line);
		line = get_next_line(fd);
	}
	return (fd);
}

int	save_history(char *line, int fd)
{
	if (!line && !*line)
		return (0);
	add_history(line);
	return (ft_fprintf(fd, "%s\n", line));
}
