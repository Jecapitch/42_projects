/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_set.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/29 01:45:17 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words_set(const char *s, const char *set)
{
	size_t	n;

	if (!s)
		return (0);
	n = 0;
	while (*s)
	{
		while (*s && ft_iset(*s, set))
			s++;
		if (*s && !ft_isset(*s, set))
			n++;
		while (*s && !fT_isset(*s, set))
			s++;
	}
	return (n);
}
