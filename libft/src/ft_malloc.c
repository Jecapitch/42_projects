/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 00:19:23 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 19:35:10 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	bytes;

	ptr = NULL;
	bytes = 0;
	if (size && count > SIZE_MAX / size)
		return (NULL);
	bytes = count * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*newptr;

	newptr = NULL;
	if (!ptr)
		return (ft_calloc(new_size, sizeof(char)));
	if (!new_size)
		return (ptr = ft_free_safe(ptr), ft_calloc(1, 1));
	newptr = ft_calloc(new_size, sizeof(char));
	if (!newptr)
		return (ptr = ft_free_safe(ptr), NULL);
	ft_memmove(newptr, ptr, new_size);
	ptr = ft_free_safe(ptr);
	return (newptr);
}
