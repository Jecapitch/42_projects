/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/07 20:37:27 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap(t_game *game)
{
	t_node_circ	*aref;
	t_node_circ	*bref;
	t_node_circ	*node;
	int			sorted;

	if (!game || !game->a || !game->b)
		return (raise_error(game));
	sorted = 0;
	if (game->a->size == 2)
	{
		swap(game);
		sorted = 1;
	ft_list_str_display(game->op, "\n");
	}
	while (!sorted)
	{
		aref = game->a->last;
		sorted = 1;
		while (game->a->size > 2 && game->a->first != aref)
		{
			sorted &= swap(game);
			rrotate(game);
			sorted &= swap(game);
			rotate(game, aref, bref);
			sorted &= swap(game);
			push(game, 'b', aref);
			if (game->b->size == 1)
				bref = game->b->first;
			if (isduplicate(game->a->first) || isduplicate(game->a->last) \
					|| isduplicate(game->b->first) || isduplicate(game->b->last))
				return (raise_error(game));
		}
		while (game->b->size && game->b->first != bref)
		{
			sorted &= swap(game);
			rrotate(game);
			sorted &= swap(game);
			rotate(game, aref, bref);
			sorted &= swap(game);
			push(game, 'a', bref);
			if (isduplicate(game->a->first) || isduplicate(game->a->last) \
					|| isduplicate(game->b->first) || isduplicate(game->b->last))
				return (raise_error(game));
		}
		node = game->a->first;
		sorted = 1;
		while (node != game->a->last && sorted)
		{
			sorted &= getval_int(node) < getval_int(node->next);
			node = node->next;
		}
	}
}
