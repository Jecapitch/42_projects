/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_circ_display.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:29:13 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:12:02 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_circ.h"

void	ft_list_circ_int_display(t_list_circ *list, char *sep)
{
	t_node_circ		*tmp;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!list->head)
		return ;
	tmp = list->head;
	while (tmp != list->tail)
	{
		ft_printf("%d", *(int *)tmp->content, sep);
		if (sep)
			ft_printf("%s", sep);
		tmp = tmp->next;
	}
	ft_printf("%d\n", *(int *)tmp->content);
}
