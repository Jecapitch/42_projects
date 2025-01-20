/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/19 22:57:23 by jpiscice         ###   ########.fr       */
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

void	swap(t_game *game)
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
	ope[1] = 'a' * (game->a->size > 1 && getval_int(a1) > getval_int(a2)) \
			+ 'b' * (game->b->size > 1 && getval_int(b1) < getval_int(b2));
	if (!ope[1])
		return ;
	if (ope[1] && ope[1] != 'a' && ope[1] != 'b')
		ope[1] = 's';
	if (ope[1] != 'b')
		swap_nodes(game, 'a');
	if (ope[1] != 'a')
		swap_nodes(game, 'b');
	return (add_op(game, ope));
}

void	push(t_game *game, char operation, int div)
{
	t_node_circ	*node;
	static char	ope[3] = "p";
	int			mod;

	mod = (operation == 'b') * ((getval_int(game->a->first) / div) % 3) \
		+ (operation == 'a') * ((getval_int(game->b->first) / div) % 3);
	ope[1] = 'b' * (game->a->size && operation == 'b' && mod != 2) \
			+ 'b' * (operation == 'B') \
			+ 'a' * (game->b->size && operation == 'a' && mod != 0) \
			+ 'a' * (operation == 'A');
	if (!ope[1])
		return ;
	if (ope[1] == 'b')
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

void	rotate(t_game *game, int div)
{
	static char	ope[3] = "r";
	int			amod;
	int			bmod;

	amod = (getval_int(game->a->first) / div) % 3;
	bmod = (getval_int(game->b->first) / div) % 3;
	ope[1] = 'a' * (game->a->size > 1 && amod == 2) \
			+ 'b' * (game->b->size > 1 && bmod == 0);
	if (!ope[1])
		return ;
	if (ope[1] && ope[1] != 'a' && ope[1] != 'b')
		ope[1] = 'r';
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
