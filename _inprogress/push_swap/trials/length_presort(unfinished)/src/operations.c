/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/31 22:22:43 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	swap_nodes(t_game *game, char list)
{
	t_node_circ	*node1;
	t_node_circ	*node2;

	if (list == 'a')
	{
		node1 = ft_dequeue_circ(game->a);
		node2 = ft_dequeue_circ(game->a);
		ft_push_circ(game->a, node1);
		ft_push_circ(game->a, node2);
		node1 = ft_dequeue_circ(game->a2);
		node2 = ft_dequeue_circ(game->a2);
		ft_push_circ(game->a2, node1);
		ft_push_circ(game->a2, node2);
	}
	else if (list == 'b')
	{
		node1 = ft_dequeue_circ(game->b);
		node2 = ft_dequeue_circ(game->b);
		ft_push_circ(game->b, node1);
		ft_push_circ(game->b, node2);
		node1 = ft_dequeue_circ(game->b2);
		node2 = ft_dequeue_circ(game->b2);
		ft_push_circ(game->b2, node1);
		ft_push_circ(game->b2, node2);
	}
}

void	swap(t_game *game)
{
	static char	ope[3] = "s";
	t_node_circ	*a1;
	t_node_circ	*a2;
	t_node_circ	*b1;
	t_node_circ	*b2;

	a1 = game->a->first;
	if (a1->next)
		a2 = a1->next;
	b1 = game->b->first;
	if (b1->next)
		b2 = b1->next;
	ope[1] = 's' * ((game->a->size > 1 && getval_int(a1) < getval_int(a2)) \
				&& (game->b->size > 1 && getval_int(b1) > getval_int(b2))) \
			+ 'a' * ((game->a->size > 1 && getval_int(a1) < getval_int(a2)) \
				&& (game->b->size < 2 || getval_int(b1) < getval_int(b2))) \
			+ 'b' * ((game->b->size > 1 && getval_int(b1) > getval_int(b2)) \
				&& (game->a->size < 2 || getval_int(a1) > getval_int(a2)));
	if (!ope[1])
		return ;
	if (ope[1] != 'b')
		swap_nodes(game, 'a');
	if (ope[1] != 'a')
		swap_nodes(game, 'b');
	add_op(game->op, ope);
}

void	push(t_game *game, char operation)
{
	t_node_circ	*node;
	static char	ope[3] = "p";

	if (operation == 'b' && game->a->size)
	{
		node = ft_dequeue_circ(game->a);
		ft_push_circ(game->b, node);
		node = ft_dequeue_circ(game->a2);
		ft_push_circ(game->b2, node);
	}
	else if (operation == 'a' && game->b->size)
	{
		node = ft_dequeue_circ(game->b);
		ft_push_circ(game->a, node);
		node = ft_dequeue_circ(game->b2);
		ft_push_circ(game->a2, node);
	}
	else
		return ;
	ope[1] = operation;
	add_op(game->op, ope);
}

void	rotate(t_game *game, char operation)
{
	static char	ope[3] = "r";

	ope[1] = 'r' * (operation == 'r' \
					&& game->a->size > 1 && game->b->size > 1) \
			+ 'a' * (operation == 'a' && game->a->size > 1) \
			+ 'b' * (operation == 'b' && game->b->size > 1);
	if (!ope[1])
		return ;
	if (ope[1] != 'b')
	{
		ft_rotlist_circ(game->a);
		ft_rotlist_circ(game->a2);
	}
	if (ope[1] != 'a')
	{
		ft_rotlist_circ(game->b);
		ft_rotlist_circ(game->b2);
	}
	add_op(game->op, ope);
}

void	rrotate(t_game *game, char operation)
{
	static char	ope[4] = "rr";

	ope[2] = 'r' * (operation == 'r' && game->a->size > 1 && game->b->size > 1) \
			+ 'a' * (operation != 'b' && game->a->size > 1) \
			+ 'b' * (operation != 'a' && game->b->size > 1);
	if (!ope[2])
		return ;
	if (ope[2] != 'b')
	{
		ft_rrotlist_circ(game->a);
		ft_rrotlist_circ(game->a2);
	}
	if (ope[2] != 'a')
	{
		ft_rrotlist_circ(game->b);
		ft_rrotlist_circ(game->b2);
	}
	add_op(game->op, ope);
}
