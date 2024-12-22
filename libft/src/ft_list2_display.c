/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:28:24 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/21 23:30:06 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_double.h"

void	ft_list2_int_display(t_list_2 *list, char *sep)
{
	t_node_2	*tmp;

	if (!list || !list->first)
		return ;
	tmp = list->first;
	while (tmp != list->last)
	{
		ft_printf("%d%s", *(int *)tmp->content, sep);
		tmp = tmp->next;
	}
	ft_printf("%d\n", *(int *)list->last->content);
}
