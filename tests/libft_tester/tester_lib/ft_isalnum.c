/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:11:35 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/16 16:49:38 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

int	tester_ft_isalnum(int c)
{
	return (tester_ft_isalpha(c) || tester_ft_isdigit(c));
}

int	tester_ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int	tester_ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	tester_ft_isint(const char *s, const char *base)
{
	size_t	len;
	long	n;
	int		sign;

	if (!s)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (0);
	}
	while (tester_ft_isspace(*s))
		s++;
	sign = (*s == '-');
	s += (*s == '+' || *s == '-');
	if (!(*s))
		return (0);
	len = 0;
	while (s[len])
	{
		if (!tester_ft_isdigit(s[len]) || len == MAX_INT_LEN)
			return (0);
		len++;
	}
	n = tester_ft_strtol(s - sign, base);
	return (len && !s[len] && INT_MIN <= n && n <= INT_MAX);
}
