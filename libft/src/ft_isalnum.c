/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:11:35 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 19:34:12 by jepiscic         ###   ########.fr       */
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

int	ft_isnum(const char *s)
{
	while (ft_isspace(*s))
		s++;
	s += (*s == '+' || *s == '-');
	while (ft_isdigit(*s))
		s++;
	return (!(*s));
}

int	ft_isint(const char *s)
{
	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (0);
	}
	return (ft_isnum(s) && ft_atoi(s) == ft_strtol(s, BASE10));
}
