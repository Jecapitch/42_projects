/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:34:37 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/02 23:08:38 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	join_str = ft_calloc((total_len + 1), sizeof(char));
	if (!join_str)
		return (NULL);
	if (s1)
		ft_strlcpy(join_str, s1, s1_len + 1);
	if (s2)
		ft_strlcpy(join_str + s1_len, s2, s2_len + 1);
	return (join_str);
}

char	*ft_strjoin_sep(const char *s1, const char *s2, const char sep)
{
	char	*join_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	total_len;

	s1_len = ft_strlen(s1) + (sep != '\0');
	s2_len = ft_strlen(s2);
	total_len = s1_len + s2_len;
	join_str = ft_calloc((total_len + 1), sizeof(char));
	if (!join_str)
		return (NULL);
	ft_strlcat(join_str, s1, total_len + 1);
	join_str[s1_len - 1] = sep;
	ft_strlcat(join_str, s2, total_len + 1);
	return (join_str);
}
