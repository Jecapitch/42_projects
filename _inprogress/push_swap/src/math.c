/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:22:04 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/17 14:18:00 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pow3(int pow)
{
	return (ft_power(3, pow));
}

int	powof3(int n)
{
	int	exp;

	exp = 0;
	while (n > 2)
	{
		n /= 3;
		exp++;
	}
	return (exp);
}

int	mod3(t_node_circ *node)
{
	int	n;

	if (!node)
		return (0);
	n = getval_int(node);
	n = ft_absval(n);
	return (n % 3);
}

int	div3(t_node_circ *node)
{
	int	n;

	if (!node)
		return (0);
	n = getval_int(node);
	return (n / 3);
}
