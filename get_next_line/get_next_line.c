/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 08:36:51 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/24 14:00:39 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE] = {'\0'};
	char		*newline;
	size_t		len_line;
	size_t		len_toadd;

	if (fd < 0 || fd > MAX_FD)
		return (NULL);
	newline = NULL;
	len_line = 0;
	while (1)
	{
		if (!buffer[0] && read(fd, buffer, BUFFER_SIZE) == -1)
		{
			if (newline)
				free(newline);
			return (NULL);
		}
		len_toadd = ft_count_endl(buffer);
		newline = ft_join(newline, len_line, buffer, len_toadd);
		len_line += len_toadd;
		if (!newline || newline[len_line - 1] == '\n' || !len_toadd)
			break ;
	}
	return (newline);
}
