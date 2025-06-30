/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mark.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:34:37 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/29 01:49:31 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split_mark(const char *s, const char *mark, const char *set)
{
	char	**splitstr;
	size_t	i;
	size_t	len;

	i = 0;
	splitstr = ft_calloc((ft_count_words_mark(s, mark, set) + 1), \
							sizeof(char *));
	if (!splitstr)
		return (NULL);
	while (s[i])
	{
		while (s[i] && !mark[i] && ft_isset(s[i], set))
			i++;
		if (!s[i])
			break ;
		len = ft_countwhile(&mark[i], '1');
		splitstr[i] = ft_substr(s, 0, len);
		if (!splitstr[i])
		{
			ft_free_all(splitstr);
			return (NULL);
		}
		i += len;
	}
	return (splitstr);
}
