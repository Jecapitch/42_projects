/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/07 20:11:45 by jpiscice         ###   ########.fr       */
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
	push_swap(game);
	ft_list_str_display(game->op, " ");
	clear_game(&game);
	return (0);
}
