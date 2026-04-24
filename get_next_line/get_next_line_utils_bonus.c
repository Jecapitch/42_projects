/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 08:36:51 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/24 14:02:30 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_count_endl(char buffer[])
{
	size_t	len;

	len = 0;
	while (len < BUFFER_SIZE && buffer[len] && buffer[len] != '\n')
		len++;
	if (len < BUFFER_SIZE && buffer[len] == '\n')
		len++;
	return (len);
}

void	ft_copy(char *dst, char *src, size_t len)
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

char	*ft_join(char *s1, size_t len_s1, char buffer[], size_t len_toadd)
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
