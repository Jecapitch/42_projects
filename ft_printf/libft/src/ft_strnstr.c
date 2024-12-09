/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/02 23:12:35 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	neelen;

	if (!haystack || !needle)
		return (NULL);
	neelen = ft_strlen(needle);
	if (!neelen)
		return ((char *)haystack);
	while (*haystack && len >= neelen)
	{
		if (ft_strncmp(haystack, needle, neelen) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
