/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/20 00:36:38 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	init_game(t_list_circ *a, t_list_circ *b, char *op)
{
	a = ft_init_list_circ();
	b = ft_init_list_circ();
	op = ft_strdup("");
	if (!a || !b || !op)
	{
		ft_free_nul(a);
		ft_free_nul(b);
		ft_free_nul(op);
		write(2, ERROR, 6);
		exit(1);
	}
}

char	**init_args(char **argv, int argc)
{
	char	**args;

	args = NULL;
	if (argc == 1 && ft_count_words(*argv, ' ') > 1)
	{
		args = ft_split(*argv, ' ');
		if (!args)
			return (NULL);
		return (args);
	}
	args = malloc(sizeof(char **));
	if (!args)
		return (NULL);
	args = argv;
	return (args);
}

void	fill_stack(t_list_circ *a, char **args)
{
	t_node_circ	*node;
	char		**tmp;

	tmp = args;
	while (args)
	{
		node = ft_newnode_circ(malloc(sizeof(int)));
		ft_append_circ(a, node);
		if (!node || !node->content || !ft_isint(*args))
			return (ft_listclear_circ(a, free));
//					 ft_free_all(tmp));
		*(int *)node->content = ft_atoi(*args);
		args++;
	}
//	ft_printf("%d\n", *(int *)(a->first->content));
	ft_free_all(tmp);
}

int	main(int argc, char **argv)
{
	t_list_circ	*a;
	t_list_circ	*b;
	char		*op;
	char		**args;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	op = NULL;
	init_game(a, b, op);
	args = init_args(++argv, --argc);
	fill_stack(a, args);
	return (0);
}
