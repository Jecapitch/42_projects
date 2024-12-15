/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:43:10 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/14 23:08:49 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int c, char **v)
{
	t_list		a;
	t_list		b;
	t_node_2	*toprint;

	ft_init_list(&a);
	ft_init_list(&b);
	c--;
	v++;
	while (v)
	{
		ft_append_2(&a, ft_atoi(*v));
		v++;
	}
	toprint = a->first;
	while (toprint)
	{
		printf("%d\n", toprint->content);
		toprint = toprint->next;
	}
	return (0);
}
