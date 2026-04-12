/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:07:17 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_single.h"

void	ft_listdelone(t_node *node, void (*del)(void *))
{
	if (!del)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!node)
		return ;
	del(node->content);
	node = ft_free_safe(node);
}

void	ft_listclear(t_list **list, void (*del)(void *))
{
	if (!list || !(*list))
		return (ft_err_nonnull(NULL, -1, __func__));
	while ((*list)->size)
		ft_listdelone(ft_dequeue(*list), del);
	(*list)->head = NULL;
	(*list)->tail = NULL;
	*list = ft_free_safe(*list);
}

t_node	*ft_dequeue(t_list *list)
{
	t_node	*dequeued_node;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__), NULL);
	if (!list->head || !list->size)
		return (NULL);
	dequeued_node = list->head;
	if (dequeued_node)
	{
		list->head = list->head->next;
		dequeued_node->next = NULL;
		list->size--;
	}
	return (dequeued_node);
}

t_node	*ft_pop(t_list *list)
{
	t_node	*popped_node;
	t_node	*tmp;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__), NULL);
	popped_node = list->tail;
	if (popped_node)
	{
		tmp = list->head;
		while (tmp->next != list->tail)
			tmp = tmp->next;
		tmp->next = NULL;
		list->tail = tmp;
		list->size--;
	}
	return (popped_node);
}
