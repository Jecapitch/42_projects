/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:39:49 by jpiscice          #+#    #+#             */
/*   Updated: 2024/10/27 16:00:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	ft_atoi(const char *str)
{
	int		n;
	char	sign;
	int		i;

	n = 0;
	i = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (n < 0)
			n = n * 10 - (str[i] - '0');
		else
			n = n * 10 + str[i] - '0';
		i++;
	}
	return (n * sign);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	isneg;
	char	ismin;
	size_t	intlen;

	intlen = ft_intlen(n);
	str = ft_calloc(intlen + 1, sizeof(char));
	if (!str)
		return (NULL);
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
	return (str);
}
