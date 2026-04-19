/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:45:45 by nthys             #+#    #+#             */
/*   Updated: 2025/10/20 14:45:45 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_set(const char c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	size;

	if (s1 == NULL)
		return (NULL);
	while (is_set(*s1, set))
		++s1;
	size = ft_strlen(s1);
	while (is_set(*(s1 + size - 1), set) && size > 0)
		--size;
	return (ft_substr(s1, 0, size));
}
