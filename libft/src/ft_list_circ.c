/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_circ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:49:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:12:57 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circ.h"

t_list_circ	*ft_init_list_circ(void)
{
	return (ft_calloc(1, sizeof(t_list_circ)));
}

t_node_circ	*ft_newnode_circ(void *content)
{
	t_node_circ	*newnode;

	newnode = ft_calloc(1, sizeof(t_node_circ));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	return (newnode);
}

void	ft_push_circ(t_list_circ *list, t_node_circ *newnode)
{
	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!newnode)
		return ;
	if (list->head)
		list->head->prev = newnode;
	else
		list->tail = newnode;
	newnode->next = list->head;
	list->head = newnode;
	list->tail->next = list->head;
	list->head->prev = list->tail;
	list->size++;
}

void	ft_append_circ(t_list_circ *list, t_node_circ *newnode)
{
	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!newnode)
		return ;
	if (list->head)
		list->tail->next = newnode;
	else
		list->head = newnode;
	newnode->prev = list->tail;
	list->tail = newnode;
	list->tail->next = list->head;
	list->head->prev = list->tail;
	list->size++;
}

void	ft_insert_circ(t_list_circ *list, t_node_circ *prev_node, \
			t_node_circ *newnode)
{
	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!newnode)
		return ;
	if (!prev_node)
	{
		ft_push_circ(list, newnode);
		return ;
	}
	newnode->next = prev_node->next;
	newnode->prev = prev_node;
	prev_node->next = newnode;
	newnode->next->prev = newnode;
	list->size++;
}
