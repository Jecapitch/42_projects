/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:39:49 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/23 01:11:04 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	long	ln;
	size_t	intlen;

	ln = n;
	intlen = ft_intlen(n);
	str = ft_calloc(intlen + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	if (n < 0)
	{
		ln = -ln;
		str[0] = '-';
	}
	while (ln)
	{
		str[intlen - 1] = ln % 10 + '0';
		ln /= 10;
		intlen--;
	}
	return (str);
}
