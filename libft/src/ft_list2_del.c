/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/21 22:19:35 by jpiscice         ###   ########.fr       */
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

void	ft_listclear_2(t_list_2 **list, void (*del)(void *))
{
	t_node_2	*to_rm;

	if (!list || !(*list))
		return ;
	while ((*list)->size)
	{
		to_rm = (*list)->first;
		(*list)->first = (*list)->first->next;
		(*list)->first->prev = NULL;
		ft_listdelone_2(to_rm, del);
		(*list)->size--;
	}
	free(*list);
	*list = NULL;
}

t_node_2	*ft_dequeue_2(t_list_2 *list)
{
	t_node_2	*dequeued_node;

	if (!list || !list->first)
		return (NULL);
	dequeued_node = list->first;
	list->first = list->first->next;
	list->first->prev = NULL;
	dequeued_node->prev = NULL;
	dequeued_node->next = NULL;
	list->size--;
	return (dequeued_node);
}

t_node_2	*ft_pop_2(t_list_2 *list)
{
	t_node_2	*popped_node;

	if (!list || !list->first)
		return (NULL);
	popped_node = list->last;
	list->last = list->last->prev;
	list->last->next = NULL;
	popped_node->prev = NULL;
	popped_node->next = NULL;
	list->size--;
	return (popped_node);
}
