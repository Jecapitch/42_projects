/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/21 22:18:48 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_single.h"

t_list	*ft_init_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->first = NULL;
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
