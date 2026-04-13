/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:39:49 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 12:35:43 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(const char *base, int base_hash[256]);

int	ft_atoi(const char *s)
{
	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (0);
	}
	return (ft_strtol(s, BASE10));
}

static int	check_base(const char *base, int base_hash[256])
{
	int		b;
	t_uchar	c;

	b = 0;
	while (b < 256)
		base_hash[b++] = -1;
	b = 0;
	while (base[b])
	{
		c = (t_uchar)base[b];
		if (base_hash[c] != -1 || c == '+' || c == '-' || ft_isspace(c))
			return (0);
		base_hash[c] = b;
		b++;
	}
	return (b);
}

long	ft_strtol(const char *s, const char *base)
{
	long	n;
	int		sign;
	int		rad;
	int		base_hash[256];

	if (!s || !base)
		return (ft_err_nonnull(NULL, -1, __func__), 0);
	n = 0;
	sign = 1;
	rad = check_base(base, base_hash);
	if (rad < 2)
		return (0);
	while (ft_isspace(*s))
		s++;
	if (*s == '-')
		sign *= -1;
	s += (*s == '+' || *s == '-');
	while (base_hash[(int)*s] != -1)
	{
		n *= rad;
		n += base_hash[(int)*s];
		s++;
	}
	return (n * sign);
}

t_ulong	ft_strtoul(const char *s, const char *base)
{
	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (0);
	}
	return (ft_strtol(s, base));
}
