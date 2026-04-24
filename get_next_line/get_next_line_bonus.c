/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:30:35 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/02 14:16:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE] = {{'\0'}};
	char		*newline;
	size_t		len_line;
	size_t		len_toadd;

	if (fd < 0 || fd > MAX_FD)
		return (NULL);
	newline = NULL;
	len_line = 0;
	while (1)
	{
		if (!buffer[fd][0] && read(fd, buffer[fd], BUFFER_SIZE) == -1)
		{
			if (newline)
				free(newline);
			return (NULL);
		}
		len_toadd = ft_count_endl(buffer[fd]);
		newline = ft_join(newline, len_line, buffer[fd], len_toadd);
		len_line += len_toadd;
		if (!newline || newline[len_line - 1] == '\n' || !len_toadd)
			break ;
	}
	return (newline);
}
