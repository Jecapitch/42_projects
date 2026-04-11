/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/02 23:14:59 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*chsrc;
	unsigned char		*chdst;

	if (!dst || !src || !n)
		return (dst);
	chsrc = (const unsigned char *)src;
	chdst = (unsigned char *)dst;
	while (n > 0)
	{
		*chdst = *chsrc;
		chdst++;
		chsrc++;
		n--;
	}
	return (dst);
}
