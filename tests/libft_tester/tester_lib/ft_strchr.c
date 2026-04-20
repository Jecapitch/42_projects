/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/14 23:50:11 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

char	*tester_ft_strchr(const char *s, int c)
{
	char	target[2];

	if (!s)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	target[0] = c;
	target[1] = '\0';
	return (tester_ft_strchr_set(s, target));
}

char	*tester_ft_strchr_set(const char *s, char *set)
{
	if (!s || !set)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	if (!(*set))
		return ((char *)s + tester_ft_strlen(s));
	while (*s)
	{
		if (tester_ft_isset(*s, set))
			return ((char *)s);
		s++;
	}
	if (tester_ft_isset(*s, set))
		return ((char *)s);
	return (NULL);
}

char	*tester_ft_strrchr(const char *s, int c)
{
	char	target[2];

	if (!s)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	target[0] = c;
	target[1] = '\0';
	return (tester_ft_strrchr_set(s, target));
}

char	*tester_ft_strrchr_set(const char *s, char *set)
{
	char	*last_found;

	if (!s)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	if (!(*set))
		return ((char *)s + tester_ft_strlen(s));
	last_found = NULL;
	while (*s)
	{
		if (tester_ft_isset(*s, set))
			last_found = (char *)s;
		s++;
	}
	if (tester_ft_isset(*s, set))
		last_found = (char *)s;
	return (last_found);
}

char	*tester_ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	neelen;

	if (!haystack || !needle)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	neelen = tester_ft_strlen(needle);
	if (!neelen)
		return ((char *)haystack);
	while (*haystack && len >= neelen)
	{
		if (tester_ft_strncmp(haystack, needle, neelen) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
