/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:35:37 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/20 00:10:15 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_code(int base)
{
	int	code[26];

	if (base < 36)
		return (base);
	ft_bzero(code, 26);
	base = ft_tolower(base);
	code['u' - 'a'] = 10;
	code['b' - 'a'] = 2;
	code['o' - 'a'] = 8;
	code['x' - 'a'] = 16;
	code['p' - 'a'] = 16;
	code['v' - 'a'] = 20;
	return (code[base - 'a']);
}

char	*ft_ltostr(unsigned long n, int base)
{
	char	a[38];
	char	b[52];
	char	*conv;

	if (!n && base == 'p')
		return (ft_strdup("(nil)"));
	if (!n)
		return (ft_strdup("0"));
	b[51] = '\0';
	conv = b + 50;
	if (ft_isupper(base))
		ft_memcpy(a, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", 36);
	else
		ft_memcpy(a, "0123456789abcdefghijklmnopqrstuvwxyz", 36);
	base = ft_code(base);
	while (n)
	{
		*conv = a[n % base];
		n /= base;
		conv--;
	}
	conv++;
	return (ft_strdup(conv));
}
