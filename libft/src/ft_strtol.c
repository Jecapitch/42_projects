/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:39:49 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/20 14:51:18 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_strtol(const char *str)
{
	long	n;
	int		sign;

	n = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		n = n * 10 + *str - '0';
		str++;
	}
	return (n * sign);
}
