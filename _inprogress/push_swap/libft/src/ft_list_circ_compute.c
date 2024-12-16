/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_circ_compute.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/16 17:10:39 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circ.h"

t_node_circ	*ft_listlast_circ(t_list_circ *list)
{
	t_node_circ	*last;

	if (!list || !list->first)
		return (NULL);
	last = list->first;
	while (last->next != list->first)
		last = last->next;
	return (last);
}

size_t	ft_listsize_circ(t_list_circ *list)
{
	size_t		size;
	t_node_circ	*node;

	if (!list || !list->first)
		return (0);
	size = 1;
	node = list->first;
	while (node->next != list->first)
	{
		size++;
		node = node->next;
	}
	return (size);
}
