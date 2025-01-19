/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/07 19:54:10 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	add_op(t_game *game, char *operation)
{
	t_node	*node;
	char	*content;

	content = ft_strdup(operation);
	if (!content)
		raise_error(game);
	node = ft_newnode(content);
	if (!node)
		raise_error(game);
	ft_append(game->op, node);
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

void	display_game(t_game *game)
{
	ft_list_str_display(game->op, "->");
	ft_printf("a : ");
	ft_list_circ_int_display(game->a, "->");
	ft_printf("b : ");
	ft_list_circ_int_display(game->b, "->");
	ft_printf("=============\n");
}
