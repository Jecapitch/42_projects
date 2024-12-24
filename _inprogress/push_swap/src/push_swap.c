/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/23 16:24:24 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	compare_first(t_list_circ *stack1, t_list_circ *stack2, t_list *op, char stack);
static int	compare_first_2_last(t_list_circ *stack1, t_list_circ *stack2, t_list *op, char stack);
static int	compare_last_2_first(t_list_circ *stack1, t_list_circ *stack2, t_list *op, char stack);

static int	compare_first(t_list_circ *stack1, t_list_circ *stack2, t_list *op, char stack)
{
	int	val1;
	int val2;
	
	if (stack1->size < 2)
		return (0);
	if (isduplicate(stack1->first) || isduplicate(stack1->first->next) || isduplicate(stack1->last))
		raise_error(stack1, stack2, op);
	val1 = *(int *)stack1->first->content;
	val2 = *(int *)stack1->first->next->content;
	return ((stack == 'a' * val1 > val2) + (stack == 'b' * (val1 < val2)));
}

static int	compare_first_2_last(t_list_circ *stack1, t_list_circ *stack2, t_list *op, char stack)
{
	int	val1;
	int val2;
	int	valend;
	
	if (stack1->size < 2)
		return (0);
	if (isduplicate(stack1->first) || isduplicate(stack1->first->next) || isduplicate(stack1->last))
		raise_error(stack1, stack2, op);
	val1 = *(int *)stack1->first->content;
	val2 = *(int *)stack1->first->next->content;
	valend = *(int *)stack1->last->content;
	if (val1 < valend && val2 < valend)
		return ((stack == 'a') * '<' + (stack == 'b') * '>');
	if (val1 > valend && val2 > valend)
		return ((stack == 'a') * '>' + (stack == 'b') * '<');
	return ('X');
}

static int	compare_last_2_first(t_list_circ *stack1, t_list_circ *stack2, t_list *op, char stack)
{
	int	val1;
	int val2;
	int	valstart;
	
	if (stack1->size < 2)
		return (0);
	if (isduplicate(stack1->first) || isduplicate(stack1->first->next) || isduplicate(stack1->last))
		raise_error(stack1, stack2, op);
	val1 = *(int *)stack1->last->content;
	val2 = *(int *)stack1->last->prev->content;
	valstart = *(int *)stack1->first->content;
	return ((stack == 'a') * (valstart < val1 && valstart > val2) + (stack == 'b') * (valstart > val1 && valstart < val2));
}

void	push_swap(t_list_circ *a, t_list_circ *b, t_list *op)
{
//	t_node_circ	*ref;
	int			cmpa_last;
	int			cmpb_last;

	if (!a->first && !b->first)
		return ;
//	ref = a->last;
	cmpa_last = compare_first_2_last(a, b, op, 'a');
	cmpb_last = compare_first_2_last(b, a, op, 'b');
	if (cmpa_last != 'X' && cmpb_last != 'X')
		swap(a, b, op);
	else if (cmpa_last != 'X')
		swap(a, b, op);
	else if (cmpb_last != 'X' && cmpb)
		swap(a, b, op);
	if (cmpa_last == '<')
		push(a, b, op, 'b');
	else if (cmpa_last == '>' && compare_last_2_first(a, b, op, 'a'))
		ft_rotlist_circ(a);
}
