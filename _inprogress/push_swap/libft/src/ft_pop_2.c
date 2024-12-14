/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/14 22:41:22 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_pop_2(t_list_start *lst)
{
	void	*popped;

	if (!lst->first)
		return ;
	popped = lst->first;
	lst->first = lst->first->next;
	lst->first->prev = NULL;
	popped->prev = NULL;
	popped->next = NULL;
	return (popped);
}
