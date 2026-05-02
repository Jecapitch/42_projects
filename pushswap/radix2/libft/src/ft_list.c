/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:14:12 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_single.h"

t_list	*ft_init_list(void)
{
	return (ft_calloc(1, sizeof(t_list)));
}

t_node	*ft_newnode(void *content)
{
	t_node	*newnode;

	newnode = ft_calloc(1, sizeof(t_node));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	return (newnode);
}

void	ft_push(t_list *list, t_node *newnode)
{
	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!newnode)
		return ;
	newnode->next = list->head;
	list->head = newnode;
	list->size++;
}

void	ft_append(t_list *list, t_node *newnode)
{
	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!newnode)
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
	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!newnode)
		return ;
	if (!prev_node)
		return (ft_push(list, newnode));
	newnode->next = prev_node->next;
	prev_node->next = newnode;
	list->size++;
}
