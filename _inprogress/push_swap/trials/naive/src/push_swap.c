/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/26 15:08:44 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap(t_list_circ *a, t_list_circ *b, t_list *op)
{
	int			cmp;
	t_node_circ	*ref;
	int			sorted;

	sorted = 0;
	while (!sorted || b->size)
	{
		ref = a->last;
		sorted = 1;
		while (a->size > 4 && a->first != ref)
		{
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			cmp = cmp_2_last_combine(a, b);
			rrotate(a, b, op, cmp);
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			cmp = cmp_last_combine(a, b);
			rotate(a, b, op, cmp);
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			push(a, b, op, 'b');
		if (isduplicate(a->first) || isduplicate(a->last) \
				|| isduplicate(b->first) || isduplicate(b->last))
			return (raise_error(a, b, op));
		}
		while (b->size)
		{
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			cmp = cmp_2_last_combine(a, b);
			rrotate(a, b, op, cmp);
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			cmp = cmp_last_combine(a, b);
			rotate(a, b, op, cmp);
			cmp = cmp_first_combine(a, b);
			sorted &= swap(a, b, op, cmp);
			push(a, b, op, 'a');
			if (isduplicate(a->first) || isduplicate(a->last) \
					|| isduplicate(b->first) || isduplicate(b->last))
				return (raise_error(a, b, op));
		}
	ft_listdelone_circ(ft_pop_circ(a), ft_free_nul);
	ft_listdelone_circ(ft_pop_circ(a), ft_free_nul);
	}
}
