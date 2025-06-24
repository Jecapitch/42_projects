/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_sp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/25 00:51:34 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_sp(const char *s1)
{
	char	*trimmed;
	size_t	len;

	if (!s1)
	{
		trimmed = ft_calloc(1, sizeof(char));
		return (trimmed);
	}
	while (*s1 && ft_isspace(*s1))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_isspace(s1[len - 1]))
		len--;
	trimmed = ft_substr(s1, 0, len);
	return (trimmed);
}
