/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 00:19:23 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/11 00:48:20 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int c, size_t len)
{
	t_uchar	*byte;

	if (!p)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return (NULL);
	}
	byte = (t_uchar *)p;
	while (len)
	{
		*byte = (t_uchar)c;
		byte++;
		len--;
	}
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return ;
	}
	ft_memset(s, 0, n);
}
