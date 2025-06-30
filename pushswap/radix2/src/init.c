/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/03/20 14:50:25 by jpiscice         ###   ########.fr       */
/*   Updated: 2025/01/04 23:00:12 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	init_stack(t_game *game, _Bool *sorted, char **argv);
static void	get_min_max(t_game *game);
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
	(*game)->min = INT_MAX;
	(*game)->max = INT_MIN;
	(*game)->min_index = 0;
	(*game)->max_index = 0;
	if (!(*game)->a || !(*game)->b || !(*game)->op)
		return (raise_error(*game), 0);
	init_stack(*game, &sorted, argv);
	normalize(*game);
	check_duplicate(*game);
	get_min_max(*game);
	return (sorted);
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
			node = set_node_val(ft_strtol(tmp[i]));
			if (!node || !ft_isint(tmp[i++]))
				return (ft_free_str_arr(tmp), raise_error(game));
			ft_append_circ(game->a, node);
			*sorted &= (getval(node) > getval(node->prev));
		}
		ft_free_str_arr(tmp);
	}
}

static void	get_min_max(t_game *game)
{
	size_t		i;
	int			val;
	t_node_circ	*node;

	i = 0;
	node = game->a->first;
	while (i < game->a->size)
	{
		val = getval(node);
		if (val < game->min)
		{
			game->min = val;
			game->min_index = i;
		}
		if (val > game->max)
		{
			game->max = val;
			game->max_index = i;
		}
		i++;
		node = node->next;
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
		val = getval(node);
		j = 0;
		while (j < game->a->size)
		{
			if (cmp != node && getval(cmp) == val)
				return (free(c), raise_error(game));
			c[i] += (getval(cmp) < val);
			j++;
			cmp = cmp->next;
		}
		i++;
		node = node->next;
	}
}

static void	normalize(t_game *game)
{
	int			*c;
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
