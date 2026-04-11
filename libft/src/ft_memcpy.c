/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/11 22:22:36 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*chsrc;
	unsigned char		*chdst;

	if (!dst || !src)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (dst);
	}
	if (src == dst)
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

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*chsrc;
	unsigned char		*chdst;

	if (!dst || !src)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (dst);
	}
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	chsrc = (const unsigned char *)src;
	chdst = (unsigned char *)dst;
	while (len--)
		chdst[len] = chsrc[len];
	return (dst);
}
