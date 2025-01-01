/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/3 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/01 02:06:24 by jpiscice         ###   ########.fr       */
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
	long		diff;
//	int			exp;

	node = list->first;
	diff = max - min;
//	exp = ft_powerof(diff, 3);
	i = 0;
	while (i++ < list->size)
	{
		val = getval_long(node);
		*(long *)node->content = (long)((double)(val - min) \
												/ (diff) * 1000);
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
