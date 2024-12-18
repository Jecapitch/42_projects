/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/19 17:19:57 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	init_stacks(t_list_circ *a, t_list_circ *b)
{
	a = ft_init_list_circ();
	b = ft_init_list_circ();
	if (!a || !b)
	{
		ft_free_nul(a);
		ft_free_nul(b);
		write(2, ERROR, 6);
		exit(1);
	}
}

int	main(int c, char *v[])
{
	t_list_circ	*a;
	t_list_circ *b;

	if (c < 2)
		return (0);
	return (0);
}
