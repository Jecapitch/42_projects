/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:10:48 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_single.h"

t_node	*ft_list_tail(t_list *list)
{
	t_node	*last;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__), NULL);
	last = list->head;
	while (last->next)
		last = last->next;
	return (last);
}

size_t	ft_listsize(t_list *list)
{
	size_t	size;
	t_node	*node;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__), 0);
	size = 0;
	node = list->head;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

void	ft_rotlist(t_list *list)
{
	t_node	*tmp;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (list->size < 2)
		return ;
	tmp = ft_dequeue(list);
	ft_append(list, tmp);
}

void	ft_rrotlist(t_list *list)
{
	t_node	*tmp;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (list->size < 2)
		return ;
	tmp = ft_pop(list);
	ft_push(list, tmp);
}
