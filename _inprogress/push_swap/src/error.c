/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:44:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/23 01:39:00 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	isduplicate(t_node_circ *node)
{
	return ((node != node->prev \
				&& *(int *)node->content == *(int *)node->prev->content) \
		|| (node != node->next \
				&&*(int *)node->content == *(int *)node->next->content));
}

void	raise_error(t_list_circ *a, t_list_circ *b, t_list *op)
{
	clear_game(&a, &b, &op);
	ft_printf(ERROR);
	exit(1);
}
