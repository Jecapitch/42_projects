/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/19 17:25:36 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_double.h"

t_list_2	*ft_init_list2(void)
{
	t_list_2	*list;

	list = malloc(sizeof(t_list_2));
	if (!list)
		return (NULL);
	list->first = NULL;
	list->size = 0;
	return (list);
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

	if (!list || !list->first)
		return (NULL);
	popped_node = list->first;
	list->first = list->first->next;
	list->first->prev = NULL;
	popped_node->prev = NULL;
	popped_node->next = NULL;
	list->size--;
	return (popped_node);
}
