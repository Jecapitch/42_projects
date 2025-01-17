/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:03:08 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/29 20:41:03 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"

long	ft_power(int n, int pow)
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
