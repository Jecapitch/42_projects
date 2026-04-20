/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_list_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:38:23 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 16:08:20 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

void	tester_ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!lst || !f)
		return (tester_ft_err_nonnull(NULL, -1, __func__));
	current = lst;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}

t_list	*tester_ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;
	t_list	*tail;

	if (!lst || !f || !del)
		return (tester_ft_err_nonnull(NULL, -1, __func__), NULL);
	newlst = NULL;
	tail = NULL;
	while (lst)
	{
		newnode = tester_ft_lstnew(NULL);
		if (!newnode)
			return (tester_ft_lstclear(&newlst, del), NULL);
		newnode->content = f(lst->content);
		if (tail)
			tail->next = newnode;
		else
			newlst = newnode;
		tail = newnode;
		lst = lst->next;
	}
	return (newlst);
}
