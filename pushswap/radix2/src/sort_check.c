/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:40:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/03/19 11:55:45 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

_Bool	issorted(t_game *game)
{
	t_list_circ	*stack;
	t_node_circ	*node;
	size_t		i;

	stack = game->a;
	if (first_val(stack) < first_val(game->b))
		return (0);
	i = 0;
	while (i++ < 2)
	{
		node = stack->first;
		while (node != stack->last)
		{
			if ((stack == game->a && getval(node) > getval(node->next)) \
					|| (stack == game->b && getval(node) < getval(node->next)))
				return (0);
			node = node->next;
		}
		stack = game->b;
	}
	return (1);
}

_Bool	issorted_rot(t_game *game, t_list_circ *stack, int min)
{
	t_node_circ	*node;
	int			val;
	int			prev_val;
	size_t		i;

	i = stack->size;
	node = stack->first;
	while (i--)
	{
		val = getval(node);
		prev_val = getval(node->prev);
		if (val != min && val < prev_val)
			return (0);
		node = node->next;
	}
	return (1);
}

_Bool	isinverted(t_game *game, t_list_circ *stack)
{
	t_node_circ	*node;
	t_node_circ	*last;

	node = stack->first;
	last = stack->last;
	while (node != last)
	{
		if (getval(node) < getval(node->next))
			return (0);
		node = node->next;
	}
	return (1);
}

_Bool	isinverted_rot(t_game *game, t_list_circ *stack, int max)
{
	t_node_circ	*node;
	int			val;
	int			prev_val;
	size_t		i;

	i = stack->size;
	node = stack->first;
	while (i--)
	{
		val = getval(node);
		prev_val = getval(node->prev);
		if (val != max && val > prev_val)
			return (0);
		node = node->next;
	}
	return (1);
}
