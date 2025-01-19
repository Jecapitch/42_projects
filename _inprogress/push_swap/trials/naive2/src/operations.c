/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/07 20:29:02 by jpiscice         ###   ########.fr       */
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
	}
	else if (list == 'b')
	{
		node1 = ft_dequeue_circ(game->b);
		node2 = ft_dequeue_circ(game->b);
		ft_push_circ(game->b, node1);
		ft_push_circ(game->b, node2);
	}
}

int	swap(t_game *game)
{
	static char	ope[3] = "s";
	t_node_circ	*a1;
	t_node_circ	*a2;
	t_node_circ	*b1;
	t_node_circ	*b2;

	a1 = game->a->first;
	if (a1 && a1->next)
		a2 = a1->next;
	b1 = game->b->first;
	if (b1 && b1->next)
		b2 = b1->next;
	ope[1] = 's' * ((game->a->size > 1 && getval_int(a1) > getval_int(a2)) \
				&& (game->b->size > 1 && getval_int(b1) < getval_int(b2))) \
			+ 'a' * ((game->a->size > 1 && getval_int(a1) > getval_int(a2)) \
				&& (game->b->size < 2 || getval_int(b1) > getval_int(b2))) \
			+ 'b' * ((game->b->size > 1 && getval_int(b1) < getval_int(b2)) \
				&& (game->a->size < 2 || getval_int(a1) < getval_int(a2)));
	if (!ope[1])
		return (1);
	if (ope[1] != 'b')
		swap_nodes(game, 'a');
	if (ope[1] != 'a')
		swap_nodes(game, 'b');
	return (add_op(game, ope), 0);
}

void	push(t_game *game, char operation, t_node_circ *ref)
{
	t_node_circ	*node;
	static char	ope[3] = "p";

	ope[1] = 'b' * (operation == 'b' && game->a->size \
				&& getval_int(game->a->first) < getval_int(ref)) \
			+ 'a' * (operation == 'a' && game->b->size); 
	if (!ope[1])
		return ;
	else if (ope[1] == 'b')
	{
		node = ft_dequeue_circ(game->a);
		ft_push_circ(game->b, node);
	}
	else if (ope[1] == 'a')
	{
		node = ft_dequeue_circ(game->b);
		ft_push_circ(game->a, node);
	}
	add_op(game, ope);
}

void	rotate(t_game *game, t_node_circ *aref, t_node_circ *bref)
{
	static char	ope[3] = "r";

	ope[1] = 'r' * ((game->a->size > 1 \
						&& getval_int(game->a->first) > getval_int(aref)) \
					&& (game->b->size > 1 \
						&& getval_int(game->b->first) < getval_int(bref))) \
			+ 'a' * (game->a->size > 1 \
						&& getval_int(game->a->first) > getval_int(aref)) \
			+ 'b' * (game->b->size > 1 \
						&& getval_int(game->b->first) < getval_int(bref));
	if (!ope[1])
		return ;
	if (ope[1] != 'b')
		ft_rotlist_circ(game->a);
	if (ope[1] != 'a')
		ft_rotlist_circ(game->b);
	add_op(game, ope);
}

void	rrotate(t_game *game)
{
	static char	ope[4] = "rr";

	ope[2] = 'r' * ((game->a->size > 1 \
						&& getval_int(game->a->last) < getval_int(game->a->first)) \
					&& (game->b->size > 1 \
						&& getval_int(game->b->last) > getval_int(game->b->first))) \
			+ 'a' * (game->a->size > 1 \
						&& getval_int(game->a->last) < getval_int(game->a->first)) \
			+ 'b' * (game->b->size > 1 \
						&& getval_int(game->b->last) > getval_int(game->b->first));
	if (!ope[2])
		return ;
	if (ope[2] != 'b')
		ft_rrotlist_circ(game->a);
	if (ope[2] != 'a')
		ft_rrotlist_circ(game->b);
	add_op(game, ope);
}
