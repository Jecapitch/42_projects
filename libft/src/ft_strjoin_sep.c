/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:34:37 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 23:33:21 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sep(const char *s1, const char *s2, const char *sep)
{
	char	*join_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	sep_len;
	size_t	total_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	sep_len = ft_strlen(sep);
	total_len = s1_len + s2_len + sep_len + 1;
	join_str = ft_calloc((total_len), sizeof(char));
	if (!join_str)
		return (NULL);
	ft_strlcpy(join_str, s1, total_len);
	ft_strlcpy(join_str + s1_len, sep, total_len);
	ft_strlcat(join_str + s1_len + sep_len, s2, total_len);
	return (join_str);
}
