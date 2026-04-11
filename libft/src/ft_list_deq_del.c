/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_deq_del.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 07:07:07 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_deq.h"

void	ft_listdelone_deq(t_denode *node, void (*del)(void *))
{
	if (!node || !del)
		return ;
	del(node->content);
	free(node);
}

void	ft_listclear_deq(t_deque **list, void (*del)(void *))
{
	if (!list || !(*list))
		return ;
	while ((*list)->size)
		ft_listdelone_deq(ft_dequeue_deq(*list), del);
	(*list)->head = NULL;
	(*list)->tail = NULL;
	*list = ft_free_safe(*list);
}

t_denode	*ft_dequeue_deq(t_deque *list)
{
	t_denode	*dequeued_node;

	if (!list || !list->head)
		return (NULL);
	dequeued_node = list->head;
	list->head = list->head->next;
	if (list->head)
		list->head->prev = NULL;
	dequeued_node->prev = NULL;
	dequeued_node->next = NULL;
	list->size--;
	return (dequeued_node);
}

t_denode	*ft_pop_deq(t_deque *list)
{
	t_denode	*popped_node;

	if (!list || !list->head)
		return (NULL);
	popped_node = list->tail;
	list->tail = list->tail->prev;
	if (list->tail)
		list->tail->next = NULL;
	popped_node->prev = NULL;
	popped_node->next = NULL;
	list->size--;
	return (popped_node);
}

t_denode	*ft_extract_deq(t_deque *list, t_denode *node)
{
	if (!list || !list->head || !node)
		return (NULL);
	if (node == list->head)
		return (ft_dequeue_deq(list));
	if (node == list->tail)
		return (ft_pop_deq(list));
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	list->size--;
	return (node);
}
