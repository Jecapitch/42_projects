/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/30 20:24:43 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	transform_positive(const t_list_circ *list, t_minmax *minmax);
static void	get_minmax(const t_list_circ *list, t_minmax *minmax);
static void	zscore(t_list_circ *list);
void		scale(t_list_circ *list, int min, int max);

static void	get_minmax(const t_list_circ *list, t_minmax *minmax)
{
	t_node_circ	*node;
	int			val;
	size_t		i;

	if (!list || !list->size)
		return ;
	node = list->first;
	minmax->min = getval_int(node);
	minmax->max = getval_int(node);
	i = 0;
	while (i++ < list->size)
	{
		val = getval_int(node);
		if (val < minmax->min)
			minmax->min = val;
		if (val > minmax->max)
			minmax->max = val;
		node = node->next;
	}
}

static void	transform_positive(const t_list_circ *list, t_minmax *minmax)
{
	t_node_circ	*node;
	size_t		i;

	if (!list || !list->size)
		return ;
	get_minmax(list, minmax);
	node = list->first;
	i = 0;
	while (i++ < list->size)
	{
		*(int *)node->content = getval_int(node) - minmax->min + 1;
		node = node->next;
	}
	minmax->max -= minmax->min;
	minmax->min -= minmax->min;
}

static void	zscore(t_list_circ *list)
{
	double		mean;
	double		std_dev;
	t_node_circ	*node;
	size_t		i;

	if (!list || !list->size)
		return ;
	mean = ft_mean_list_circ(list);
	std_dev = ft_std_dev_list_circ(list);
	node = list->first;
	i = 0;
	while (i < list->size)
	{
		*(int *)node->content = (int)(100000 * (((double)getval_int(node) - mean) / std_dev));
		node = node->next;
		i++;
	}
}

void	scale(t_list_circ *list, int min, int max)
{
	t_node_circ	*node;
	size_t		i;

	if (!list || !list->size)
		return ;
	node = list->first;
	i = 0;
	while (i++ < list->size)
	{
		*(int *)node->content = ((double)(getval_int(node) - min) / (max - min)) * (list->size - 1);
		node = node->next;
	}
}

void	normalize(t_list_circ *list)
{
	t_minmax	minmax;

	if (!list || !list->size)
		return ;
	transform_positive(list, &minmax);
	zscore(list);
	transform_positive(list, &minmax);
	scale(list, minmax.min, minmax.max);
}
