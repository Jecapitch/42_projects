/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:42:02 by nthys             #+#    #+#             */
/*   Updated: 2025/10/15 11:42:02 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if (src == NULL && dest == NULL)
		return (NULL);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (d < s)
		while (n-- > 0)
			*d++ = *s++;
	else
	{
		s += n - 1;
		d += n - 1;
		while (n-- > 0)
			*d-- = *s--;
	}
	return (dest);
}
