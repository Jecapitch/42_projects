/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_circ_del.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/21 22:20:05 by jpiscice         ###   ########.fr       */
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

void	ft_listclear_circ(t_list_circ **list, void (*del)(void *))
{
	t_node_circ	*to_rm;

	if (!list || !(*list))
		return ;
	while ((*list)->size)
	{
		to_rm = (*list)->first;
		(*list)->first = (*list)->first->next;
		(*list)->first->prev = (*list)->last;
		(*list)->last->next = (*list)->first;
		ft_listdelone_circ(to_rm, del);
		(*list)->size--;
	}
	(*list)->first = NULL;
	(*list)->last = NULL;
	free(*list);
	*list = NULL;
}

t_node_circ	*ft_dequeue_circ(t_list_circ *list)
{
	t_node_circ	*dequeued_node;

	if (!list || !list->first)
		return (NULL);
	dequeued_node = list->first;
	if (list->size > 1)
	{
		list->first = list->first->next;
		list->first->prev = list->last;
		list->last->next = list->first;
	}
	else
	{
		list->first = NULL;
		list->last = NULL;
	}
	dequeued_node->prev = NULL;
	dequeued_node->next = NULL;
	list->size--;
	return (dequeued_node);
}

t_node_circ	*ft_pop_circ(t_list_circ *list)
{
	t_node_circ	*popped_node;

	if (!list || !list->first)
		return (NULL);
	popped_node = list->last;
	if (list->size > 1)
	{
		list->last = list->last->prev;
		list->first->prev = list->last;
		list->last->next = list->first;
	}
	else
	{
		list->first = NULL;
		list->last = NULL;
	}
	popped_node->prev = NULL;
	popped_node->next = NULL;
	list->size--;
	return (popped_node);
}
