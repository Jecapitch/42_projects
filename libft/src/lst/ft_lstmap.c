/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:38:23 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 15:54:01 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	t_list	*tail;

	if (!lst || !f || !del)
		return (ft_err_nonnull(NULL, -1, __func__), NULL);
	newlst = NULL;
	tail = NULL;
	while (lst)
	{
		newnode = ft_lstnew(lst->content);
		if (!newnode)
			return (ft_lstclear(&newlst, del), NULL);
		newnode->content = f(newnode->content);
		if (tail)
			tail->next = newnode;
		tail = newnode;
		lst = lst->next;
	}
	return (newlst);
}
