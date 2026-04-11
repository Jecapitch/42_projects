/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/15 11:37:33 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_single.h"

t_list	*ft_init_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

t_node	*ft_newnode(void *content)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}

void	ft_push(t_list *list, t_node *newnode)
{
	if (!list || !newnode)
		return ;
	newnode->next = list->head;
	list->head = newnode;
	list->size++;
}

void	ft_append(t_list *list, t_node *newnode)
{
	if (!list || !newnode)
		return ;
	if (list->head)
		list->tail->next = newnode;
	else
		list->head = newnode;
	list->tail = newnode;
	list->size++;
}

void	ft_insert(t_list *list, t_node *prev_node, t_node *newnode)
{
	if (!list || !newnode)
		return ;
	if (!prev_node)
		return (ft_push(list, newnode));
	newnode->next = prev_node->next;
	prev_node->next = newnode;
	list->size++;
}
