/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:44:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/30 23:13:21 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	isduplicate(t_node_circ *node)
{
	t_node_circ	*prev;
	t_node_circ	*next;
	int			c_val;
	int			p_val;
	int			n_val;

	if (!node)
		return (0);
	prev = node->prev;
	next = node->next;
	c_val = getval_int(node);
	p_val = getval_int(prev);
	n_val = getval_int(next);
	return ((node != prev && c_val == p_val) \
			|| (node != next && c_val == n_val));
}

void	raise_error(t_game *game)
{
	clear_game(&game);
	ft_printf(ERROR);
	exit(1);
}
