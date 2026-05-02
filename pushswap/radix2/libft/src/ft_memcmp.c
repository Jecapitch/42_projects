/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 19:12:18 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_uchar	*chs1 = (const t_uchar *)s1;
	const t_uchar	*chs2 = (const t_uchar *)s2;

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
			return ((unsigned char)*chs1 - (unsigned char)*chs2);
		chs1++;
		chs2++;
		n--;
	}
	return (0);
}
