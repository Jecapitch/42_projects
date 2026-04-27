/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 10:25:31 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/27 10:47:04 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"


int main(int c, char **v)
{
	t_lst	*lst = tester_ft_lstcreate((void **)++v, --c);
	t_lst	*node = lst;

	while (node)
	{
		printf("%s -> ", (char *)node->content);
		node = node->next;
	}
	tester_ft_lstclear(&lst, zerochar);
	return (0);
}
