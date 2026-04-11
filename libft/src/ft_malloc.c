/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 00:19:23 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 04:10:46 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	bytes;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	bytes = count * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}

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
