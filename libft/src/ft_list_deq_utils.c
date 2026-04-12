/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_deq_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:13:26 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_deq.h"

t_denode	*ft_list_tail_deq(t_deque *list)
{
	t_denode	*last;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__), NULL);
	last = list->head;
	while (last->next)
		last = last->next;
	return (last);
}

size_t	ft_listsize_deq(t_deque *list)
{
	size_t		size;
	t_denode	*node;

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

void	ft_rot_deq(t_deque *list)
{
	t_denode	*tmp;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (list->size < 2)
		return ;
	tmp = ft_pop_deq(list);
	ft_append_deq(list, tmp);
}

void	ft_rrot_deq(t_deque *list)
{
	t_denode	*tmp;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (list->size < 2)
		return ;
	tmp = list->tail;
	list->tail = tmp->prev;
	list->tail->next = NULL;
	tmp->prev = NULL;
	ft_push_deq(list, tmp);
}
