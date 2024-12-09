/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/02 23:05:09 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimmed;
	size_t	len;

	if (!s1)
	{
		trimmed = ft_calloc(1, sizeof(char));
		return (trimmed);
	}
	if (!set)
		return (ft_strdup(s1));
	while (*s1 && ft_isset(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_isset(s1[len - 1], set))
		len--;
	trimmed = ft_substr(s1, 0, len);
	return (trimmed);
}
