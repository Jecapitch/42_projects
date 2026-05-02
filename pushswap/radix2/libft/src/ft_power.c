/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:03:08 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 03:45:07 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"

int	ft_power_int(int n, int pow)
{
	return (ft_power(n, pow));
}

double	ft_power(double n, int pow)
{
	double	res;

	if (!n)
		return (0);
	if (n == 1 || !pow)
		return (1);
	if (pow < 0)
	{
		n = 1 / n;
		pow *= -1;
	}
	res = 1;
	while (1)
	{
		if (pow & 1)
			res *= n;
		pow /= 2;
		if (!pow)
			return (res);
		n *= n;
	}
}

int	ft_powerof10(long n)
{
	int	exp;

	exp = 0;
	while (n > 9)
	{
		n /= 10;
		exp++;
	}
	return (exp);
}
