/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/15 23:01:34 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_single.h"

void	ft_listdelone(t_node *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->content);
	free(node);
}

void	ft_listclear(t_list *list, void (*del)(void *))
{
	t_node	*to_rm;

	while (list->size)
	{
		to_rm = list->first;
		list->first = list->first->next;
		ft_listdelone(to_rm, del);
		list->size--;
	}
	free(list);
}
