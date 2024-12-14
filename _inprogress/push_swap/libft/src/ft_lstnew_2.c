/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/14 22:26:47 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_2	*ft_lstnew_2(void *content)
{
	t_list_2	*newnode;

	newnode = malloc(sizeof(t_list_2));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->previous = NULL;
	newnode->next = NULL;
	return (newnode);
}
