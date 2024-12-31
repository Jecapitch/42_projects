/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/30 23:32:52 by jpiscice         ###   ########.fr       */
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
	sorted = init_game(&game, argv);
	if (game->a->size < 2 || sorted)
	{
		clear_game(&game);
		return (0);
	}
	push_swap(game);
//	ft_list_str_display(op, "\n");
	clear_game(&game);
	return (0);
}
