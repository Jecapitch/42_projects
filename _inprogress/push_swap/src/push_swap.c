/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/19 22:58:29 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

_Bool	sorted(t_game *game)
{
	t_node_circ	*node;

	if (game->a->size && game->b->size)
		return (0);
	node = game->a->first;
	while (game->b->size == 0 && node != game->a->last)
	{
		if (getval_int(node) > getval_int(node->next))
			return (0);
		node = node->next;
	}
	node = game->b->first;
	while (game->a->size == 0 && node != game->b->last)
	{
		if (getval_int(node) < getval_int(node->next))
			return (0);
		node = node->next;
	}
	return (1);
}

void	push_swap(t_game *game)
{
	size_t	i;
	int		div;
	int		rounds;

	if (game->a->size == 2)
		return (swap(game));
	div = 1;
	rounds = (powof3(game->a->size) + 1);
	while (rounds-- && !sorted(game))
	{
		display_game(game);
		i = game->a->size;
		while (i--)
		{
			push(game, 'b', div);
			rotate(game, div);
		}
		empty_stack(game, 'a');
		if (sorted(game))
			break ;
		div *= 3;
		i = game->b->size;
		while (i--)
		{
			push(game, 'a', div);
			rotate(game, div);
		}
		empty_stack(game, 'b');
	}
	empty_stack(game, 'b');
}
