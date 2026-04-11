/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/11 00:46:04 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*chs1 = (const unsigned char *)s1;
	const unsigned char	*chs2 = (const unsigned char *)s2;

	if (!s1 || !s2)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (-1);
	}
	if (!n || s1 == s2)
		return (0);
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
