/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 00:04:38 by Lykoro            #+#    #+#             */
/*   Updated: 2026/04/18 19:25:53 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/libft.h"
#include "utils.h"
#include <limits.h>

void	init_cost(t_game *g)
{
	for (int i = 0; i < g->height; i++) {
		for (int j = 0; j < g->width; j++) {
			g->grid[i][j].weight = ft_min(i + 1, g->height - i) + ft_min(j + 1, g->width - j);
			// DOWN RIGHT
			if (g->height - i >= 4 && g->width - j >= 4)
				for (int x = 0; x < 3; x++)
					++g->grid[i + x][j + x].weight;
			// DOWN LEFT
			if (g->height - i >= 4 && j >= 3)
				for (int x = 0; x < 3; x++)
					++g->grid[i + x][j - x].weight;
			// UP RIGHT
			if (i >= 3 && g->width - j >= 4)
				for (int x = 0; x < 3; x++)
					++g->grid[i - x][j + x].weight;
			// UP LEFT
			if (i >= 3 && j >= 3)
				for (int x = 0; x < 3; x++)
					++g->grid[i - x][j - x].weight;
		}
	}
}

static int	prioritize_chain(t_game game, t_player player)
{
	t_player	other;
	int			count;
	int			c;

	if (player == HUMAN)
		other = AI;
	else
		other = HUMAN;
	count = 0;
	for (int i = 0; i < game.height; i++) {
		for (int j = 0; j < game.width; j++) {
			if (game.grid[i][j].player == NONE)
				continue ;
			c = 0;
			// UP
			for (int x = 0; x < game.height - i; x++)
			{
				if (game.grid[i + x][j].player == player)
					c++;
				if (game.grid[i + x][j].player == other)
				{
					c = 0;
				}
			}
			count += c;
			c = 0;
			// DOWN
			for (int x = 0; x < i; x++)
			{
				if (game.grid[i - x][j].player == player)
					c++;
				if (game.grid[i - x][j].player == other)
				{
					c = 0;
				}
			}
			count += c;
			c = 0;
			// LEFT
			for (int x = 0; x < j; x++)
			{
				if (game.grid[i][j - x].player == player)
					c++;
				if (game.grid[i][j - x].player == other)
				{
					c = 0;
				}
			}
			count += c;
			c = 0;
			// RIGHT
			for (int x = 0; x < game.width - j; x++)
			{
				if (game.grid[i][j + x].player == player)
					c++;
				if (game.grid[i][j + x].player == other)
				{
					c = 0;
				}
			}
			count += c;
			c = 0;
			// DOWN RIGHT
			for (int x = 0; x < ft_min(game.height - i, game.width - j); x++)
			{
				if (game.grid[i + x][j + x].player == player)
					c++;
				if (game.grid[i + x][j + x].player == other)
				{
					c = 0;
				}
			}
			count += c;
			c = 0;
			// DOWN LEFT
			for (int x = 0; x < ft_min(game.height - i, j); x++)
			{
				if (game.grid[i + x][j - x].player == player)
					c++;
				if (game.grid[i + x][j - x].player == other)
				{
					c = 0;
				}
			}
			count += c;
			c = 0;
			// UP RIGHT
			for (int x = 0; x < ft_min(i, game.width - j); x++)
			{
				if (game.grid[i - x][j + x].player == player)
					c++;
				if (game.grid[i - x][j + x].player == other)
				{
					c = 0;
				}
			}
			count += c;
			c = 0;
			// UP LEFT
			for (int x = 0; x < ft_min(i, j); x++)
			{
				if (game.grid[i - x][j - x].player == player)
					c++;
				if (game.grid[i - x][j - x].player == other)
				{
					c = 0;
				}
			}
			count += c;
		}
	}
	return (count * count);
}

static int	get_game_state(t_game game) {
	int			state = 0;
	t_player	player;

	for (int i = 0; i < game.height; i++)
		for (int j = 0; j < game.width; j++) {
			player = game.grid[i][j].player;
			if (player == NONE)
				continue ;
			else if (player == AI)
				state += game.grid[i][j].weight;
			else if (player == HUMAN)
				state -= game.grid[i][j].weight;
		}
	player = game.current_player;
	if (player == AI)
		state += prioritize_chain(game, player);
	else if (player == HUMAN)
		state -= prioritize_chain(game, player);
	return (state);
}

static int	is_finished(t_game game) {
	for (int i = 0; i < game.width; i++)
	{
		if (game.grid[0][i].max_height == game.height)
			continue ;
		return (0);
	}
	return (1);
}

static int	minimax(t_game g, int depth, int is_AI) {
	int	pos = 0;

	if (depth == 0 || is_finished(g))
		return (get_game_state(g));

	if (is_AI) {
		int max_eval = INT_MIN;
		for (int k = 0; k < g.width; k++)
		{
			int height = g.grid[0][k].max_height;
			if (height >= g.height)
				continue ;
			g.grid[height][k].player = AI;
			g.grid[0][k].max_height = height + 1;
			g.current_player = HUMAN;
			int eval = minimax(g, depth - 1, 0);
			g.current_player = AI;
			g.grid[height][k].player = NONE;
			g.grid[0][k].max_height = height;
			if (eval > max_eval)
				pos = k;
			max_eval = ft_max(max_eval, eval);
		}
		if (depth == g.level)
			return (pos);
		return (max_eval);
	}
	else {
		int min_eval = INT_MAX;
		for (int k = 0; k < g.width; k++)
		{
			int height = g.grid[0][k].max_height;
			if (height >= g.height)
				continue ;
			g.grid[height][k].player = HUMAN;
			g.grid[0][k].max_height = height + 1;
			g.current_player = AI;
			int eval = minimax(g, depth - 1, 1);
			g.current_player = HUMAN;
			g.grid[height][k].player = NONE;
			g.grid[0][k].max_height = height;
			if (eval < min_eval)
				pos = k;
			min_eval = ft_min(min_eval, eval);
		}
		if (depth == g.level)
			return (pos);
		return (min_eval);
	}
}

int	ai_turn(t_game game) {
	return (minimax(game, game.level, game.current_player));
}
