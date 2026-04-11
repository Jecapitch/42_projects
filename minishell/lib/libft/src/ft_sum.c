/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:58:07 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/29 22:44:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mymath.h"

long	ft_sum(int a, int b)
{
	return (a + b);
}

long	ft_sum_arr(int *arr)
{
	long	sum;
	size_t	size;
	size_t	i;

	if (!arr)
		return (0);
	sum = 0;
	size = sizeof(*arr) / sizeof(int);
	i = 0;
	while (i < size)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

long	ft_sum_list(t_list *list)
{
	t_node	*node;
	long	sum;

	if (!list || !list->size)
		return (0);
	node = list->first;
	sum = 0;
	while (node)
	{
		sum += *(int *)node->content;
		node = node->next;
	}
	return (sum);
}

long	ft_sum_list2(t_list_2 *list)
{
	t_node_2	*node;
	long		sum;

	if (!list || !list->size)
		return (0);
	node = list->first;
	sum = 0;
	while (node)
	{
		sum += *(int *)node->content;
		node = node->next;
	}
	return (sum);
}

long	ft_sum_list_circ(t_list_circ *list)
{
	t_node_circ	*node;
	long		sum;

	if (!list || !list->size)
		return (0);
	node = list->first;
	sum = 0;
	while (node != list->last)
	{
		sum += *(int *)node->content;
		node = node->next;
	}
	sum += *(int *)node->content;
	return (sum);
}
