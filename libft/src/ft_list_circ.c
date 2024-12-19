/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_circ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:49:50 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/19 17:05:58 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circ.h"

t_list_circ	*ft_init_list_circ(void)
{
	t_list_circ *list;

	list = malloc(sizeof(t_list_circ));
	if (!list)
		return (NULL);
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
	return (list);
}

t_node_circ	*ft_newnode_circ(void *content)
{
	t_node_circ	*newnode;

	newnode = malloc(sizeof(t_node_circ));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

void	ft_push_circ(t_list_circ *list, t_node_circ *newnode)
{
	if (!list || !newnode)
		return ;
	newnode->next = list->first;
	list->first->prev = newnode;
	list->first = newnode;
	list->last->next = list->first;
	list->first->prev = list->last;
	list->size++;
}

void	ft_append_circ(t_list_circ *list, t_node_circ *newnode)
{
	if (!list || !newnode)
		return ;
	if (list->first)
		list->last->next = newnode;
	else
		list->first = newnode;
	newnode->prev = list->last;
	list->last = newnode;
	list->last->next = list->first;
	list->first->prev = list->last;
	list->size++;
}

t_node_circ	*ft_pop_circ(t_list_circ *list)
{
	t_node_circ	*popped_node;

	if (!list || !list->first)
		return (NULL);
	popped_node = list->first;
	list->first = list->first->next;
	list->first->prev = list->last;
	list->last->next = list->first;
	popped_node->prev = NULL;
	popped_node->next = NULL;
	list->size--;
	return (popped_node);
}
