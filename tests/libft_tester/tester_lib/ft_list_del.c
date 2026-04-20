/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_list_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 16:03:19 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

void	tester_ft_lstdelone(t_list *node, void (*del)(void *))
{
	if (!node || !del)
		return (tester_ft_err_nonnull(NULL, -1, __func__));
	del(node->content);
	tester_ft_free_safe(node);
}

void	tester_ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return (tester_ft_err_nonnull(NULL, -1, __func__));
	while (*lst)
	{
		next = (*lst)->next;
		tester_ft_lstdelone(*lst, del);
		*lst = next;
	}
	lst = NULL;
}
