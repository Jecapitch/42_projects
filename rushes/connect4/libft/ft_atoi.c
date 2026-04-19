/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:11:46 by nthys             #+#    #+#             */
/*   Updated: 2025/10/16 16:11:46 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *nptr)
{
	long	number;
	char	minus;

	minus = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	if (*nptr && *nptr == '+')
		nptr++;
	else if (*nptr == '-')
	{
		nptr++;
		minus = -1;
	}
	number = 0;
	while (ft_isdigit(*nptr))
	{
		if (number * minus > LONG_MAX / 10)
			return (-1);
		if (number * minus < LONG_MIN / 10)
			return (0);
		number = number * 10 + *nptr++ - '0';
	}
	return (number * minus);
}
