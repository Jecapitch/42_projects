/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/14 03:33:15 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	pushrot(t_game *game, t_list_circ *stack, int div, int ref);

static void	pushrot(t_game *game, t_list_circ *stack, int div, int ref)
{
	size_t	i;
	int		val;
	int		mod;
	int		mod2;

	i = stack->size;
	while (i && !issorted(game))
	{
		val = first_val(stack) / div;
		mod = val % 3;
		mod2 = (val / 3) % 3;
		if (stack->size && mod == ref \
				&& !(stack == game->a && ref == 2 && mod2 == 2) \
				&& !(stack == game->b && ref == 0 && mod2 == 0))
			bigpush(game, stack);
		else if (stack->size > 1)
			bigrotate(game, stack);
		i--;
	}
}

void	radix_sort(t_game *game)
{
	int			ref;
	t_list_circ	*stack;
	int			div;

	normalize(game);
	div = 1;
	while (!issorted(game))
	{
		if (stack == game->a)
			stack = game->b;
		else
			stack = game->a;
		ref = 2 * (stack == game->b);
		while (!issorted(game) \
			&& ((stack == game->a && ref <= 2) \
				|| (stack == game->b && ref >= 0)))
		{
			pushrot(game, stack, div, ref);
			ref += ((stack == game->a) - (stack == game->b));
		}
		div *= 3;
	}
	empty_stack(game, game->b);
}

void	smallsort(t_game *game)
{
	t_list_circ	*stack;
	int			aref;
	int			bref;

	while (!issorted(game))
	{
		if (stack == game->a)
			stack = game->b;
		else
			stack = game->a;
		aref = last_val(game->a);
		bref = last_val(game->b);
		while (!issorted(game) \
				&& ((stack == game->a && first_val(stack) != aref) \
					|| (stack == game->b && first_val(stack) != bref)))
		{
			rrotate(game, aref, bref);
			smallrotate(game, aref, bref);
			swap(game, aref, bref);
			smallpush(game, stack, aref, bref);
			if (stack == game->a && game->b->size == 1)
				bref = last_val(game->b);
		}
	}
	empty_stack(game, game->b);
}

void	reverse(t_game *game)
{
	if (game->a->size > 2)
	{
		ft_rotlist_circ(game->a);
		add_op(game, "ra");
		ft_rotlist_circ(game->a);
		add_op(game, "ra");
	}
	while (game->a->size > 2)
	{
		ft_push_circ(game->b, ft_dequeue_circ(game->a));
		add_op(game, "pb");
		if (game->b->size > 1)
		{
			ft_rotlist_circ(game->b);
			add_op(game, "rb");
		}
	}
	swap(game, last_val(game->a), 0);
	empty_stack(game, game->b);
}
