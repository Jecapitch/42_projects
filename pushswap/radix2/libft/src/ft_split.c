/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:34:37 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/11 20:27:58 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(const char *s, char c)
{
	char	sep[2];

	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	sep[0] = c;
	sep[1] = '\0';
	return (ft_split_set(s, sep));
}

char	**ft_split_set(const char *s, const char *set)
{
	char	**split_str;
	size_t	i;

	if (!s)
		return (ft_err_nonnull(NULL, -1, __func__), NULL);
	split_str = ft_calloc((ft_count_words_set(s, set) + 1), sizeof(char *));
	if (!split_str)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (ft_isset(*s, set))
			s++;
		if (!(*s))
			break ;
		split_str[i] = ft_substr(s, 0, ft_strlen_delim_set(s, set));
		if (!split_str[i++])
		{
			ft_free_str_tab(split_str);
			return (NULL);
		}
		while (*s && !ft_isset(*s, set))
			s++;
	}
	return (split_str);
}
