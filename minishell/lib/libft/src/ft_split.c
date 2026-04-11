/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:34:37 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/23 14:19:27 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *s, char c)
{
	char	**split_str;
	size_t	i;

	if (!s)
		return (NULL);
	split_str = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!split_str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (!(*s))
			break ;
		split_str[i] = ft_substr(s, 0, ft_countwhile(s, c));
		if (!split_str[i++])
		{
			ft_free_str_arr(split_str);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
	}
	return (split_str);
}
