/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/17 20:23:40 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void		pushrot(t_game *game, t_list_circ *stack, int div, int ref);

static void	pushrot(t_game *game, t_list_circ *stack, int div, int ref)
{
	size_t	i;
	int		mod;

	i = stack->size;
	while (i-- && !issorted(game))
	{
		mod = (first_val(stack) >> div) & 1;
		if (stack->size && mod == ref)
			rad_push(game, stack);
		else if (stack->size > 1)
			rad_rotate(game, stack);
	}
}

void	rad_push(t_game *game, t_list_circ *stack)
{
	static char	ope[3] = "p";
	t_node_circ	*node;
	t_list_circ	*dest;

	if (stack == game->a)
		dest = game->b;
	else
		dest = game->a;
	ope[1] = 'b' * (stack == game->a) + 'a' * (stack == game->b);
	if (!ope[1])
		return ;
	node = ft_dequeue_circ(stack);
	ft_push_circ(dest, node);
	add_op(game, ope);
	return ;
}

_Bool	rad_rotate(t_game *game, t_list_circ *stack)
{
	static char	ope[3] = "r";

	ope[1] = 'a' * (stack == game->a) + 'b' * (stack == game->b);
	if (!ope[1])
		return (0);
	if (ope[1] == 'a')
		ft_rotlist_circ(game->a);
	if (ope[1] == 'b')
		ft_rotlist_circ(game->b);
	if (game->op->size \
		&& ((ope[1] == 'a' \
			&& !ft_strncmp((char *)game->op->last->content, "rb", 2)) \
		|| (ope[1] == 'b' \
			&& !ft_strncmp((char *)game->op->last->content, "ra", 2))))
	{
		ft_memcpy(game->op->last->content, "rr", 2);
		return (1);
	}
	add_op(game, ope);
	return (1);
}

void	radix_sort(t_game *game)
{
	int			div;

	normalize(game);
	div = 0;
	while (!issorted(game))
	{
		pushrot(game, game->a, div, 0);
		div++;
		pushrot(game, game->b, div, 1);
	}
	empty_stack(game, game->b);
}
