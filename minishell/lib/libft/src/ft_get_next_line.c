/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:30:35 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/07 23:27:44 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_count_endl(char buffer[])
{
	size_t	len;

	len = 0;
	while (len < BUFFER_SIZE && buffer[len] && buffer[len] != '\n')
		len++;
	if (len < BUFFER_SIZE && buffer[len] == '\n')
		len++;
	return (len);
}

static void	ft_copy(char *dst, char *src, size_t len)
{
	size_t	i;

	if (!dst || !src || !len)
		return ;
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		src[i] = '\0';
		i++;
	}
	dst[i] = '\0';
}

static char	*ft_join(char *s1, size_t len_s1, char buffer[], size_t len_toadd)
{
	char	*newstr;

	if (!s1 && !buffer[0])
		return (NULL);
	if (!buffer[0])
		return (s1);
	newstr = malloc((len_s1 + len_toadd + 1) * sizeof(char));
	if (!newstr)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	ft_copy(newstr, s1, len_s1);
	if (s1)
		free(s1);
	ft_copy(newstr + len_s1, buffer, len_toadd);
	ft_copy(buffer, buffer + len_toadd, BUFFER_SIZE - len_toadd);
	return (newstr);
}

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
