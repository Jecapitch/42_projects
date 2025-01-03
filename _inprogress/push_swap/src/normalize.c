/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/3 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/03 00:21:17 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	minmax(const t_list_circ *list, long *min, long *max);
static void	scale(t_list_circ *list, long min, long max);

static void	minmax(const t_list_circ *list, long *min, long *max)
{
	t_node_circ	*node;
	long		val;
	size_t		i;

	node = list->first;
	i = 0;
	while (i++ < list->size)
	{
		val = getval_long(node);
		if (val < *min)
			*min = val;
		if (val > *max)
			*max = val;
		node = node->next;
	}
}

void	scale(t_list_circ *list, long min, long max)
{
	long		val;
	t_node_circ	*node;
	size_t		i;
//	long		diff;
	int			length[10];

//	diff = max - min;
	i = 0;
	node = list->first;
	while (i++ < list->size)
	{
		val = (getval_long(node) - min);
		*(long*)node->content = val;
		length[ft_powerof10(val)] = 1;
		node = node->next;
	}
	i = 0;
	while (i < 10)
		ft_printf("%d\n", length[i++]);
	max -= min;
	min = 0;
	node = list->first;
	while (i++ < list->size && max)
	{
	//	val = (getval_long(node) - mean) / (max - mean);
	//	*(long *)node->content = val;
		node = node->next;
	}
}

void	normalize(t_list_circ *list)
{
	long	min;
	long	max;

	if (!list || !list->size)
		return ;
	min = INT_MAX;
	max = INT_MIN;
	minmax(list, &min, &max);
	scale(list, min, max);
}
