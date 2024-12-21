/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/21 20:43:49 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_node_circ	*value_node(char *data);
static void			init_stack(t_list_circ *a, t_list_circ *b, \
					t_list *op, char **argv);

void	init_game(t_list_circ **a, t_list_circ **b, t_list **op, char **argv)
{
	*a = ft_init_list_circ();
	*b = ft_init_list_circ();
	*op = ft_init_list();
	if (!a || !b || !op)
		raise_error(*a, *b, *op);
	init_stack(*a, *b, *op, argv);
}

 static t_node_circ	*value_node(char *data)
{
	t_node_circ	*node;

	if (!ft_isint(data))
		return (NULL);
	node = ft_newnode_circ((int *)malloc(sizeof(int)));
	if (!node || !node->content)
		return (ft_listdelone_circ(node, ft_free_nul), NULL);
	*(int *)node->content = ft_atoi(data);
	return (node);
}

static void	init_stack(t_list_circ *a, t_list_circ *b, t_list *op, char **argv)
{
	t_node_circ	*node;
	char		**tmp;
	char		**p_tmp;

	while (*argv)
	{
		tmp = ft_split(*argv, ' ');
		if (!tmp)
			raise_error(a, b, op);
		p_tmp = tmp;
		while (*tmp)
		{
			node = value_node(*tmp);
			if (!node)
				return (ft_free_all(p_tmp), raise_error(a, b, op));
			ft_append_circ(a, node);
			if (a->size > 1 && isduplicate(node))
				return (ft_free_all(p_tmp), raise_error(a, b, op));
			tmp++;
		}
		ft_free_all(p_tmp);
		argv++;
	}
}
