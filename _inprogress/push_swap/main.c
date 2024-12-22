/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/22 23:23:22 by jpiscice         ###   ########.fr       */
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
											ft_printf("Size : %d\n", a->size);
											ft_printf("a\n");
											ft_list_circ_int_display(a, "->");
											ft_printf("b\n");
											ft_list_circ_int_display(b, "->");
											swap(a, b, op, 's');
											push(a, b, op, 'b');
											rrotate(a, b, op, 'r');
											swap(a, b, op, 'a');
											push(a, b, op, 'b');
											swap(a, b, op, 's');
											push(a, b, op, 'b');
											swap(a, b, op, 'b');
											rotate(a, b, op, 'a');
											rrotate(a, b, op, 'r');
											ft_printf("=====\na\n");
											ft_list_circ_int_display(a, "->");
											ft_printf("b\n");
											ft_list_circ_int_display(b, "->");
											ft_printf("=====\n");
											ft_list_str_display(op, "->");
	ft_listclear_circ(&a, ft_free_nul);
	ft_listclear_circ(&b, ft_free_nul);
	ft_listclear(&op, ft_free_nul);
	return (0);
}
