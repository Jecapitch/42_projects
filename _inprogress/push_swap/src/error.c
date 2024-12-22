/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:44:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/22 16:31:04 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		isduplicate(t_node_circ *node);
void	raise_error(t_list_circ *a, t_list_circ *b, t_list *op);

int	isduplicate(t_node_circ *node)
{
	return ((node != node->prev \
				&& *(int *)node->content == *(int *)node->prev->content) \
		|| (node != node->next \
				&&*(int *)node->content == *(int *)node->next->content));
}

void	raise_error(t_list_circ *a, t_list_circ *b, t_list *op)
{
	ft_listclear_circ(&a, ft_free_nul);
	ft_listclear_circ(&b, ft_free_nul);
	ft_listclear(&op, ft_free_nul);
	ft_printf(ERROR);
	exit(1);
}
