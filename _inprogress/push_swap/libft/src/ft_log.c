/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 01:21:54 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/01 01:16:27 by jpiscice         ###   ########.fr       */
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

double	ft_log10(double x)
{
	double	y;

	if (x <= 0)
		return (0);
	y = (x - 1) / (x + 1);
	return (2 * ft_ln_taylor(y) / LN10);
}

double	ft_log(double n, int base)
{
	double	res;
	double	fraction;
	double	power;

	power = 0.5;
	res = 0;
	while (n > 1)
	{
		n /= base;
		res++;
	}
	fraction = n;
	while (fraction < 1 && power > 1e-15)
	{
		fraction *= fraction;
		if (fraction >= base)
		{
			res += power;
			fraction /= base;
		}
		power /= 2;
	}
	return (res);
}
