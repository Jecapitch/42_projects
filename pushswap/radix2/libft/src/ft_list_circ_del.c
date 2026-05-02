/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_circ_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:04:52 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circ.h"

void	ft_listdelone_circ(t_node_circ *node, void (*del)(void *))
{
	if (!node || !del)
		return (ft_err_nonnull(NULL, -1, __func__));
	del(node->content);
	free(node);
}

void	ft_listclear_circ(t_list_circ **list, void (*del)(void *))
{
	t_node_circ	*tmp;

	if (!list || !(*list) || !del)
		return (ft_err_nonnull(NULL, -1, __func__));
	while ((*list)->size)
	{
		tmp = (*list)->head;
		(*list)->head = (*list)->head->next;
		(*list)->head->prev = (*list)->tail;
		(*list)->tail->next = (*list)->head;
		ft_listdelone_circ(tmp, del);
		(*list)->size--;
	}
	(*list)->head = NULL;
	(*list)->tail = NULL;
	free(*list);
	*list = NULL;
}

t_node_circ	*ft_dequeue_circ(t_list_circ *list)
{
	t_node_circ	*dequeued_node;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__), NULL);
	if (!list->head)
		return (NULL);
	dequeued_node = list->head;
	if (list->size > 1)
	{
		list->head = list->head->next;
		list->head->prev = list->tail;
		list->tail->next = list->head;
	}
	else
	{
		list->head = NULL;
		list->tail = NULL;
	}
	dequeued_node->prev = NULL;
	dequeued_node->next = NULL;
	list->size--;
	return (dequeued_node);
}

t_node_circ	*ft_pop_circ(t_list_circ *list)
{
	t_node_circ	*popped_node;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__), NULL);
	if (!list->tail)
		return (NULL);
	popped_node = list->tail;
	if (list->size > 1)
	{
		list->tail = list->tail->prev;
		list->head->prev = list->tail;
		list->tail->next = list->head;
	}
	else
	{
		list->head = NULL;
		list->tail = NULL;
	}
	popped_node->prev = NULL;
	popped_node->next = NULL;
	list->size--;
	return (popped_node);
}
