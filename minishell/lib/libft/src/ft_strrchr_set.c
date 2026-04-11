/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/25 21:33:28 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr_set(const char *s, char *set)
{
	char	*last_found;

	if (!s)
		return (NULL);
	last_found = NULL;
	while (*s)
	{
		if (ft_isset(*s, set))
			last_found = (char *)s;
		s++;
	}
	if (ft_isset(*s, set))
		last_found = (char *)s;
	return (last_found);
}
