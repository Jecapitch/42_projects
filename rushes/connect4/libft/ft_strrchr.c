/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:55:47 by nthys             #+#    #+#             */
/*   Updated: 2025/10/16 10:55:47 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr = s + ft_strlen(s);
	const char	byte = (char) c;

	while (ptr >= s)
	{
		if (*ptr == byte)
			return ((char *)ptr);
		--ptr;
	}
	return (NULL);
}
