/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/15 23:43:48 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_double.h"

void	ft_init_list_2(t_list_2 *list)
{
	list = malloc(sizeof(list));
	if (!list)
	{
		list = NULL;
		return ;
	}
	list->first = NULL;
	list->last = NULL;
	list->size = 0;
}

t_node_2	*ft_newnode_2(void *content)
{
	t_node_2	*newnode;

	newnode = malloc(sizeof(t_node_2));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->prev = NULL;
	newnode->next = NULL;
	return (newnode);
}

void	ft_push_2(t_list_2 *list, t_node_2 *newnode)
{
	if (!list || !newnode)
		return ;
	newnode->next = list->first;
	newnode->next->prev = newnode;
	list->first = newnode;
	list->size++;
}

void	ft_append_2(t_list_2 *list, t_node_2 *newnode)
{
	if (!list || !newnode)
		return ;
	if (list->first)
		list->last->next = newnode;
	else
		list->first = newnode;
	newnode->prev = list->last;
	list->last = newnode;
	list->size++;
}

t_node_2	*ft_pop_2(t_list_2 *list)
{
	t_node_2	*popped_node;

	if (!list)
		return (NULL);
	popped_node = list->first;
	if (list->first)
	{
		list->first = list->first->next;
		list->first->prev = NULL;
	}
	list->size--;
	popped_node->prev = NULL;
	popped_node->next = NULL;
	return (popped_node);
}
