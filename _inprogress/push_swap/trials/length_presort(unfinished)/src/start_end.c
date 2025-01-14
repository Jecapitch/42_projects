/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/04 01:42:14 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	init_stack(t_game *game, _Bool *sorted, char **argv);

_Bool	init_game(t_game **game, char **argv, int nperlength[], int actual_lengths[])
{
	_Bool	sorted;

	*game = malloc(sizeof(t_game));
	(*game)->a = ft_init_list_circ();
	(*game)->b = ft_init_list_circ();
	(*game)->a2 = ft_init_list_circ();
	(*game)->b2 = ft_init_list_circ();
	(*game)->op = ft_init_list();
	if (!(*game)->a || !(*game)->b \
		|| !(*game)->a2 || !(*game)->b2 \
		|| !(*game)->op)
		raise_error(*game);
	init_stack(*game, &sorted, argv);
	if (!sorted)
	{
		normalize(*game, nperlength);
		lengths_to_treat(nperlength, actual_lengths);
	}
	return (sorted);
}

t_node_circ	*value_node(long data)
{
	t_node_circ	*node;

	node = ft_newnode_circ(malloc(sizeof(long)));
	if (!node || !node->content)
		return (ft_listdelone_circ(node, ft_free_nul), NULL);
	*(long *)node->content = data;
	return (node);
}

static void	init_stack(t_game *game, _Bool *sorted, char **argv)
{
	t_node_circ	*node;
	char		**tmp;
	size_t		i;

	*sorted = 1;
	while (*argv)
	{
		tmp = ft_split(*argv++, ' ');
		if (!tmp)
			raise_error(game);
		i = 0;
		while (tmp[i])
		{
			node = value_node(ft_strtol(tmp[i++]));
			if (!node || !ft_isint(tmp[i - 1]))
				return (ft_free_all(tmp), raise_error(game));
			ft_append_circ(game->a, node);
			if (game->a->size > 1 && isduplicate(node))
				return (ft_free_all(tmp), raise_error(game));
			*sorted &= (getval_long(node) > getval_long(node->prev));
		}
		ft_free_all(tmp);
	}
}

void	clear_game(t_game **game)
{
	ft_listclear_circ(&(*game)->a, ft_free_nul);
	ft_listclear_circ(&(*game)->b, ft_free_nul);
	ft_listclear_circ(&(*game)->a2, ft_free_nul);
	ft_listclear_circ(&(*game)->b2, ft_free_nul);
	ft_listclear(&(*game)->op, ft_free_nul);
}
