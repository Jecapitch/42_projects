/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/03/20 00:16:50 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	get_minmax_index(t_game *game);

_Bool	rot_sort(t_game *game, int min, size_t min_index)
{
	t_list_circ	*stack;

	stack = game->a;
	if (game->b->size || !issorted_rot(game, stack, min))
		return (0);
	get_minmax_index(game);
	if (min_index <= (stack->size - 1) / 2)
	{
		while (first_val(stack) != min)
		{
			ft_rotlist_circ(stack);
			add_op(game, "ra");
		}
		return (1);
	}
	while (first_val(stack) != min)
	{
		ft_rrotlist_circ(stack);
		add_op(game, "rra");
	}
	return (1);
}

_Bool	reverse_rot_sort(t_game *game, int max, size_t max_index)
{
	t_list_circ	*stack;

	stack = game->a;
	if (game->b->size || !isinverted_rot(game, stack, max))
		return (0);
	get_minmax_index(game);
	if (max_index > (stack->size - 3) / 2)
	{
		while (getval(stack->last->prev->prev) != max)
		{
			ft_rotlist_circ(stack);
			add_op(game, "ra");
		}
		return (1);
	}
	while (getval(stack->last->prev->prev) != max)
	{
		ft_rrotlist_circ(stack);
		add_op(game, "rra");
	}
	return (1);
}

void	reverse_sort(t_game *game)
{
	while (game->a->size > 3)
	{
		ft_push_circ(game->b, ft_dequeue_circ(game->a));
		add_op(game, "pb");
		ft_rotlist_circ(game->b);
		if (game->b->size > 1)
			add_op(game, "rb");
	}
	ft_rotlist_circ(game->a);
	if (game->op->size \
			&& !ft_strncmp((char *)game->op->last->content, "rb", 2))
		ft_memcpy(game->op->last->content, "rr", 2);
	else
		add_op(game, "ra");
	swap(game, last_val(game->a), 0);
	empty_stack(game, game->b);
}

static void	get_minmax_index(t_game *game)
{
	int			val;
	size_t		i;
	t_node_circ	*node;

	if (game->b->size)
		return ;
	i = 0;
	node = game->a->first;
	while (i < game->a->size)
	{
		val = getval(node);
		if (val == game->min)
			game->min_index = i;
		if (val == game->max)
			game->max_index = i;
		i++;
	}
}
