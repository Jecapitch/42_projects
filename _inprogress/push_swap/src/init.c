/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/20 15:46:53 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	init_game(t_list_circ *a, t_list_circ *b, t_list *op, char **argv)
{
	a = ft_init_list_circ();
	b = ft_init_list_circ();
	op = ft_init_list();
	if (!a || !b || !op)
		raise_error(a, b, op);
	init_stack(a, b, op, argv);
}

t_node_circ	*value_node(char *data)
{
	t_node_circ	*node;

	if (!ft_isint(data))
		return (NULL);
	node = ft_newnode_circ((int *)malloc(sizeof(int)));
	if (!node || !node->content)
	{
		ft_listdelone_circ(node, ft_free_nul);
		return (NULL);
	}
	*(int *)node->content = ft_atoi(data);
	return (node);
}

void	init_stack(t_list_circ *a, t_list_circ *b, t_list *op, char **argv)
{
	t_node_circ	*node;
	char		**tmp;
	size_t		i;

	while (*argv)
	{
		tmp = ft_split(*argv, ' ');
		if (!tmp)
			raise_error(a, b, op);
		i = 0;
		while (tmp[i])
		{
			node = value_node(tmp[i]);
			if (!node)
			{
				ft_free_all(tmp);
				raise_error(a, b, op);
			}
			ft_append_circ(a, node);
			if (a->size > 1 && isduplicate(node))
			{
				ft_free_all(tmp);
				raise_error(a, b, op);
			}
			i++;
		}
		ft_free_all(tmp);
		argv++;
	}
}
