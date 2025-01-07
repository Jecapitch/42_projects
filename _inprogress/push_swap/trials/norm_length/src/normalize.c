/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/3 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/04 23:52:17 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	minmax(const t_list_circ *list, long *min, long *max);
static void	minmax2(const t_list_circ *list, long *min, long *max);

static void	minmax(const t_list_circ *list, long *min, long *max)
{
	t_node_circ	*node;
	long		val;
	size_t		i;

	node = list->first;
	val = getval_long(node);
	*min = val;
	*max = val;
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

static void	minmax2(const t_list_circ *list, long *min, long *max)
{
	t_node_circ	*node;
	long		val;
	size_t		i;

	node = list->first;
	val = getval_long(node);
	if (!val)
		val = getval_long(node->next);
	*min = val;
	*max = val;
	i = 0;
	while (i++ < list->size)
	{
		val = getval_long(node);
		if (val && val < *min)
			*min = val;
		if (val > *max)
			*max = val;
		node = node->next;
	}
}

void	lengths_to_treat(int nperlength[], int actual_lengths[])
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < 10)
		actual_lengths[j++] = -1;
	j = 0;
	while (i < 10)
	{
		if (nperlength[i])
			actual_lengths[j++] = i;
		i++;
	}
}

void	normalize(t_game *game, int nperlength[])
{
	long		val;
	t_node_circ	*node;
	size_t		i;
	long		min;
	long		max;

	i = 0;
	node = game->a->first;
	min = INT_MAX;
	max = INT_MIN;
	minmax(game->a, &min, &max);
	while (i++ < game->a->size)
	{
		*(long*)node->content = getval_long(node) - min;
		node = node->next;
	}
	minmax2(game->a, &min, &max);
	node = game->a->first;
	i = 0;
	while (i++ < game->a->size)
	{
		*(long*)node->content = (getval_long(node) - min + 1) * (getval_long(node) != 0);
		val = ft_powerof10(getval_long(node));
		ft_append_circ(game->a2, value_node(val));
		if (!game->a2->last)
			raise_error(game);
		nperlength[val]++;
		node = node->next;
	}
}
