/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_std_dev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 22:03:05 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/29 22:22:22 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mymath.h"

/*
double	ft_std_dev_arr(int *arr)
{
	return (0);
}
*/

double	ft_std_dev_list_circ(t_list_circ *list)
{
	double		mean;
	long		sum;
	size_t		i;
	t_node_circ	*node;
	int			val;

	if (!list || !list->size)
		return (0);
	mean = ft_mean_list_circ(list);
	sum = 0;
	i = 0;
	node = list->first;
	while (i < list->size)
	{
		val = *(int *)node->content;
		sum += ft_power(val - mean, 2);
		node = node->next;
		i++;
	}
	return (ft_sqrt(sum));
}
