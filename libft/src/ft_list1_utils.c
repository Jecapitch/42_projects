/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list1_compute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/15 22:49:20 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_single.h"

t_node	*ft_listlast(t_list *list)
{
	t_node	*last;

	if (!list)
		return (NULL);
	last = list->first;
	while (last->next)
		last = last->next;
	return (last);
}

size_t	ft_listsize(t_list *list)
{
	size_t	size;
	t_node	*node;

	size = 0;
	node = list->first;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
