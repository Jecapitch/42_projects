/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/04 00:41:20 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	_Bool	sorted;
	int		nperlength[10];
	int		actual_lengths[10];

	if (argc < 2)
		return (0);
	argv++;
	sorted = init_game(&game, argv, nperlength, actual_lengths);
	if (game->a->size < 2 || sorted)
	{
		clear_game(&game);
		return (0);
	}
	push_swap(game, nperlength, actual_lengths);
	ft_list_str_display(game->op, "\n");
	clear_game(&game);
	return (0);
}
