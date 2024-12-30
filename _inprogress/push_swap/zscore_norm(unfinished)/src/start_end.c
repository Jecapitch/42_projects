/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/30 12:35:37 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int			init_stack(t_list_circ *a, t_list_circ *b, \
						t_list *op, char **argv);

int	init_game(t_list_circ **a, t_list_circ **b, t_list **op, char **argv)
{
	int	sorted;

	*a = ft_init_list_circ();
	*b = ft_init_list_circ();
	*op = ft_init_list();
	if (!a || !b || !op)
		raise_error(*a, *b, *op);
	sorted = init_stack(*a, *b, *op, argv);
	if (sorted)
		return (1);
	display_game(*a, *b, *op);
	normalize(*a);
	display_game(*a, *b, *op);
	return (0);
}

t_node_circ	*value_node(char *data)
{
	t_node_circ	*node;

	if (!ft_isint(data))
		return (NULL);
	node = ft_newnode_circ(malloc(sizeof(long)));
	if (!node || !node->content)
		return (ft_listdelone_circ(node, ft_free_nul), NULL);
	*(int *)node->content = ft_atoi(data);
	return (node);
}

static int	init_stack(t_list_circ *a, t_list_circ *b, t_list *op, char **argv)
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
			raise_error(a, b, op);
		i = 0;
		while (tmp[i])
		{
			node = value_node(tmp[i++]);
			if (!node)
				return (ft_free_all(tmp), raise_error(a, b, op), sorted);
			ft_append_circ(a, node);
			if (a->size > 1 && isduplicate(node))
				return (ft_free_all(tmp), raise_error(a, b, op), sorted);
			sorted &= (a->size > 1 && getval_int(node) > getval_int(node->prev));
		}
		ft_free_all(tmp);
	}
	return (sorted);
}

void	clear_game(t_list_circ **a, t_list_circ **b, t_list **op)
{
	ft_listclear_circ(a, ft_free_nul);
	ft_listclear_circ(b, ft_free_nul);
	ft_listclear(op, ft_free_nul);
}
