/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_circ_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:29:13 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/21 23:29:49 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_circ.h"

void	ft_list_circ_int_display(t_list_circ *list, char *sep)
{
	t_node_circ		*tmp;

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
