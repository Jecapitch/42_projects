/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:23:43 by nthys             #+#    #+#             */
/*   Updated: 2025/10/22 10:23:43 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static size_t	getsize(int n)
{
	size_t	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		++count;
	}
	if (n < 0)
		++count;
	while (n <= -10)
	{
		n /= 10;
		++count;
	}
	return (count);
}

static void	buf_putnbr(char *s, int n, size_t size)
{
	char	buff;

	if (n >= 10)
	{
		buf_putnbr(s, n / 10, size - 1);
		n %= 10;
	}
	buff = n + '0';
	*(s + size - 1) = buff;
}

char	*ft_itoa(int n)
{
	char	*s;
	size_t	size;

	size = getsize(n);
	s = (char *)malloc((size + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	if (n == INT_MIN)
	{
		(void)ft_strlcpy(s, "-2147483648", 12);
		return (s);
	}
	if (n < 0)
	{
		*s = '-';
		buf_putnbr(s + 1, n * -1, size - 1);
	}
	else
		buf_putnbr(s, n, size);
	*(s + size) = '\0';
	return (s);
}
