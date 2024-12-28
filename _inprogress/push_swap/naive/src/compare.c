/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/25 23:26:51 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	cmp_first(t_list_circ *stack)
{
	int	val1;
	int val2;
	
	if (stack->size < 2)
		return (0);
	val1 = *(int *)stack->first->content;
	val2 = *(int *)stack->first->next->content;
	return ('>' * (val1 > val2) + '<' * (val1 < val2));
}

int	cmp_last(t_list_circ *stack)
{
	int	val1;
	int val2;
	
	if (stack->size < 2)
		return (0);
	val1 = *(int *)stack->first->content;
	val2 = *(int *)stack->last->content;
	return ('>' * (val1 > val2) + '<' * (val1 < val2));
}

int	cmp_first_2_last(t_list_circ *stack)
{
	int	val1;
	int val2;
	int	valend;
	
	if (stack->size < 3)
		return (0);
	val1 = *(int *)stack->first->content;
	val2 = *(int *)stack->first->next->content;
	valend = *(int *)stack->last->content;
	return ('<' * (val1 < valend && val2 < valend) + '>' * (val1 > valend && val2 > valend));
}

int	cmp_first_combine(t_list_circ *a, t_list_circ *b)
{
	return (1 * (cmp_first(a) == '>' && cmp_first_2_last(a)) + 2 * (cmp_first(b) == '<' && cmp_first_2_last(b)));
}

int	cmp_last_combine(t_list_circ *a, t_list_circ *b)
{
	return (1 * (cmp_last(a) == '>') + 2 * (cmp_last(b) == '<'));
}

int	cmp_last_2_first(t_list_circ *stack)
{
	int	val1;
	int val2;
	int	valstart;
	
	if (stack->size < 3)
		return (0);
	val1 = *(int *)stack->last->content;
	val2 = *(int *)stack->last->prev->content;
	valstart = *(int *)stack->first->content;
	return (1 * (valstart < val1 && valstart > val2) \
			+ 2 * (valstart > val1 && valstart < val2));
}

int	cmp_2_last_combine(t_list_circ *a, t_list_circ *b)
{
	return (cmp_last_2_first(a) + cmp_last_2_first(b));
}
