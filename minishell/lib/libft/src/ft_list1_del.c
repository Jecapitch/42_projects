/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/22 22:35:12 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_single.h"

void	ft_listdelone(t_node *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->content);
	node = ft_free_safe(node);
}

void	ft_listclear(t_list **list, void (*del)(void *))
{
	if (!list || !(*list))
		return ;
	while ((*list)->size)
		ft_listdelone(ft_dequeue(*list), del);
	(*list)->first = NULL;
	(*list)->last = NULL;
	*list = ft_free_safe(*list);
}

t_node	*ft_dequeue(t_list *list)
{
	t_node	*dequeued_node;

	if (!list || !list->first || !list->size)
		return (NULL);
	dequeued_node = list->first;
	list->first = list->first->next;
	dequeued_node->next = NULL;
	list->size--;
	return (dequeued_node);
}

t_node	*ft_pop(t_list *list)
{
	t_node	*popped_node;
	t_node	*tmp;

	if (!list || !list->first || !list->size)
		return (NULL);
	popped_node = list->last;
	tmp = list->first;
	while (tmp->next != list->last)
		tmp = tmp->next;
	tmp->next = NULL;
	list->last = tmp;
	list->size--;
	return (popped_node);
}
