/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/25 19:40:12 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	swap_nodes(t_list_circ *stack);

static void	display_game(t_list_circ *a, t_list_circ *b, t_list *op)
{
	ft_list_str_display(op, "->");
	ft_printf("a : ");
	ft_list_circ_int_display(a, "->");
	ft_printf("b : ");
	ft_list_circ_int_display(b, "->");
	ft_printf("=============\n");
}

void	push(t_list_circ *a, t_list_circ *b, t_list *op, char todo)
{
	t_node_circ	*node;
	char		ope[3];

	ope[0] = 'p';
	ope[1] = todo;
	ope[2] = '\0';
	if (a->size && todo == 'b' && cmp_last(a) != '>')
	{
		node = ft_dequeue_circ(a);
		ft_push_circ(b, node);
	}
	else if (b->size && todo == 'a' && cmp_last(b) != '<')
	{
		node = ft_dequeue_circ(b);
		ft_push_circ(a, node);
	}
	else
		return ;
	add_op(op, ope);
												display_game(a, b, op);
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

void	swap(t_list_circ *a, t_list_circ *b, t_list *op, int cmp)
{
	char	ope[3];

	if (!cmp)
		return ;
	ope[0] = 's';
	ope[1] = ('s' * (cmp == 3) + 'a' * (cmp == 1) + 'b' * (cmp == 2));
	ope[2] = '\0';
	if (cmp != 2)
		swap_nodes(a);
	if (cmp != 1)
		swap_nodes(b);
	add_op(op, ope);
												display_game(a, b, op);
}

void	rotate(t_list_circ *a, t_list_circ *b, t_list *op, int cmp)
{
	char	ope[3];

	if (!cmp || cmp > 3)
		return ;
	ope[0] = 'r';
	ope[1] = ('r' * (cmp == 3) + 'a' * (cmp == 1) + 'b' * (cmp == 2));
	ope[2] = '\0';
	if (cmp != 2)
		ft_rotlist_circ(a);
	if (cmp != 1)
		ft_rotlist_circ(b);
	add_op(op, ope);
												display_game(a, b, op);
}

void	rrotate(t_list_circ *a, t_list_circ *b, t_list *op, int cmp)
{
	char	ope[4];

	if (cmp != 4 && cmp != 8 && cmp != 12)
		return ;
	ope[0] = 'r';
	ope[1] = 'r';
	ope[2] = ('r' * (cmp == 12) + 'a' * (cmp == 4) + 'b' * (cmp == 8));
	ope[3] = '\0';
	if (cmp != 8)
		ft_rrotlist_circ(a);
	if (cmp != 4)
		ft_rrotlist_circ(b);
	add_op(op, ope);
												display_game(a, b, op);
}
