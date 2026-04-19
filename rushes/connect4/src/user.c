/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 21:51:41 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/20 00:18:17 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	prompt(t_game *game, char *msg)
{
	char	*b = game->user_input;
	int	r;

	ft_bzero(b, USER_INPUT);
	if (msg)
		ft_printf("%s", msg);
	r = read(STDIN_FILENO, b, USER_INPUT);
	if (--r >= 0)
		b[r] = '\0';
	return (r);
}

int	ask_player(t_game *game)
{
	char	*b = game->user_input;
	int		col;
	int		height;
	
	game->last_move_c = -1;
	while (game->last_move_c == -1)
	{
		height = -1;
		int	r = prompt(game, "Your turn. Choose a column number or q to quit: "); 
		ft_printf("\e[1A\e[2K\r");
		if (r == -2 || ft_strncmp(b, "q", 2) == 0)
			return (-1);
		col = ft_atoi(b) - 1;
		if (col >= 0 && col < game->width)
			height = game->grid[0][col].max_height + 1;
		if (height != -1 && col >= 0 && col < game->width && height < game->height)
			return (col);
	}
	return (0);
}

int	ask_level(t_game *game)
{
	char	*b = game->user_input;
	int		level = -1;

	while (!(0 <= level && level <= 4))
	{
		ft_printf("\e[2J\e[H");
		int	r = prompt(game, "Choose difficulty:\n" \
							"0. Default\n" \
							"1. Easy\n" \
							"2. Medium\n" \
							"3. Hard\n" \
							"4. Impossible\n");
		if (r == -1)
			return (1);
		if (r > 0)
		{
			level = ft_atoi(b);
			if (level)
				game->level = level + 1;
		}
	}
	return (0);
}

void	quit(t_game *game)
{
	prompt(game, YEL"Press enter to quit."CRESET);
}
