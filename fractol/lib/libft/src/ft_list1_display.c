/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list1_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:27:12 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/21 23:33:27 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_single.h"

void	ft_list_str_display(t_list *list, char *sep)
{
	t_node		*tmp;

	if (!list || !list->first)
		return ;
	tmp = list->first;
	while (tmp != list->last)
	{
		ft_printf("%s%s", (char *)tmp->content, sep);
		tmp = tmp->next;
	}
	ft_printf("%s\n", (char *)list->last->content);
}

void	ft_list_int_display(t_list *list, char *sep)
{
	t_node		*tmp;

	if (!list || !list->first)
		return ;
	tmp = list->first;
	while (tmp != list->last)
	{
		ft_printf("%d%s", *(int *)tmp->content, sep);
		tmp = tmp->next;
	}
	ft_printf("%d\n", *(int *)list->last->content);
}
