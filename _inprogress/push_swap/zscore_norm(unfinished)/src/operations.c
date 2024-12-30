/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/28 22:21:53 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push(t_list_circ *a, t_list_circ *b, t_list *op, char todo)
{
	t_node_circ	*node;
	static char	ope[3] = "p";

	if (a->size && todo == 'b' && mod3(a->first) != 2)
	{
		node = ft_dequeue_circ(a);
		ft_push_circ(b, node);
	}
	else if (b->size && todo == 'a' && mod3(b->first) != 0)
	{
		node = ft_dequeue_circ(b);
		ft_push_circ(a, node);
	}
	else
		return ;
	ope[1] = todo;
	add_op(op, ope);
												display_game(a, b, op);
}

void	rotate(t_list_circ *a, t_list_circ *b, t_list *op)
{
	static char	ope[3] = "r";
	int			amod;
	int			bmod;

	amod = 0;
	bmod = 0;
	if (a->size)
		amod = mod3(a->first);
	if (b->size)
		bmod = mod3(b->first);
	ope[1] = 'r' * ((amod == 2 && a->size > 1) && (bmod == 0 && b->size > 1)) \
		+ 'a' * ((amod == 2 && (a->size > 1)) && (bmod == 0 || b->size <= 1)) \
		+ 'b' * ((amod != 2 || a->size <= 1) && (bmod == 0 && b->size > 1));
	if (!ope[1])
		return ;
	if (ope[1] != 'b')
		ft_rotlist_circ(a);
	if (ope[1] != 'a' && mod3(b->first->next) == 1)
		ft_rotlist_circ(b);
	add_op(op, ope);
												display_game(a, b, op);
}
