/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/14 03:43:56 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		return (0);
	argv++;
	if (init_game(&game, argv) || game->a->size < 2)
	{
		clear_game(&game);
		return (0);
	}
	if (game->a->size > 3 && isinverted(game->a))
		reverse(game);
	else if (game->a->size < 10)
		smallsort(game);
	else
		radix_sort(game);
	ft_list_str_display(game->op, "\n");
	clear_game(&game);
	return (0);
}
