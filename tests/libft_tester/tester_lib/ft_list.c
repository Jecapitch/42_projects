/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 16:36:09 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

t_list	*tester_ft_lstnew(void *content)
{
	t_list	*node;

	node = tester_ft_calloc(1, sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	return (node);
}

int	tester_ft_lstsize(t_list *lst)
{
	int		size;

	if (!lst)
		return (tester_ft_err_nonnull(NULL, -1, __func__), 0);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_list	*tester_ft_lstlast(t_list *lst)
{
	if (!lst)
		return (tester_ft_err_nonnull(NULL, -1, __func__), NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	tester_ft_lstadd_back(t_list **lst, t_list *newnode)
{
	t_list	*last;

	if (!lst)
		return (tester_ft_err_nonnull(NULL, -1, __func__));
	if (!newnode)
		return ;
	if (*lst)
	{
		last = tester_ft_lstlast(*lst);
		last->next = newnode;
	}
	else
		*lst = newnode;
}

void	tester_ft_lstadd_front(t_list **lst, t_list *newnode)
{
	if (!lst)
		return (tester_ft_err_nonnull(NULL, -1, __func__));
	if (!newnode)
		return ;
	newnode->next = *lst;
	*lst = newnode;
}
