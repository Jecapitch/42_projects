/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_reverse_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 12:39:05 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

void	*tester_ft_reverse_tab(void *tab, size_t size, size_t elem_size)
{
	size_t	left;
	size_t	right;
	t_uchar	tmp[64];
	t_uchar	*ptr;

	if (!tab || size < 2 || elem_size == 0
		|| size < elem_size || size % elem_size != 0)
		return (tab);
	ptr = (t_uchar *)tab;
	left = 0;
	right = size - elem_size;
	while (left < right)
	{
		tester_ft_memcpy(tmp, ptr + left, elem_size);
		tester_ft_memcpy(ptr + left, ptr + right, elem_size);
		tester_ft_memcpy(ptr + right, tmp, elem_size);
		left += elem_size;
		right -= elem_size;
	}
	return (tab);
}
