/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 15:44:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/03/19 11:41:19 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	check_duplicate(t_game *game)
{
	int			*tab;
	int			val;
	size_t		i;
	t_node_circ	*node;

	tab = malloc(game->a->size * sizeof(int));
	if (!tab)
		raise_error(game);
	i = 0;
	while (i < game->a->size)
		tab[i++] = -1;
	i = 0;
	node = game->a->first;
	while (game->a->size > i++)
	{
		val = getval(node);
		if (tab[val] == val)
			raise_error(game);
		tab[val] = val;
		node = node->next;
	}
	free(tab);
}

void	raise_error(t_game *game)
{
	clear_game(&game);
	write(2, ERROR, 6);
	exit(1);
}
