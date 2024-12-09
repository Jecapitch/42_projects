/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/04 16:23:32 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chs;
	unsigned char	ch;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	chs = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (chs[i] == ch)
			return ((void *)&chs[i]);
		i++;
	}
	return (NULL);
}
