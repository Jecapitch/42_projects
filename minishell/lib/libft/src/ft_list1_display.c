/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:27:12 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/12 18:29:43 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_single.h"

void	ft_list_str_display(t_list *list, char *sep)
{
	t_node		*node;

	if (!list || !list->first)
		return ;
	node = list->first;
	while (node != list->last)
	{
		ft_printf("%s%s", (char *)node->content, sep);
		node = node->next;
	}
	ft_printf("%s\n", (char *)list->last->content);
}

void	ft_list_int_display(t_list *list, char *sep)
{
	t_node		*node;

	if (!list || !list->first)
		return ;
	node = list->first;
	while (node != list->last)
	{
		ft_printf("%d%s", *(int *)node->content, sep);
		node = node->next;
	}
	ft_printf("%d\n", *(int *)list->last->content);
}
