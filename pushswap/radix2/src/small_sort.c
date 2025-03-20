/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/03/20 01:05:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	small_sort(t_game *game)
{
	t_list_circ	*stack;
	int			aref;
	int			bref;

	stack = game->a;
	while (!issorted(game))
	{
		aref = last_val(game->a);
		bref = last_val(game->b);
		while (!issorted(game) \
				&& ((stack == game->a && first_val(stack) != aref) \
					|| (stack == game->b && first_val(stack) != bref)))
		{
			if (game->a->size > 3 && reverse_rot_sort(game, game->max, game->max_index))
				reverse_sort(game);
			if (!rot_sort(game, game->min, game->min_index) \
				&& !rrotate(game, aref, bref) && !rotate(game, aref, bref) \
					&& !swap(game, aref, bref))
				push(game, stack, aref, bref);
			if (game->b->size == 1)
				bref = last_val(game->b);
		}
		stack = (stack == game->a) * (game->b - game->a) + game->a;
	}
	empty_stack(game, game->b);
}
