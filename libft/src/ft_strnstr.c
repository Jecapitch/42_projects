/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/11 21:31:37 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	neelen;

	if (!haystack || !needle)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
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
