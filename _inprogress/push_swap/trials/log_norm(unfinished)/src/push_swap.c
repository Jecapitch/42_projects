/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/30 23:33:32 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_swap(t_game *game)
{
//	t_node_circ	*aref;
//	t_node_circ	*bref;

	if (!game || !game->a || !game->b || !game->a2 || !game->b2)
		return (raise_error(game));
													display_game(game->a, game->a2, game->op);
}
