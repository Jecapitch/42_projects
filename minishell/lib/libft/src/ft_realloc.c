/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:00:23 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/11 02:00:04 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*newptr;
	size_t	size;

	newptr = NULL;
	size = 0;
	if (!ptr)
		return (ft_calloc(size, 1));
	if (!new_size)
		return (ptr = ft_free_safe(ptr), NULL);
	newptr = ft_calloc(new_size, 1);
	if (!newptr)
		return (ptr = ft_free_safe(ptr), NULL);
	if (old_size > new_size)
		size = new_size;
	else
		size = old_size;
	ft_memmove(newptr, ptr, size);
	ptr = ft_free_safe(ptr);
	return (newptr);
}
