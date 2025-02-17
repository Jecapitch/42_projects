/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getval.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:51:41 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/13 16:01:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_node_circ	*set_node_val(int data)
{
	t_node_circ	*node;

	node = ft_newnode_circ(malloc(sizeof(int)));
	if (!node || !node->content)
		return (ft_listdelone_circ(node, ft_free_nul), NULL);
	*(int *)node->content = data;
	return (node);
}

int	getval(t_node_circ *node)
{
	if (!node)
		return (0);
	return (*(int *)node->content);
}

int	first_val(t_list_circ *stack)
{
	return (getval(stack->first));
}

int	second_val(t_list_circ *stack)
{
	if (stack->size < 2)
		return (0);
	return (getval(stack->first->next));
}

int	last_val(t_list_circ *stack)
{
	if (stack->size < 2)
		return (0);
	return (getval(stack->last));
}
