/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deq_display.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 23:28:24 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/21 23:30:06 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list_deq.h"

void	ft_deq_int_display(t_deque *list, char *sep)
{
	t_denode	*tmp;

	if (!list || !list->head)
		return ;
	tmp = list->head;
	while (tmp != list->tail)
	{
		ft_printf("%d%s", *(int *)tmp->content, sep);
		tmp = tmp->next;
	}
	ft_printf("%d\n", *(int *)list->tail->content);
}
