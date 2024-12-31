/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/30 12:36:16 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_list_circ	*init_norm_list(t_list_circ *list)
{
	t_list_circ	*dup;
	t_node_circ	*node;
	t_node_circ	*newnode;
	char		*val;
	size_t		i;

	dup = ft_init_list_circ();
	if (!list || !dup)
		return (ft_listclear_circ(&dup, ft_free_nul), NULL);
	node = list->first;
	i = 0;
	while (i++ < list->size)
	{
		val = ft_itoa(getval_int(node));
		if (!val)
			return (ft_listclear_circ(&dup, ft_free_nul), NULL);
		newnode = value_node(val);
		if (!newnode)
			return (ft_free_nul(val), ft_listclear_circ(&dup, ft_free_nul), NULL);
		ft_append_circ(dup, newnode);
		ft_free_nul(val);
		node = node->next;
	}
	return (dup);
}

void	push_swap(t_list_circ *a, t_list_circ *b, t_list *op)
{
	t_node_circ	*ref;
	t_list_circ	*a2;
	t_list_circ	*b2;
	int			sorted;

	a2 = init_norm_list(a);
	b2 = ft_init_list_circ();
	if (!a || !b || !a2 || !b2)
		return (clear_game(&a2, &b2, NULL), raise_error(a, b, op));
	ref = a->last;
	sorted = 1;
	while (a->first != ref && sorted)
	{
		sorted &= (getval_int(a->first) < getval_int(a->first->next));
		push(a, b, op, 'b');
		rotate(a, b, op);
	}
	push(a, b, op, 'b');
	rotate(a, b, op);
	ref = a->last;
	while (b->size && mod3(b->first->content))
	{
		sorted &= (getval_int(b->first) == 0);
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
