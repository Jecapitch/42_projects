/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 16:28:17 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/21 15:20:04 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned long	delay(int ms)
{
	volatile unsigned long	i = ms * 50000UL;
	volatile unsigned long	x = 1;
	volatile unsigned long	y = 2;

	while (i--)
	{
		x = x * 987654321UL + 12345UL;
		y = (y ^ x) + 42UL;
		x ^= (y << 19);
	}
	return (x ^ y);
}

void	display_horizontal_sep(int width)
{
	while (width--)
		ft_printf("=");
	ft_printf("\n");
}

void	place_pawn(t_game game)
{
	ft_printf("\e[2;%dH", game.last_move_c * 2 + 2);
	for (int r = 0; r < game.last_move_r; r++)
	{
		ft_printf("\e[?25l");
		ft_printf("%s", PAWN[game.current_player - 1]);
		delay(3000 / game.height);
		ft_printf("\e[1D");
		ft_printf(" \a");
		ft_printf("\e[2B\e[1D");
		ft_printf("\e[?25h");
	}
	ft_printf("%s", PAWN[game.current_player - 1]);
	ft_printf("\e[%d;1H", game.height * 2 + 2);
}

void	display_game(t_game game)
{
	int		h = game.height;
	int		w = game.width;

	ft_printf("\e[2J");
	ft_printf("\e[H");
	ft_printf("┏━");
	ft_printf("\e[1;%dH", w * 2 + 1);
	ft_printf("┓");
	ft_printf("\e[%d;1H", h * 2 + 1);
	ft_printf("┗━");
	ft_printf("\e[%d;", h * 2 + 1);
	ft_printf("%dH", w * 2 + 1);
	ft_printf("┛");
	ft_printf("\e[1;3H");
	for (int c = 0; c < w - 1; c++)
	{
		ft_printf("┳━");
		ft_printf("\e[2D");
		ft_printf("\e[%dB", h * 2);
		ft_printf("┻━");
		ft_printf("\e[%dA", h * 2);
	}
	ft_printf("\e[2;1H");
	for (int r = 1; r < h * 2; r++)
	{
		if (r % 2)
			ft_printf("┃ ");
		else
			ft_printf("┣━");
		for (int c = 0; c < w - 1; c++)
		{
			if (r % 2)
				ft_printf("┃ ");
			else
				ft_printf("╋━");
		}
		if (r % 2)
			ft_printf("┃");
		else
			ft_printf("┫");
		ft_printf("\e[1E");
	}
	ft_printf("\e[%d;1H", h * 2 + 2);
}
