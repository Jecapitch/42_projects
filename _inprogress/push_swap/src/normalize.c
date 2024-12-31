/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/31 01:31:56 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	minmax(const t_list_circ *list, long *min, long *max);
void		transform_log10(const t_list_circ *list, long min);
void		scale(t_list_circ *list, long min, long max);

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

void	transform_log10(const t_list_circ *list, long min)
{
	t_node_circ	*node;
	size_t		i;

	node = list->first;
	i = 0;
	while (i++ < list->size)
	{
//		*(long *)node->content = (long)(10e4 * ft_log10((double)(getval_long(node) - min + 1)));
		*(long *)node->content = getval_long(node) - min + 1;
		*(long *)node->content = (ft_log10(*(long *)node->content) * 10e12);
		node = node->next;
	}
}

void	scale(t_list_circ *list, long min, long max)
{
	int			val;
	t_node_circ	*node;
	size_t		i;

	node = list->first;
	i = 0;
	while (i++ < list->size)
	{
		val = getval_long(node);
		*(long *)node->content = 10e6 * ((list->size - 1) * ((double)val - min) / (max - min));
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
	transform_log10(list, min);
	minmax(list, &min, &max);
	scale(list, min, max);
}
