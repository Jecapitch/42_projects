/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/17 14:47:37 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	ft_printf("%s %s\n", ft_ltostr(700, 3), ft_ltostr(702, 3));
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
	display_game(game);
	clear_game(&game);
	return (0);
}
