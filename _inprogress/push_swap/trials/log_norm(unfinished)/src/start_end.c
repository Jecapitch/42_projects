/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/31 00:51:06 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	init_stack(t_game *game, char **argv);
static void	normalized_list(t_game *game);

int	init_game(t_game **game, char **argv)
{
	int	sorted;

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
	sorted = init_stack(*game, argv);
	if (sorted)
		return (1);
	normalized_list(*game);
	return (0);
}

static void	normalized_list(t_game *game)
{
	t_node_circ	*node;
	t_node_circ	*newnode;
	char		*val;
	size_t		i;

	node = game->a->first;
	i = 0;
	while (i++ < game->a->size)
	{
		val = ft_itoa(getval_long(node));
		if (!val)
			return (raise_error(game));
		newnode = value_node(val);
		if (!newnode)
			return (ft_free_nul(val), raise_error(game));
		ft_append_circ(game->a2, newnode);
		ft_free_nul(val);
		node = node->next;
	}
	normalize(game->a2);
}

t_node_circ	*value_node(char *data)
{
	t_node_circ	*node;

	if (!ft_isint(data))
		return (NULL);
	node = ft_newnode_circ(malloc(sizeof(long)));
	if (!node || !node->content)
		return (ft_listdelone_circ(node, ft_free_nul), NULL);
	*(long *)node->content = ft_atoi(data);
	return (node);
}

static int	init_stack(t_game *game, char **argv)
{
	t_node_circ	*node;
	char		**tmp;
	size_t		i;
	int			sorted;

	sorted = 1;
	while (*argv)
	{
		tmp = ft_split(*argv++, ' ');
		if (!tmp)
			raise_error(game);
		i = 0;
		while (tmp[i])
		{
			node = value_node(tmp[i++]);
			if (!node)
				return (ft_free_all(tmp), raise_error(game), sorted);
			ft_append_circ(game->a, node);
			if (game->a->size > 1 && isduplicate(node))
				return (ft_free_all(tmp), raise_error(game), sorted);
			sorted &= (game->a->size > 1 && getval_long(node) > getval_long(node->prev));
		}
		ft_free_all(tmp);
	}
	return (sorted);
}

void	clear_game(t_game **game)
{
	ft_listclear_circ(&(*game)->a, ft_free_nul);
	ft_listclear_circ(&(*game)->b, ft_free_nul);
	ft_listclear_circ(&(*game)->a2, ft_free_nul);
	ft_listclear_circ(&(*game)->b2, ft_free_nul);
	ft_listclear(&(*game)->op, ft_free_nul);
}
