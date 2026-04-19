/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:00:09 by nthys             #+#    #+#             */
/*   Updated: 2025/10/16 14:00:09 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char		*ptr;
	const unsigned char	ch = (const unsigned char)c;

	ptr = (unsigned char *)s;
	while (n)
	{
		if (*ptr == ch)
			return (ptr);
		++ptr;
		--n;
	}
	return (NULL);
}
