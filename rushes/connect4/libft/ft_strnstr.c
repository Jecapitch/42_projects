/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:59:21 by nthys             #+#    #+#             */
/*   Updated: 2025/10/22 13:50:30 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b = big;
	const char	*l = little;
	size_t		tmp_len;

	if (*l == '\0')
		return ((char *)big);
	tmp_len = len;
	while (len > 0)
	{
		if (*l == '\0')
			return ((char *)big);
		if (*b == '\0')
			return (NULL);
		if (*b++ == *l++ && tmp_len)
			continue ;
		tmp_len = --len;
		b = ++big;
		l = little;
	}
	return (NULL);
}
