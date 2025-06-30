/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_mark.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/29 01:53:48 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words_mark(const char *s, const char *mark, const char *set)
{
	size_t	n;
	size_t	i;

	if (!s)
		return (0);
	n = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && mark[i] && ft_isset(s[i], set))
			s++;
		if (s[i] && !mark[i] && !ft_isset(s[i], set))
			n++;
		while (s[i] && !mark[i] && !ft_isset(s[i], set))
			s++;
	}
	return (n);
}
