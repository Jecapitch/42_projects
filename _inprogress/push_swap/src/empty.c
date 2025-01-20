/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:40:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/19 19:41:05 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	stack_to_empty(t_game *game)
{
	if (game->a->size < game->b->size)
		return ('a');
	return ('b');
}

void	empty_stack(t_game *game, char stack)
{
	if (stack == 'a')
	{
		while (game->a->size)
			push(game, 'B', 1);
	}
	else
	{
		while (game->b->size)
			push(game, 'A', 1);
	}
}
