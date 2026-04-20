/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 23:42:49 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 04:31:22 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

void	*tester_ft_free_safe(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	tester_ft_free_str_tab(char **arr)
{
	t_uint	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		arr[i] = tester_ft_free_safe(arr[i]);
		i++;
	}
	arr = tester_ft_free_safe(arr);
}
