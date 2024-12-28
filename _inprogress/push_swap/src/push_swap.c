/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/28 14:57:28 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap(t_list_circ *a, t_list_circ *b, t_list *op)
{
	t_node_circ	*ref;
	int			sorted;
	int			turns;

	ref = a->last;
	sorted = 1;
	turns = 0;
	while (turns < 3)
	{
	while (a->first != ref && sorted)
	{
		sorted &= (*(int *)a->first->content < *(int *)a->first->next->content);
		push(a, b, op, 'b');
		rotate(a, b, op);
	}
	push(a, b, op, 'b');
	rotate(a, b, op);
	ref = a->last;
	while (b->size && right_bit(b->first->content))
	{
		sorted &= (*(int *)b->first->content == 0);
		push(a, b, op, 'a');
		rotate(a, b, op);
	}
	ref = b->first;
	while (b->size && ref != b->last)
	{
		right_shift(ref->content);
		ref = ref->next;
	}
	right_shift(ref->content);
							display_game(a, b, op);
turns++;
	}
}
