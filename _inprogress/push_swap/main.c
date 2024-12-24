/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/23 16:25:29 by jpiscice         ###   ########.fr       */
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
											ft_printf("Size : %d\n", a->size);
											ft_printf("a\n");
											ft_list_circ_int_display(a, "->");
											ft_printf("b\n");
											ft_list_circ_int_display(b, "->");
											push(a, b, op, 'b');ft_list_circ_int_display(b, "->");
											push(a, b, op, 'b');ft_list_circ_int_display(b, "->");
											swap(a, b, op);	ft_list_circ_int_display(b, "->");
											ft_printf("=====\na\n");
											ft_list_circ_int_display(a, "->");
											ft_printf("b\n");
											ft_list_circ_int_display(b, "->");
											ft_printf("=====\n");
											ft_list_str_display(op, "->");
	}
	clear_game(&a, &b, &op);
	return (0);
}
