/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_circ_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/16 17:10:50 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circ.h"

void	ft_listdelone_circ(t_node_circ *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->content);
	free(node);
}

void	ft_listclear_circ(t_list_circ *list, void (*del)(void *))
{
	t_node_circ	*to_rm;

	while (list->size)
	{
		to_rm = list->first;
		list->first = list->first->next;
		list->first->prev = list->last;
		list->last->next = list->first;
		ft_listdelone_circ(to_rm, del);
		list->size--;
	}
	free(list);
}
