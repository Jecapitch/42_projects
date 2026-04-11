/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/11 21:26:52 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (0);
	}
	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlen_delim(const char *s, const char delim)
{
	char	target[2];

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (0);
	}
	target[0] = delim;
	target[1] = '\0';
	return (ft_strlen_delim_set(s, target));
}

size_t	ft_strlen_delim_set(const char *s, const char *delim_set)
{
	size_t	len;

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (0);
	}
	len = 0;
	while (s[len] && !ft_isset(s[len], delim_set))
		len++;
	return (len);
}

size_t	ft_strlen_condition(const char *s, int (*f)(int))
{
	size_t	len;

	if (!s || !f)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (0);
	}
	len = 0;
	while (s[len] && f(s[len]))
		len++;
	return (len);
}
