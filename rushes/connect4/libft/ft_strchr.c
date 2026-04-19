/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:42:41 by nthys             #+#    #+#             */
/*   Updated: 2025/10/16 10:42:41 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	ch = (const char)c;
	const char	*end = s + ft_strlen(s);

	while (s <= end)
	{
		if (*s == ch)
			return ((char *)s);
		++s;
	}
	return (NULL);
}
