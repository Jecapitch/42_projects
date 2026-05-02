/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_circ_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:12:32 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circ.h"

t_node_circ	*ft_list_tail_circ(t_list_circ *list)
{
	t_node_circ	*last;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__), NULL);
	if (!list->head)
		return (NULL);
	last = list->head;
	while (last->next != list->head)
		last = last->next;
	return (last);
}

size_t	ft_listsize_circ(t_list_circ *list)
{
	size_t		size;
	t_node_circ	*node;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__), 0);
	if (!list->head)
		return (0);
	size = 1;
	node = list->head;
	while (node->next != list->head)
	{
		size++;
		node = node->next;
	}
	return (size);
}

void	ft_listiter_circ(t_list_circ *list, void (*f)(void *))
{
	t_node_circ	*node;
	size_t		i;

	if (!list || !f)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!list->head)
		return ;
	node = list->head;
	i = 0;
	while (i < list->size)
	{
		f(node->content);
		node = node->next;
		i++;
	}
}

void	ft_rotlist_circ(t_list_circ *list)
{
	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (list->head)
	{
		list->tail = list->head;
		list->head = list->head->next;
	}
}

void	ft_rrotlist_circ(t_list_circ *list)
{
	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (list->head)
	{
		list->head = list->tail;
		list->tail = list->tail->prev;
	}
}
