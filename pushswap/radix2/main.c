/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/03/20 15:13:48 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		sorted;

	if (argc < 2)
		return (0);
	if (init_game(&game, ++argv) || game->a->size < 2)
	{
		clear_game(&game);
		return (0);
	}
	sorted = rot_sort(game, game->min, game->min_index);
	if (game->a->size > 3 && reverse_rot_sort(game, game->max, game->max_index))
		reverse_sort(game);
	else if (!sorted && game->a->size <= 5)
		small_sort(game);
	else if (!sorted)
		radix_sort(game);
	ft_list_str_display(game->op, "\n");
	clear_game(&game);
	return (0);
}
