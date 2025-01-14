/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/04 22:59:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap(t_list_circ *a, t_list_circ *b, t_list *op)
{
	int			cmp;
	t_node_circ	*aref;
	t_node_circ	*bref;
	int			sorted;

	sorted = 0;
	while (!sorted || b->size)
	{
		aref = a->last;
		bref = b->last;
		sorted = 1;
		while (a->size > 4 && a->first != aref)
		{
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			cmp = cmp_2_last_combine(a, b);
			rrotate(a, b, op, cmp);
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			cmp = cmp_last_combine(a, b, aref, bref);
			rotate(a, b, op, cmp);
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			push(a, b, op, 'b');
			if (!bref && b->size == 1)
				bref = b->first;
		if (isduplicate(a->first) || isduplicate(a->last) \
				|| isduplicate(b->first) || isduplicate(b->last))
			return (raise_error(a, b, op));
		}
		aref = a->last;
		bref = b->last;
		while (b->size && b->first != bref)
		{
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			cmp = cmp_2_last_combine(a, b);
			rrotate(a, b, op, cmp);
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			cmp = cmp_last_combine(a, b, aref, bref);
			rotate(a, b, op, cmp);
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			push(a, b, op, 'a');
			if (isduplicate(a->first) || isduplicate(a->last) \
					|| isduplicate(b->first) || isduplicate(b->last))
				return (raise_error(a, b, op));
		}
	}
}
