/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/25 21:31:27 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_set(const char *s, char *set)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (ft_isset(*s, set))
			return ((char *)s);
		s++;
	}
	if (ft_isset(*s, set))
		return ((char *)s);
	return (NULL);
}
