/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:44:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/25 03:38:45 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	isduplicate(t_node_circ *node)
{
	t_node_circ	*prev;
	t_node_circ	*next;
	int			c_val;
	int			p_val;
	int			n_val;

	if (!node)
		return (0);
	prev = node->prev;
	next = node->next;
	c_val = *(int *)node->content;
	p_val = *(int *)prev->content;
	n_val = *(int *)next->content;
	return ((node != prev && c_val == p_val) || (node != next && c_val == n_val));
}

void	raise_error(t_list_circ *a, t_list_circ *b, t_list *op)
{
	clear_game(&a, &b, &op);
	ft_printf(ERROR);
	exit(1);
}
