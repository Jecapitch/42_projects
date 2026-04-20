/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_cpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/16 11:09:50 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

void	*tester_ft_memcpy(void *dst, const void *src, size_t n)
{
	const t_uchar	*chsrc;
	t_uchar			*chdst;

	if (!dst || !src)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (dst);
	}
	if (src == dst)
		return (dst);
	chsrc = (const t_uchar *)src;
	chdst = (t_uchar *)dst;
	while (n > 0)
	{
		*chdst = *chsrc;
		chdst++;
		chsrc++;
		n--;
	}
	return (dst);
}

void	*tester_ft_memmove(void *dst, const void *src, size_t len)
{
	const t_uchar	*chsrc;
	t_uchar			*chdst;

	if (!dst || !src)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (dst);
	}
	if (src > dst)
		return (tester_ft_memcpy(dst, src, len));
	chsrc = (const t_uchar *)src;
	chdst = (t_uchar *)dst;
	while (len--)
		chdst[len] = chsrc[len];
	return (dst);
}

size_t	tester_ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = 0;
	if (src)
		src_len = tester_ft_strlen(src);
	if (!dst || !src)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (src_len);
	}
	if (!dstsize)
		return (src_len);
	if (src_len + 1 < dstsize)
		dstsize = src_len + 1;
	dst[dstsize - 1] = '\0';
	tester_ft_memmove(dst, src, dstsize - 1);
	return (src_len);
}

char	*tester_ft_strdup(const char *s)
{
	if (!s)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	return (tester_ft_strldup(s, tester_ft_strlen(s)));
}

char	*tester_ft_strldup(const char *s, size_t len)
{
	char	*dup;

	if (!s)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	dup = tester_ft_calloc(len + 1, sizeof(char));
	if (!dup)
		return (NULL);
	tester_ft_strlcpy(dup, s, len + 1);
	return (dup);
}
