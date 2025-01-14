/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/04 01:23:51 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap(t_game *game, int nperlength[], int actual_lengths[])
{
//	t_node_circ	*aref;
//	t_node_circ	*bref;

	if (!game || !game->a || !game->b || !game->a2 || !game->b2)
		return (raise_error(game));
	int	i = 0;
	while (i < 10)
		ft_printf("[%d]", nperlength[i++]);
	ft_printf("\n");
	i = 0;
	while (i < 10)
		ft_printf("[%d]", actual_lengths[i++]);
	ft_printf("\n");

													display_game(game->a, game->a2, game->op);
}
