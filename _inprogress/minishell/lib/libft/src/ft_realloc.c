/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:00:23 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/09 21:08:34 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*newptr;

	newptr = NULL;
	if (!size)
		size = 1;
	newptr = ft_calloc(1, size);
	if (!newptr)
		return (NULL);
	ft_memcpy(newptr, ptr, size);
	ft_free_nul(ptr);
	return (newptr);
}
