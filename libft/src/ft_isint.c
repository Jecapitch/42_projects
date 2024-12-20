/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:11:05 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/20 15:14:59 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *s)
{
	long	n;

	n = ft_strtol(s);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	while (ft_isspace(*s))
		s++;
	s += (*s == '+' || *s == '-');
	if (!(*s))
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}
