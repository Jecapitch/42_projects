/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 00:32:24 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/02 19:14:17 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"

double	ft_ln_taylor(double x)
{
	double	result;
	double	power;
	int		n;
	size_t	i;

	if (x <= -1 || x > 1)
		return (0);
	result = 0;
	power = x;
	n = 1;
	i = 1;
	while (i <= 15)
	{
		result += power / n;
		power *= -x;
		n++;
		i++;
	}
	return (result);
}
#include <stdio.h>
double	ft_log10(double x)
{
	int	power;

	if (x <= 0)
		return (0);
	power = ft_powerof10(x);
	x /= ft_power(10, power);
	printf("%f %d\n", x, power);
	return (power + ft_ln(x) / LN10);
}


double	ft_ln(double x)
{
	double	power;
	double	res;
	int		n;

	power = x;
	res = 0.0;
	n = 1;
	while (n <= 25)
	{
		if (n % 2 == 1)
			res += power / n;
		else
			res -= power / n;
		power *= x;
		n++;
	}
	return (res);
}
