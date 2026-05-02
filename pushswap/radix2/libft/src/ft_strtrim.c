/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 19:30:04 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	char	*trimmed;
	size_t	len;

	len = 0;
	trimmed = NULL;
	if (!s || !set)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	if (!(*set))
		return (ft_strdup(s));
	while (ft_isset(*s, set))
		s++;
	len = ft_strlen(s);
	while (len && ft_isset(s[len - 1], set))
		len--;
	trimmed = ft_strldup(s, len);
	return (trimmed);
}

char	*ft_strstrip(const char *s)
{
	return (ft_strtrim(s, " \n\t\r\v\f"));
}
