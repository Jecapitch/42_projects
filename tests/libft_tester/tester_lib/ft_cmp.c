/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 01:11:50 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/16 18:35:26 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

int	tester_ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const t_uchar	*chs1 = (const t_uchar *)s1;
	const t_uchar	*chs2 = (const t_uchar *)s2;

	if (!s1 || !s2)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
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

int	tester_ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
	{
		tester_ft_err_nonnull(NULL, -1, __func__);
		return (-1);
	}
	while (n)
	{
		if (*s1 != *s2 || !(*s1) || !(*s2))
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
