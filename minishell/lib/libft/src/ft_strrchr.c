/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/04 16:22:32 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_found;
	char	ch;

	if (!s)
		return (NULL);
	last_found = NULL;
	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			last_found = (char *)s;
		s++;
	}
	if (*s == ch)
		last_found = (char *)s;
	return (last_found);
}
