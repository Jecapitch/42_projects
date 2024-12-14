/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/14 22:41:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_append(t_list_start *lst, t_list_2 *newnode)
{
	t_list_2	*last;

	last = NULL;
	if (!lst || !newnode)
		return ;
	if (lst->first)
		lst->last->next = newnode;
	else
		lst->first = newnode;
	lst->last = newnode;
	lst->size++;
}
