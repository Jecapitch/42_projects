/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/17 14:25:20 by jpiscice         ###   ########.fr       */
/*   Updated: 2025/01/04 23:00:12 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	init_stack(t_game *game, _Bool *sorted, char **argv);
static void	compute_position(t_game *game, int *c);
static void	normalize(t_game *game);

_Bool	init_game(t_game **game, char **argv)
{
	_Bool	sorted;

	*game = malloc(sizeof(t_game));
	if (!game)
		return (raise_error(*game), 0);
	(*game)->a = ft_init_list_circ();
	(*game)->b = ft_init_list_circ();
	(*game)->op = ft_init_list();
	if (!(*game)->a || !(*game)->b || !(*game)->op)
		return (raise_error(*game), 0);
	init_stack(*game, &sorted, argv);
	if (!sorted)
		normalize(*game);
	return (sorted);
}

t_node_circ	*value_node(int data)
{
	t_node_circ	*node;

	node = ft_newnode_circ(malloc(sizeof(int)));
	if (!node || !node->content)
		return (ft_listdelone_circ(node, ft_free_nul), NULL);
	*(int *)node->content = data;
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
			node = value_node(ft_strtol(tmp[i]));
			if (!node || !ft_isint(tmp[i++]))
				return (ft_free_all(tmp), raise_error(game));
			ft_append_circ(game->a, node);
			if (game->a->size > 1 && isduplicate(node))
				return (ft_free_all(tmp), raise_error(game));
			*sorted &= (getval_int(node) > getval_int(node->prev));
		}
		ft_free_all(tmp);
	}
}

static void	compute_position(t_game *game, int *c)
{
	t_node_circ	*node;
	t_node_circ	*cmp;
	int			val;
	size_t		i;
	size_t		j;

	node = game->a->first;
	i = 0;
	while (i < game->a->size)
	{
		cmp = game->a->first;
		val = getval_int(node);
		j = 0;
		while (j < game->a->size)
		{
			if (cmp != node && getval_int(cmp) == val)
				return (free(c), raise_error(game));
			c[i] += (getval_int(cmp) < val);
			j++;
			cmp = cmp->next;
		}
		i++;
		node = node->next;
	}
}

static void	normalize(t_game *game)
{
	int 		*c;
	size_t		i;
	t_node_circ	*node;

	c = ft_calloc(game->a->size, sizeof(int));
	if (!c)
		return (raise_error(game));
	compute_position(game, c);
	i = 0;
	node = game->a->first;
	while (i < game->a->size)
	{
		*(int *)node->content = c[i];
		i++;
		node = node->next;
	}
	free(c);
}

void	clear_game(t_game **game)
{
	ft_listclear_circ(&(*game)->a, ft_free_nul);
	ft_listclear_circ(&(*game)->b, ft_free_nul);
	ft_listclear(&(*game)->op, ft_free_nul);
}
