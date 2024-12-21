/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_circ_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/21 21:27:10 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_circ.h"

void ft_list_circ_int_display(t_list_circ *list, char *sep)
{
	t_node_circ		*tmp;
	
	tmp = list->first;
	while (tmp != list->last)
	{	
		ft_printf("%d%s", *(int *)tmp->content, sep);
		tmp = tmp->next;
	}
	ft_printf("%d\n", *(int *)list->last->content);
}

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

void	ft_rotlist_circ(t_list_circ *list)
{
	list->last = list->first;
	list->first = list->first->next;
}

void	ft_rrotlist_circ(t_list_circ *list)
{
	list->first = list->last;
	list->last = list->last->prev;
}
