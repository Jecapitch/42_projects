/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/17 15:29:25 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

_Bool	sorted(t_game *game)
{
	_Bool		sorted;
	t_node_circ	*node;

	if (game->b->size)
		return (0);
	sorted = 1;
	node = game->a->first;
	while (sorted && node != game->a->last)
	{
		sorted = getval_int(node) < getval_int(node->next);
		node = node->next;
	}
	return (sorted);
}

void	push_swap(t_game *game)
{
	size_t	i;
	int		div;
	int		rounds;

	if (game->a->size == 2)
		return (swap(game));
	div = 1;
	rounds = powof3(game->a->size);
	while (rounds-- >= 0)
	{
		i = game->a->size;
		while (i--)
		{
			push(game, 'b', div);
			rotate(game, div);
		}
		div *= 3;
		i = game->b->size;
		while (i--)
		{
		//	rotate(game, div);
			push(game, 'e', div);
		}
	}
}
