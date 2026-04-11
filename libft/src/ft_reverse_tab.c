/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 05:49:44 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_reverse_tab(void *tab, size_t size, size_t elem_size)
{
	size_t			left;
	size_t			right;
	unsigned char	tmp[64];
	unsigned char	*ptr;

	if (!tab || size < 2 || elem_size == 0
		|| size < elem_size || size % elem_size != 0)
		return (tab);
	ptr = (unsigned char *)tab;
	left = 0;
	right = size - elem_size;
	while (left < right)
	{
		ft_memcpy(tmp, ptr + left, elem_size);
		ft_memcpy(ptr + left, ptr + right, elem_size);
		ft_memcpy(ptr + right, tmp, elem_size);
		left += elem_size;
		right -= elem_size;
	}
	return (tab);
}
