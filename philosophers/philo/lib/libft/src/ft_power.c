/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:03:08 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/02 23:22:06 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"

long	ft_power_int(int n, int pow)
{
	long	res;

	if (n == 1 || pow == 0)
		return (1);
	if (n == 0 || pow < 0)
		return (0);
	res = n;
	while (pow-- > 1)
		res *= n;
	return (res);
}

double	ft_power(double n, int pow)
{
	double	res;

	if (n == 1 || pow == 0)
		return (1);
	if (n == 0)
		return (0);
	if (pow < 0)
	{
		n = 1 / n;
		pow = -pow;
	}
	res = n;
	while (pow-- > 1)
		res *= n;
	return (res);
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
