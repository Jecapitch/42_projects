/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/18 00:50:44 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

char	*tester_ft_substr(const char *s, t_uint start, size_t len)
{
	if (!s)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	if (tester_ft_strlen(s) <= start)
		return (tester_ft_strdup(""));
	return (tester_ft_strldup(s + start, len));
}

char	*tester_ft_strtrim(const char *s, const char *set)
{
	char	*trimmed;
	size_t	len;

	len = 0;
	trimmed = NULL;
	if (!s || !set)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	if (!(*set))
		return (tester_ft_strdup(s));
	while (tester_ft_isset(*s, set))
		s++;
	len = tester_ft_strlen(s);
	while (len && tester_ft_isset(s[len - 1], set))
		len--;
	trimmed = tester_ft_substr(s, 0, len);
	return (trimmed);
}

char	*tester_ft_strstrip(const char *s)
{
	return (tester_ft_strtrim(s, " \n\t\r\v\f"));
}
