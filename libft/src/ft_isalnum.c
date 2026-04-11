/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:11:35 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 05:36:54 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isint(char *s)
{
	size_t	len;
	long	n;
	int		sign;

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (0);
	}
	while (ft_isspace(*s))
		s++;
	sign = (*s == '-');
	s += (*s == '+' || *s == '-');
	if (!(*s))
		return (0);
	len = 0;
	while (s[len])
	{
		if (!ft_isdigit(s[len]) || len == MAX_INT_LEN)
			return (0);
		len++;
	}
	n = ft_strtol(s - sign);
	return (len && !s[len] && INT_MIN <= n && n <= INT_MAX);
}
