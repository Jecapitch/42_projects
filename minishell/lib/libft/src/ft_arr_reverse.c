/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/02 23:05:44 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arr_reverse(void *arr, size_t arr_size, size_t elem_size)
{
	size_t			i;
	size_t			end_i;
	unsigned char	*tmp;
	unsigned char	*arrptr;

	if (!arr || arr_size < 2 || elem_size == 0
		|| arr_size < elem_size || arr_size % elem_size != 0)
		return ;
	arrptr = (unsigned char *)arr;
	tmp = malloc(elem_size);
	if (!tmp)
		return ;
	i = 0;
	end_i = arr_size - elem_size;
	while (i < end_i)
	{
		ft_memcpy(tmp, arrptr + i, elem_size);
		ft_memcpy(arrptr + i, arrptr + end_i, elem_size);
		ft_memcpy(arrptr + end_i, tmp, elem_size);
		i += elem_size;
		end_i -= elem_size;
	}
	free(tmp);
}
