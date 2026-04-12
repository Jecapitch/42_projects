/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_deq_display.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:28:24 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:08:33 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_deq.h"

void	ft_deq_int_display(t_deque *list, char *sep)
{
	t_denode	*tmp;

	if (!list)
		return (ft_err_nonnull(NULL, -1, __func__));
	if (!list->head)
		return ;
	tmp = list->head;
	while (tmp != list->tail)
	{
		ft_printf("%d", *(int *)tmp->content);
		if (sep)
			ft_printf("%s", sep);
		tmp = tmp->next;
	}
	ft_printf("%d\n", *(int *)list->tail->content);
}
