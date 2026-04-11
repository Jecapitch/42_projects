/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/28 03:08:23 by jpiscice         ###   ########.fr       */
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
	if (!list || !(*list))
		return ;
	while ((*list)->size)
		ft_listdelone_2(ft_dequeue_2(*list), del);
	(*list)->first = NULL;
	(*list)->last = NULL;
	*list = ft_free_safe(*list);
}

t_node_2	*ft_dequeue_2(t_list_2 *list)
{
	t_node_2	*dequeued_node;

	if (!list || !list->first)
		return (NULL);
	dequeued_node = list->first;
	list->first = list->first->next;
	if (list->first)
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
	if (list->last)
		list->last->next = NULL;
	popped_node->prev = NULL;
	popped_node->next = NULL;
	list->size--;
	return (popped_node);
}

t_node_2	*ft_extract_2(t_list_2 *list, t_node_2 *node)
{
	if (!list || !list->first || !node)
		return (NULL);
	if (node == list->first)
		return (ft_dequeue_2(list));
	if (node == list->last)
		return (ft_pop_2(list));
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	list->size--;
	return (node);
}
