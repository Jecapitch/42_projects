/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 10:46:09 by nthys             #+#    #+#             */
/*   Updated: 2025/10/15 10:46:09 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s = src;
	size_t		n;

	d = dst;
	n = size;
	if (n != 0)
		while (--n != 0 && *s)
			*d++ = *s++;
	if (size != 0)
		*d = '\0';
	while (*s++)
		;
	return (s - src - 1);
}
