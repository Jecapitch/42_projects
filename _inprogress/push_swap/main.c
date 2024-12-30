/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/29 23:47:03 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_circ	*a;
	t_list_circ	*b;
	t_list		*op;
	int			sorted;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	op = NULL;
	argv++;
	sorted = init_game(&a, &b, &op, argv);
	if (a->size < 2 || sorted)
	{
		clear_game(&a, &b, &op);
		return (0);
	}
//	push_swap(a, b, op);
//	ft_list_str_display(op, "\n");
	clear_game(&a, &b, &op);
	return (0);
}
