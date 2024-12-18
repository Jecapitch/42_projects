/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/15 23:43:10 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_single.h"

void	ft_init_list(t_list *list)
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
	newnode->next = list->first;
	list->first = newnode;
	list->size++;
}

void	ft_append(t_list *list, t_node *newnode)
{
	if (!list || !newnode)
		return ;
	if (list->first)
		list->last->next = newnode;
	else
		list->first = newnode;
	list->last = newnode;
	list->size++;
}

t_node	*ft_pop(t_list *list)
{
	t_node	*popped_node;

	if (!list)
		return (NULL);
	popped_node = list->first;
	if (list->first)
		list->first = list->first->next;
	list->size--;
	popped_node->next = NULL;
	return (popped_node);
}
