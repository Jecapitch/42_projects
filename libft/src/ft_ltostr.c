/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:35:37 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 19:03:07 by jepiscic         ###   ########.fr       */
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

char	*ft_ltostr(t_ulong n, int base)
{
	char	*b;
	char	a[52];
	char	*conv;

	if (!n && base == 'p')
		return (ft_strdup("(nil)"));
	if (!n)
		return (ft_strdup("0"));
	a[51] = '\0';
	conv = a + 50;
	if (ft_isupper(base))
		b = BASE36_UP;
	else
		b = BASE36_LOW;
	base = ft_code(base);
	while (n)
	{
		*conv = b[n % base];
		n /= base;
		conv--;
	}
	conv++;
	return (ft_strdup(conv));
}
