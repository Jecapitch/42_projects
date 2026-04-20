/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:59:38 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 04:05:00 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

size_t	tester_ft_count_words(const char *s, char c)
{
	size_t	n;

	if (!s)
		return (0);
	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

size_t	tester_ft_count_words_set(const char *s, const char *set)
{
	size_t	n;

	if (!s)
		return (0);
	n = 0;
	while (*s)
	{
		while (tester_ft_isset(*s, set))
			s++;
		if (*s)
			n++;
		while (*s && !tester_ft_isset(*s, set))
			s++;
	}
	return (n);
}
