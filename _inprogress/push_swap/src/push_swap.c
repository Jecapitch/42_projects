/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/25 19:38:27 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap(t_list_circ *a, t_list_circ *b, t_list *op)
{
	int			cmp;
	t_node_circ	*ref;

	ref = a->last;
	while (a->first != ref)
	{
		cmp = cmp_first_combine(a, b);
		swap(a, b, op, cmp);
		push(a, b, op, 'b');
		cmp = cmp_last_combine(a, b);
		rotate(a, b, op, cmp);
	if (isduplicate(a->first) || isduplicate(a->last) \
		|| isduplicate(b->first) || isduplicate(b->last))
		return (raise_error(a, b, op));
	}
	while (b->size)
	{
		cmp = cmp_first_combine(a, b);
		swap(a, b, op, cmp);
		push(a, b, op, 'a');
		cmp = cmp_last_combine(a, b);
		rotate(a, b, op, cmp);
	if (isduplicate(a->first) || isduplicate(a->last) \
		|| isduplicate(b->first) || isduplicate(b->last))
		return (raise_error(a, b, op));
	}
}
