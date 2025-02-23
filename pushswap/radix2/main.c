/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/17 20:31:38 by jpiscice         ###   ########.fr       */
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
	argv++;
	if (init_game(&game, argv) || game->a->size < 2)
	{
		clear_game(&game);
		return (0);
	}
	sorted = rot_sort(game, game->min, game->min_index);
	if (game->a->size > 3 && reverse_rot_sort(game, game->max, game->max_index))
		reverse_sort(game);
	else if (!sorted && game->a->size <= 16)
		small_sort(game);
	else if (!sorted)
		radix_sort(game);
	ft_list_str_display(game->op, "\n");
	clear_game(&game);
	return (0);
}
