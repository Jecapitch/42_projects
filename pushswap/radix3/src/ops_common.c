/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_common.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:40:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/13 16:01:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	empty_stack(t_game *game, t_list_circ *stack)
{
	static char	ope[3] = "p";

	if (!stack->size)
		return ;
	ope[1] = 'b' * (stack == game->a) + 'a' * (stack == game->b);
	if (!ope[1])
		return ;
	while (stack->size)
	{
		if (ope[1] == 'a')
			ft_push_circ(game->a, ft_dequeue_circ(game->b));
		else
			ft_push_circ(game->b, ft_dequeue_circ(game->a));
		add_op(game, ope);
	}
}

void	add_op(t_game *game, char *operation)
{
	t_node	*node;
	char	*content;

	content = ft_strdup(operation);
	if (!content)
		raise_error(game);
	node = ft_newnode(content);
	if (!node)
		raise_error(game);
	ft_append(game->op, node);
}

_Bool	issorted(t_game *game)
{
	t_list_circ	*stack;
	t_node_circ	*node;
	t_node_circ	*last;

	if (game->a->size && game->b->size \
			&& first_val(game->a) < first_val(game->b))
		return (0);
	stack = game->a;
	while (stack)
	{
		node = stack->first;
		last = stack->last;
		while (node != last)
		{
			if ((stack == game->a && getval(node) > getval(node->next)) \
					|| (stack == game->b && getval(node) < getval(node->next)))
				return (0);
			node = node->next;
		}
		if (stack == game->a)
			stack = game->b;
		else
			stack = NULL;
	}
	return (1);
}

_Bool	isinverted(t_list_circ *stack)
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
