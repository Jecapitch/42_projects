/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:39:49 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 05:52:27 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	long	ln;

	ln = n;
	str = ft_calloc(16, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	if (n < 0)
		ln *= -1;
	i = 0;
	while (ln)
	{
		str[i] = ln % 10 + '0';
		ln /= 10;
		i++;
	}
	if (n < 0)
		str[i++] = '-';
	return (ft_reverse_tab(str, i, sizeof(char)));
}
