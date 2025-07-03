/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/25 07:10:48 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstrip(const char *s1)
{
	char	*stripped;
	size_t	len;

	if (!s1)
	{
		stripped = ft_calloc(1, sizeof(char));
		return (stripped);
	}
	while (*s1 && ft_isspace(*s1))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && ft_isspace(s1[len - 1]))
		len--;
	stripped = ft_substr(s1, 0, len);
	return (stripped);
}
