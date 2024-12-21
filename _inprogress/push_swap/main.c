/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/21 21:32:06 by jpiscice         ###   ########.fr       */
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
												ft_list_circ_int_display(a, "->");
	ft_listclear_circ(&a, ft_free_nul);
	ft_listclear_circ(&b, ft_free_nul);
	ft_listclear(&op, ft_free_nul);
	return (0);
}
