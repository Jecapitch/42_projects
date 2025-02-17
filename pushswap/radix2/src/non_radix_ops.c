/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_not_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/17 20:29:28 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	swap_nodes(t_list_circ *stack)
{
	t_node_circ	*node1;
	t_node_circ	*node2;

	node1 = ft_dequeue_circ(stack);
	node2 = ft_dequeue_circ(stack);
	ft_push_circ(stack, node1);
	ft_push_circ(stack, node2);
}

_Bool	swap(t_game *game, int aref, int bref)
{
	static char	ope[3] = "s";
	int			a1;
	int			a2;
	int			b1;
	int			b2;

	if (issorted(game))
		return (0);
	a1 = first_val(game->a);
	a2 = second_val(game->a);
	b1 = first_val(game->b);
	b2 = second_val(game->b);
	ope[1] = 'a' * (a1 > a2 && (game->a->size == 2 \
				|| (a1 < aref && a2 < aref) || (a1 > aref && a2 > aref))) \
			+ 'b' * (b1 < b2 && (game->b->size == 2 \
				|| (b1 < bref && b2 < bref) || (b1 > bref && b2 > bref)));
	if (!ope[1])
		return (0);
	if (ope[1] != 'a' && ope[1] != 'b')
		ope[1] = 's';
	if (ope[1] != 'b')
		swap_nodes(game->a);
	if (ope[1] != 'a')
		swap_nodes(game->b);
	return (add_op(game, ope), 1);
}

_Bool	smallpush(t_game *game, t_list_circ *stack, \
			int aref, int bref)
{
	static char	ope[3] = "p";
	t_node_circ	*node;
	int			val1;
	int			val2;
	t_list_circ	*dest;

	if (stack->size < 2 || issorted(game))
		return (0);
	if (stack == game->a)
		dest = game->b;
	else
		dest = game->a;
	val1 = first_val(stack);
	val2 = second_val(stack);
	ope[1] = 'b' * (stack == game->a && val1 < aref && val1 < val2) \
			+ 'a' * (stack == game->b && val1 > bref && val1 > val2);
	if (!ope[1])
		return (0);
	node = ft_dequeue_circ(stack);
	ft_push_circ(dest, node);
	return (add_op(game, ope), 1);
}

_Bool	smallrotate(t_game *game, int aref, int bref)
{
	static char	ope[3] = "r";
	int			a1;
	int			a2;
	int			b1;
	int			b2;

	if (issorted(game))
		return (0);
	a1 = first_val(game->a);
	a2 = second_val(game->a);
	b1 = first_val(game->b);
	b2 = second_val(game->b);
	ope[1] = 'a' * (game->a->size > 1 && a1 > aref && !(a2 > aref \
				&& a1 > a2) && a1 > last_val(game->a)) \
			+ 'b' * (game->b->size > 1 && b1 < bref && !(b2 < bref \
				&& b1 < b2) && b1 < last_val(game->b));
	if (!ope[1])
		return (0);
	if (ope[1] != 'a' && ope[1] != 'b')
		ope[1] = 'r';
	if (ope[1] != 'b')
		ft_rotlist_circ(game->a);
	if (ope[1] != 'a')
		ft_rotlist_circ(game->b);
	return (add_op(game, ope), 1);
}

_Bool	rrotate(t_game *game, int aref, int bref)
{
	static char	ope[4] = "rr";
	int			a1;
	int			a2;
	int			b1;
	int			b2;

	if (issorted(game))
		return (0);
	a1 = first_val(game->a);
	a2 = second_val(game->a);
	b1 = first_val(game->b);
	b2 = second_val(game->b);
	ope[2] = 'a' * (game->a->size > 1 && a1 > aref && !(a2 > aref \
				&& a1 > a2) && a1 < last_val(game->a)) \
			+ 'b' * (game->b->size > 1 && b1 < bref && !(b2 < bref \
				&& b1 < b2) && b1 > last_val(game->b));
	if (!ope[2])
		return (0);
	if (ope[2] != 'a' && ope[2] != 'b')
		ope[2] = 'r';
	if (ope[2] != 'b')
		ft_rrotlist_circ(game->a);
	if (ope[2] != 'a')
		ft_rrotlist_circ(game->b);
	return (add_op(game, ope), 1);
}
