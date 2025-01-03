/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:10:12 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/02 23:31:27 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmnbr_fd(int n, int fd)
{
	char	*str;
	char	isneg;
	char	ismin;
	size_t	intlen;

	intlen = ft_intlen(n);
	str = ft_calloc(intlen + 1, sizeof(char));
	isneg = (n < 0);
	ismin = (n == INT_MIN);
	n += ismin;
	if (isneg)
		n = -n;
	str[0] = '0';
	while (n)
	{
		str[intlen - 1] = n % 10 + ismin + '0';
		n /= 10;
		ismin = 0;
		intlen--;
	}
	if (isneg)
		str[0] = '-';
	ft_putstr_fd(str, fd);
	free(str);
}
