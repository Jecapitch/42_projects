/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/28 20:25:09 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap(t_list_circ *a, t_list_circ *b, t_list *op)
{
	t_node_circ	*ref;
	int			sorted;
	//int			divpow;

	ref = a->last;
	sorted = 1;
	{
	while (a->first != ref && sorted)
	{
		sorted &= (getval(a->first) < getval(a->first->next));
		push(a, b, op, 'b');
		rotate(a, b, op);
	}
	push(a, b, op, 'b');
	rotate(a, b, op);
	ref = a->last;
	while (b->size && mod3(b->first->content))
	{
		sorted &= (getval(b->first) == 0);
		push(a, b, op, 'a');
		rotate(a, b, op);
	}
	ref = b->first;
	while (b->size && ref != b->last)
	{
		div3(ref->content);
		ref = ref->next;
	}
	div3(ref->content);
							display_game(a, b, op);
	}
}
