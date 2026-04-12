/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_deq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:13:53 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_deq.h"

t_deque	*ft_init_deq(void)
{
	return (ft_calloc(1, sizeof(t_deque)));
}

t_denode	*ft_newnode_deq(void *content)
{
	t_denode	*newnode;

	newnode = ft_calloc(1, sizeof(t_denode));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	return (newnode);
}

void	ft_push_deq(t_deque *list, t_denode *newnode)
{
	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (newnode)
	{
		newnode->next = list->head;
		newnode->next->prev = newnode;
		list->head = newnode;
		list->size++;
	}
}

void	ft_append_deq(t_deque *list, t_denode *newnode)
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
	list->size++;
}

void	ft_insert_deq(t_deque *list, t_denode *prev_node, t_denode *newnode)
{
	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!newnode)
		return ;
	if (!prev_node)
		return (ft_push_deq(list, newnode));
	newnode->next = prev_node->next;
	prev_node->next = newnode;
	list->size++;
}
