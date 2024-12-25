/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/25 18:54:58 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list_circ	*a;
	t_list_circ	*b;
	t_list		*op;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	op = NULL;
	argv++;
	init_game(&a, &b, &op, argv);
	if (a->size > 1)
	{
											push_swap(a, b, op);
	}
	clear_game(&a, &b, &op);
	return (0);
}
