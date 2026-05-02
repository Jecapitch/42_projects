/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:58:07 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 06:19:11 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mymath.h"

long	ft_sum(int a, int b)
{
	return (a + b);
}

long	ft_sum_tab(int *tab, size_t size)
{
	long	sum;
	size_t	i;

	if (!tab)
		return (0);
	sum = 0;
	i = 0;
	while (i < size)
	{
		sum += tab[i];
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
	node = list->head;
	sum = 0;
	while (node)
	{
		sum += *(int *)node->content;
		node = node->next;
	}
	return (sum);
}

long	ft_sum_deque(t_deque *list)
{
	t_denode	*node;
	long		sum;

	if (!list || !list->size)
		return (0);
	node = list->head;
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
	node = list->head;
	sum = 0;
	while (node != list->tail)
	{
		sum += *(int *)node->content;
		node = node->next;
	}
	sum += *(int *)node->content;
	return (sum);
}
