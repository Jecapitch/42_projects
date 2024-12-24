/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/23 15:32:21 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	swap_nodes(t_list_circ *stack);

void	push(t_list_circ *a, t_list_circ *b, t_list *op, char todo)
{
	t_node_circ	*node;
	char		ope[3];

	if ((todo != 'a' && todo != 'b') || (!a->size && !b->size))
		raise_error(a, b, op);
	ope[0] = 'p';
	ope[1] = todo;
	ope[2] = '\0';
	if (a->size && todo == 'b')
	{
		node = ft_dequeue_circ(a);
		ft_push_circ(b, node);
		add_op(op, ope);
	}
	else if (b->size && todo == 'a')
	{
		node = ft_dequeue_circ(b);
		ft_push_circ(a, node);
		add_op(op, ope);
	}
}

static void	swap_nodes(t_list_circ *stack)
{
	t_node_circ	*node1;
	t_node_circ	*node2;

	node1 = ft_dequeue_circ(stack);
	node2 = ft_dequeue_circ(stack);
	ft_push_circ(stack, node1);
	ft_push_circ(stack, node2);
}

void	swap(t_list_circ *a, t_list_circ *b, t_list *op)
{
	char	ope[3];
	int		anode;
	int		bnode;

	anode = (a->first && *(int *)a->first->content > *(int *)a->first->next->content);
	bnode = (b->first && *(int *)b->first->content < *(int *)b->first->next->content);
	if (!anode && !bnode)
		return ;
	ope[0] = 's';
	ope[1] = ('s' * (anode && bnode) + 'a' * (anode && !bnode) + 'b' * (!anode && bnode));
	ope[2] = '\0';
	if (ope[1] == 'a' || ope[1] != 's' )
		swap_nodes(a);
	if (ope[1] == 'b' || ope[1] != 's' )
		swap_nodes(b);
	add_op(op, ope);
}

void	rotate(t_list_circ *a, t_list_circ *b, t_list *op, char todo)
{
	char	ope[3];

	if ((todo != 'a' && todo != 'b') && todo != 'r')
		raise_error(a, b, op);
	ope[0] = 'r';
	ope[1] = todo;
	ope[2] = '\0';
	if (todo == 'r' && a->size < 2 && b->size < 2)
		return ;
	else if (todo == 'r' && a->size < 2)
		ope[1] = 'b';
	else if (todo == 'r' && b->size < 2)
		ope[1] = 'a';
	if ((todo == 'a' && a->size < 2) || (todo == 'b' && b->size < 2))
		return ;
	if (todo == 'a' || todo != 's')
		ft_rotlist_circ(a);
	if (todo == 'b' || todo != 's')
		ft_rotlist_circ(b);
	add_op(op, ope);
}

void	rrotate(t_list_circ *a, t_list_circ *b, t_list *op, char todo)
{
	char	ope[4];

	if ((todo != 'a' && todo != 'b') && todo != 'r')
		raise_error(a, b, op);
	ope[0] = 'r';
	ope[1] = 'r';
	ope[2] = todo;
	ope[3] = '\0';
	if (todo == 'r' && a->size < 2 && b->size < 2)
		return ;
	else if (todo == 'r' && a->size < 2)
		ope[2] = 'b';
	else if (todo == 'r' && b->size < 2)
		ope[2] = 'a';
	if ((todo == 'a' && a->size < 2) || (todo == 'b' && b->size < 2))
		return ;
	if (todo == 'a' || todo != 's')
		ft_rrotlist_circ(a);
	if (todo == 'b' || todo != 's')
		ft_rrotlist_circ(b);
	add_op(op, ope);
}
