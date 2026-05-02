/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 19:26:59 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = 0;
	if (src)
		src_len = ft_strlen(src);
	if (!dst || !src)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (src_len);
	}
	if (!dstsize)
		return (src_len);
	if (src_len + 1 < dstsize)
		dstsize = src_len + 1;
	dst[dstsize - 1] = '\0';
	ft_memmove(dst, src, dstsize - 1);
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	return (ft_strldup(s, ft_strlen(s)));
}

char	*ft_strldup(const char *s, size_t len)
{
	char	*dup;

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	dup = ft_calloc(len + 1, sizeof(char));
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, len + 1);
	return (dup);
}

char	*ft_substr(const char *s, t_uint start, size_t len)
{
	size_t	slen;

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	s += start;
	slen -= start;
	if (len > slen)
		len = slen;
	return (ft_strldup(s, len));
}
