/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:22:04 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/29 22:53:39 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	power3(int pow)
{
	return (ft_power(3, pow));
}

int	mod3(t_node_circ *node)
{
	int	n;
	if (!node)
		return (0);
	n = getval(node);
	n = ft_absval(n);
	return (n % 3);
}

int	div3(t_node_circ *node)
{
	int	n;
	if (!node)
		return (0);
	n = getval(node);
	return (n / 3);
}

