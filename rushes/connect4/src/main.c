/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 17:35:01 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/20 00:13:43 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "ft_printf/libft.h"
#include "libft.h"
#include "utils.h"

static int	is_done(t_game game)
{
	int count;

	for (int player = 1; player <= 2; player++)
	{
		count = 0;
		for (int i = 0; i < game.height; i++) {
			for (int j = 0; j < game.width; j++) {
				if (game.grid[i][j].player == NONE)
					continue ;
				// UP
				if (game.height - i >= 4)
					for (int x = 0; x < 4; x++)
						if ((int)game.grid[i + x][j].player == player)
							count++;
				if (count >= 4)
					return (player);
				count = 0;
				// DOWN
				if (i >= 4)
					for (int x = 0; x < 4; x++)
						if ((int)game.grid[i - x][j].player == player)
							count++;
				if (count >= 4)
					return (player);
				count = 0;
				// LEFT
				if (j >= 4)
					for (int x = 0; x < 4; x++)
						if ((int)game.grid[i][j - x].player == player)
							count++;
				if (count >= 4)
					return (player);
				count = 0;
				// RIGHT
				if (game.width - j >= 4)
					for (int x = 0; x < 4; x++)
						if ((int)game.grid[i][j + x].player == player)
							count++;
				if (count >= 4)
					return (player);
				count = 0;
				// DOWN RIGHT
				if (game.height - i >= 4 && game.width - j >= 4)
					for (int x = 0; x < 4; x++)
						if ((int)game.grid[i + x][j + x].player == player)
							count++;
				if (count >= 4)
					return (player);
				count = 0;
				// DOWN LEFT
				if (game.height - i >= 4 && j >= 3)
					for (int x = 0; x < 4; x++)
						if ((int)game.grid[i + x][j - x].player == player)
							count++;
				if (count >= 4)
					return (player);
				count = 0;
				// UP RIGHT
				if (i >= 3 && game.width - j >= 4)
					for (int x = 0; x < 4; x++)
						if ((int)game.grid[i - x][j + x].player == player)
							count++;
				if (count >= 4)
					return (player);
				count = 0;
				// UP LEFT
				if (i >= 3 && j >= 3)
					for (int x = 0; x < 4; x++)
						if ((int)game.grid[i - x][j - x].player == player)
							count++;
			}
		}
	}
	return (0);
}

#include <stdio.h>
int main(int c, char **v)
{
	t_game	game;
	int		player;
	int		height;
	int		winner;

	if (init(c, v + 1, &game))
		return (1);
	ft_printf("\e[?1049h \e[?25l");
	if (ask_level(&game))
		return (cleanup(&game), 1);
	display_game(game);
	while (1)
	{
		player = game.current_player;
		if (player == HUMAN)
			game.last_move_c = ask_player(&game);
		else
			game.last_move_c = ai_turn(game);
		if (game.last_move_c == -1)
			break ;
		height = ++game.grid[0][game.last_move_c].max_height;
		game.last_move_r = game.height - height;
		game.grid[height - 1][game.last_move_c].player = game.current_player;
		place_pawn(game);
		game.current_player = !(game.current_player - 1) + 1;
		winner = is_done(game);
		if (!winner)
			continue ;
		if (winner == HUMAN)
			ft_printf("%s You win !\n", PAWN[HUMAN - 1]);
		else
			ft_printf("%s AI wins :-(\n", PAWN[AI - 1]);
		quit(&game);
		break ;
	}
	cleanup(&game);
	return (0);
}
