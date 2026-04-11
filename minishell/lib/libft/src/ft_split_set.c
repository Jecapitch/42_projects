/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:34:37 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/29 01:48:19 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_set(const char *s, const char *set)
{
	char	**split_str;
	size_t	i;

	if (!s)
		return (NULL);
	split_str = ft_calloc((ft_count_words_set(s, set) + 1), sizeof(char *));
	if (!split_str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_isset(*s, set))
			s++;
		if (!(*s))
			break ;
		split_str[i] = ft_substr(s, 0, ft_countwhile_set(s, set));
		if (!split_str[i++])
		{
			ft_free_str_arr(split_str);
			return (NULL);
		}
		while (*s && !ft_isset(*s, set))
			s++;
	}
	return (split_str);
}
