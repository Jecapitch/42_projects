/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 13:41:40 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chs;
	unsigned char	ch;
	size_t			i;

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	i = 0;
	chs = (unsigned char *)s;
	ch = (unsigned char)c;
	while (i < n)
	{
		if (chs[i] == ch)
			return (chs + i);
		i++;
	}
	return (NULL);
}
