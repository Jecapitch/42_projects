/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:44:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/17 18:05:36 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

_Bool	isduplicate(t_game *game, t_node_circ *node)
{
	t_node_circ	*prev;
	t_node_circ	*next;
	int			node_val;
	int			prev_val;
	int			next_val;

	if (!node)
		return (0);
	prev = node->prev;
	next = node->next;
	node_val = getval(node);
	prev_val = getval(prev);
	next_val = getval(next);
	if ((node != prev && node_val == prev_val) \
			|| (node != next && node_val == next_val))
		return (raise_error(game), 1);
	return (0);
}

void	raise_error(t_game *game)
{
	clear_game(&game);
	write(2, ERROR, 6);
	exit(1);
}
