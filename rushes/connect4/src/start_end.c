/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:57:17 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/19 23:12:15 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	init(int argc, char **args, t_game *game)
{
	if (argc != 3)
	{
		ft_printf("Usage: ./connect4 <number_of_rows> <number_of_columns>\n");
		return (1);
	}
	ft_bzero(game, sizeof(t_game));
	game->height = ft_atoi(args[0]);
	game->width = ft_atoi(args[1]);
	if (!(MIN_HEIGHT <= game->height \
		&& MAX_HEIGHT >= game->height \
		&& MIN_WIDTH <= game->width \
		&& MAX_WIDTH >= game->width))
	{
		ft_printf("Invalid grid size: " \
					"%d <= number_of_rows <= %d " \
					"&& %d <= number_of_cols <= %d\n", \
					MIN_HEIGHT, MAX_HEIGHT, MIN_WIDTH, MAX_WIDTH);
		return (1);
	}
	game->grid = ft_calloc(game->height + 1, sizeof(t_cell *));
	if (!game->grid)
		return (ft_dprintf(STDERR_FILENO, "%s: malloc error", __func__), 1);
	for (int i = 0; i < game->height; i++)
	{
		game->grid[i] = ft_calloc(game->width + 1, sizeof(t_cell));
		if (!game->grid[i])
		{
			cleanup(game);
			return (ft_dprintf(STDERR_FILENO, "%s: malloc error", __func__), 1);
		}
	}
	game->level = DEF_LEVEL;
	srand(time(NULL));
	game->first_player = rand() & 1;
	game->current_player = game->first_player + 1;
	init_cost(game);
	return (0);
}

void	cleanup(t_game *game)
{
	ft_printf("\e[?1049l\e[?25h");
	if (!game->grid)
		return ;
	for (int i = 0; game->grid[i]; i++)
	{
		free(game->grid[i]);
		game->grid[i] = NULL;
	}
	free(game->grid);
	game->grid = NULL;
}
