/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/22 23:38:43 by jpiscice         ###   ########.fr       */
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

void	ft_rotlist(t_list *list)
{
	t_node	*tmp;

	if (!list || list->size < 2)
		return ;
	tmp = ft_pop(list);
	ft_append(list, tmp);
}

void	ft_rrotlist(t_list *list)
{
	t_node	*tmp;

	if (!list || list->size < 2)
		return ;
	tmp = list->last;
	ft_push(list, tmp);
	list->last = ft_listlast(list);
	list->last->next = NULL;
}
