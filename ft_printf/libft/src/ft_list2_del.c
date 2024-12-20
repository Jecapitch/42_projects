/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/15 23:50:57 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_double.h"

void	ft_listdelone_2(t_node_2 *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->content);
	free(node);
}

void	ft_listclear_2(t_list_2 *list, void (*del)(void *))
{
	t_node_2	*to_rm;

	while (list->size)
	{
		to_rm = list->first;
		list->first = list->first->next;
		list->first->prev = NULL;
		ft_listdelone_2(to_rm, del);
		list->size--;
	}
	free(list);
}
