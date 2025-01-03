/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/02 23:17:04 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*chs1;
	const unsigned char	*chs2;

	chs1 = (const unsigned char *)s1;
	chs2 = (const unsigned char *)s2;
	while (n)
	{
		if (*chs1 != *chs2)
			return (*chs1 - *chs2);
		chs1++;
		chs2++;
		n--;
	}
	return (0);
}
