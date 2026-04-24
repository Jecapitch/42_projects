/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 19:11:49 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uchar	*chs;
	t_uchar	ch;
	size_t	i;

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	i = 0;
	chs = (t_uchar *)s;
	ch = (t_uchar)c;
	while (i < n)
	{
		if (chs[i] == ch)
			return (chs + i);
		i++;
	}
	return (NULL);
}
