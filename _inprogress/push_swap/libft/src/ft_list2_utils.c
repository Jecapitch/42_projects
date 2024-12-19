/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/19 17:01:32 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_double.h"

t_node_2	*ft_listlast_2(t_list_2 *list)
{
	t_node_2	*last;

	if (!list)
		return (NULL);
	last = list->first;
	while (last->next)
		last = last->next;
	return (last);
}

size_t	ft_listsize_2(t_list_2 *list)
{
	size_t		size;
	t_node_2	*node;

	size = 0;
	node = list->first;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

void	ft_rotlist2(t_list_2 *list)
{
	t_node_2	*tmp;

	tmp = ft_pop_2(list);
	ft_append_2(list, tmp);
}

void	ft_rrotlist2(t_list_2 *list)
{
	t_node_2	*tmp;

	tmp = list->last;
	list->last = tmp->prev;
	list->last->next = NULL;
	tmp->prev = NULL;
	ft_push_2(list, tmp);
}
