/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/23 15:24:13 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	add_op(t_list *op, char *operation)
{
	t_node	*node;
	char	*content;

	content = ft_calloc(4, sizeof(char));
	ft_strlcpy(content, operation, 4);
	node = ft_newnode(content);
	ft_append(op, node);
}

void	clear_game(t_list_circ **a, t_list_circ **b, t_list **op)
{
	ft_listclear_circ(a, ft_free_nul);
	ft_listclear_circ(b, ft_free_nul);
	ft_listclear(op, ft_free_nul);
}
