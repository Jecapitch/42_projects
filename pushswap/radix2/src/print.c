/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/14 03:29:25 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	display_game(t_game *game)
{
	ft_list_str_display(game->op, "->");
	ft_printf("a : ");
	ft_list_circ_int_display(game->a, "->");
	ft_printf("b : ");
	ft_list_circ_int_display(game->b, "->");
	ft_printf("=============\n");
}

void	display_game_base(t_game *game, int base)
{
	char		*s;
	t_node_circ	*node;
	size_t		i;
	t_list_circ	*stack;

	stack = game->a;
	i = 0;
	while (i++ < 2)
	{
		node = stack->first;
		while (node != stack->last)
		{
			s = ft_ltostr(getval(node), base);
			ft_printf("%s->", s);
			ft_free_nul(s);
			node = node->next;
		}
		s = ft_ltostr(getval(node), base);
		if (stack->size)
			ft_printf("%s\n\n", s);
		ft_free_nul(s);
		stack = game->b;
	}
	ft_printf("=============\n\n");
}
