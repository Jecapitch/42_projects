/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deque.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/28 02:09:43 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_deq.h"

t_deque	*ft_init_deq(void)
{
	t_deque	*list;

	list = malloc(sizeof(t_deque));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->size = 0;
	return (list);
}

t_denode	*ft_newnode_deq(void *content)
{
	t_denode	*newnode;

	newnode = malloc(sizeof(t_denode));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

void	ft_push_deq(t_deque *list, t_denode *newnode)
{
	if (!list || !newnode)
		return ;
	newnode->next = list->head;
	newnode->next->prev = newnode;
	list->head = newnode;
	list->size++;
}

void	ft_append_deq(t_deque *list, t_denode *newnode)
{
	if (!list || !newnode)
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
	if (!list || !newnode)
		return ;
	if (!prev_node)
		return (ft_push_deq(list, newnode));
	newnode->next = prev_node->next;
	prev_node->next = newnode;
	list->size++;
}
