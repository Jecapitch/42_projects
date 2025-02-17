/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_radix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/14 00:45:58 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	bigpush(t_game *game, t_list_circ *stack)
{
	static char	ope[3] = "p";
	t_node_circ	*node;
	t_list_circ	*dest;

	if (stack == game->a)
		dest = game->b;
	else
		dest = game->a;
	ope[1] = 'b' * (stack == game->a) + 'a' * (stack == game->b);
	if (!ope[1])
		return ;
	node = ft_dequeue_circ(stack);
	ft_push_circ(dest, node);
	return (add_op(game, ope));
}

_Bool	bigrotate(t_game *game, t_list_circ *stack)
{
	static char	ope[3] = "r";

	ope[1] = 'a' * (stack == game->a) + 'b' * (stack == game->b);
	if (!ope[1])
		return (0);
	if (ope[1] == 'a')
		ft_rotlist_circ(game->a);
	if (ope[1] == 'b')
		ft_rotlist_circ(game->b);
	return (add_op(game, ope), 1);
}
