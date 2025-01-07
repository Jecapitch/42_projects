/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/31 00:50:05 by jpiscice         ###   ########.fr       */
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

int	getval_int(t_node_circ *node)
{
	return (*(int *)node->content);
}

long	getval_long(t_node_circ *node)
{
	return (*(long *)node->content);
}

double	getval_double(t_node_circ *node)
{
	return (*(double *)node->content);
}

void	display_game(t_list_circ *a, t_list_circ *b, t_list *op)
{
	ft_list_str_display(op, "->");
	ft_printf("a : ");
	ft_list_circ_int_display(a, "->");
	ft_printf("b : ");
	ft_list_circ_int_display(b, "->");
	ft_printf("=============\n");
}
