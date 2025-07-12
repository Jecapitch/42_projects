/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/12 01:56:31 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_single.h"

void	ft_listdelone(t_node *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->content);
	node->content = NULL;
	ft_free_nul(node);
	node = NULL;
}

void	ft_listclear(t_list **list, void (*del)(void *))
{
	t_node	*to_rm;

	if (!list || !(*list))
		return ;
	while ((*list)->size)
	{
		to_rm = (*list)->first;
		(*list)->first = (*list)->first->next;
		ft_listdelone(to_rm, del);
		to_rm = NULL;
		(*list)->size--;
	}
	ft_free_nul(*list);
	*list = NULL;
}

t_node	*ft_dequeue(t_list *list)
{
	t_node	*dequeued_node;

	if (!list || !list->first)
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

	if (!list || !list->first)
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
