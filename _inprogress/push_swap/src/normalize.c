/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/30 20:38:37 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	minmax(const t_list_circ *list, t_node_circ **min_node, t_node_circ **max_node);
static void	transform_log10(const t_list_circ *list, t_node_circ **min_node, t_node_circ **max_node);
void	scale(t_list_circ *list, t_node_circ *min_node, t_node_circ *max_node);

static void	minmax(const t_list_circ *list, t_node_circ **min_node, t_node_circ **max_node)
{
	t_node_circ	*node;
	int			val;
	size_t		i;
	int			min;
	int			max;

	node = list->first;
	*min_node = node;
	*max_node = node;
	min = getval_int(node);
	max = getval_int(node);
	i = 0;
	while (i++ < list->size)
	{
		val = getval_int(node);
		if (val < min)
			*min_node = node;
		if (val > max)
			*max_node = node;
		node = node->next;
	}
}

static void	transform_log10(const t_list_circ *list, t_node_circ **min_node, t_node_circ **max_node)
{
	t_node_circ	*node;
	double		min;
	size_t		i;

	minmax(list, min_node, max_node);
	node = list->first;
	min = getval_int(*min_node);
	i = 0;
	while (i++ < list->size)
	{
		*(int *)node->content = 1000 * (ft_log((double)(getval_int(node) - min + 1), 2));
		node = node->next;
	}
}

void	scale(t_list_circ *list, t_node_circ *min_node, t_node_circ *max_node)
{
	int			val;
	t_node_circ	*node;
	size_t		i;
	double		min;

	node = list->first;
	min = getval_int(min_node);
	i = 0;
	while (i++ < list->size)
	{
		val = getval_int(node);
		*(int *)node->content = (list->size - 1) * (((double)val - min) / (getval_int(max_node) - min));
		node = node->next;
	}
}

void	normalize(t_list_circ *list)
{
	t_node_circ	*min_node;
	t_node_circ	*max_node;

	if (!list || !list->size)
		return ;
	min_node = NULL;
	max_node = NULL;
	transform_log10(list, &min_node, &max_node);
	scale(list, min_node, max_node);
}
