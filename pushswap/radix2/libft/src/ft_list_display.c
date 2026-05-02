/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_display.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:27:12 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:10:00 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_single.h"

void	ft_list_str_display(t_list *list, char *sep)
{
	t_node		*node;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!list->head)
		return ;
	node = list->head;
	while (node != list->tail)
	{
		ft_printf("%s", (char *)node->content);
		if (sep)
			ft_printf("%s", sep);
		node = node->next;
	}
	ft_printf("%s\n", (char *)list->tail->content);
}

void	ft_list_int_display(t_list *list, char *sep)
{
	t_node		*node;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!list->head)
		return ;
	node = list->head;
	while (node != list->tail)
	{
		ft_printf("%d", *(int *)node->content);
		if (sep)
			ft_printf("%s", sep);
		node = node->next;
	}
	ft_printf("%d\n", *(int *)list->tail->content);
}
