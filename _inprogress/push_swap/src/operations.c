/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/28 01:08:48 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	right_bit(void *value)
{
	if (!value)
		return (0);
	return (*(int *)value & 1);
}

void	right_shift(void *value)
{
	if (!value)
		return ;
	*(int *)value >>= 1;
}

void	push(t_list_circ *a, t_list_circ *b, t_list *op, char todo)
{
	t_node_circ	*node;
	static char	ope[3] = "p";

	if (a->size && todo == 'b' && !right_bit(a->first->content))
	{
		right_shift(a->first->content);
		node = ft_dequeue_circ(a);
		ft_push_circ(b, node);
	}
	else if (b->size && todo == 'a' && right_bit(b->first->content))
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
	int			abit;
	int			bbit;

	abit = 0;
	bbit = 0;
	if (a->size)
		abit = right_bit(a->first->content);
	if (b->size)
		bbit = right_bit(b->first->content);
	ope[1] = 'r' * ((abit && a->size > 1) && (!bbit && b->size > 1)) + 'a' * ((abit && (a->size > 1)) && (bbit || b->size <= 1)) + 'b' * ((!abit || a->size <= 1) && (!bbit && b->size > 1));
	if (!ope[1])
		return ;
	if (ope[1] != 'b')
	{
		right_shift(a->first->content);
		ft_rotlist_circ(a);
	}
	if (ope[1] != 'a' && right_bit(b->first->next->content))
	{
		ft_rotlist_circ(b);
	}
	add_op(op, ope);
												display_game(a, b, op);
}
