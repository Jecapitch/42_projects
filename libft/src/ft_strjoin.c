/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:34:37 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 16:16:39 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	src_len = 0;
	if (dst)
		dst_len = ft_strlen(dst);
	if (src)
		src_len = ft_strlen(src);
	if (!dst || !src)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (dst_len + src_len);
	}
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	dst += dst_len;
	dstsize -= dst_len;
	ft_strlcpy(dst, src, dstsize);
	return (dst_len + src_len);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	return (ft_strjoin_sep(s1, s2, ""));
}

int	ft_strappend(char **dest, char *src)
{
	char	*newline;

	if (!dest)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (1);
	}
	newline = ft_strjoin(*dest, src);
	*dest = ft_free_safe(*dest);
	*dest = newline;
	return (*dest == NULL);
}

char	*ft_strjoin_sep(const char *s1, const char *s2, const char *sep)
{
	char	*join_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	sep_len;

	s1_len = 0;
	s2_len = 0;
	sep_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	if (s2)
		s2_len = ft_strlen(s2);
	if (sep)
		sep_len = ft_strlen(sep);
	join_str = ft_calloc(s1_len + s2_len + sep_len + 1, sizeof(char));
	if (!join_str)
		return (NULL);
	if (s1_len)
		ft_strlcpy(join_str, s1, s1_len + 1);
	if (s1_len && s2_len && sep_len)
		ft_strlcpy(join_str + s1_len, sep, sep_len + 1);
	if (s2_len)
		ft_strlcpy(join_str + s1_len + sep_len, s2, s2_len + 1);
	return (join_str);
}
