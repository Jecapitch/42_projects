/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/28 23:59:46 by jpiscice         ###   ########.fr       */
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

void	ft_insert_2(t_list_2 *list, t_node_2 *prev_node, t_node_2 *newnode)
{
	if (!list || !newnode)
		return ;
	if (!prev_node)
		return (ft_push_2(list, newnode));
	newnode->next = prev_node->next;
	prev_node->next = newnode;
	list->size++;
}
