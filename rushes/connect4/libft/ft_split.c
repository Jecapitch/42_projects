/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:03:48 by nthys             #+#    #+#             */
/*   Updated: 2025/07/22 14:24:54 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		if (*s != c)
		{
			size++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (size);
}

static char	**set_split(char **split, char const *s, char c)
{
	size_t	size;

	while (*s)
	{
		size = 0;
		if (*s != c)
		{
			while (*s && *s != c)
			{
				++s;
				++size;
			}
			s -= size;
			*split = (char *)malloc((size + 1) * sizeof(char));
			if (*split == NULL)
				return (NULL);
			(void)ft_strlcpy(*split, s, size + 1);
			while (*s && *s != c)
				++s;
			++split;
		}
		else
			s++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	size;

	if (s == NULL)
		return (NULL);
	size = count_words(s, c);
	split = (char **)ft_calloc(sizeof(char *), size + 1);
	if (split == NULL)
		return (NULL);
	if (set_split(split, s, c) == NULL)
	{
		size = 0;
		while (*split)
		{
			free(*split++);
			++size;
		}
		free(split - size);
		return (NULL);
	}
	return (split);
}
