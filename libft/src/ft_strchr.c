/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/11 20:38:35 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	target[2];

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	target[0] = c;
	target[1] = '\0';
	return (ft_strchr_set(s, target));
}

char	*ft_strchr_set(const char *s, char *set)
{
	if (!s || !set)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	while (*s)
	{
		if (ft_isset(*s, set))
			return ((char *)s);
		s++;
	}
	if (ft_isset(*s, set))
		return ((char *)s);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	target[2];

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	target[0] = c;
	target[1] = '\0';
	return (ft_strrchr_set(s, target));
}

char	*ft_strrchr_set(const char *s, char *set)
{
	char	*last_found;

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	last_found = NULL;
	while (*s)
	{
		if (ft_isset(*s, set))
			last_found = (char *)s;
		s++;
	}
	if (ft_isset(*s, set))
		last_found = (char *)s;
	return (last_found);
}
