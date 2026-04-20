/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_ltostr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:35:37 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/20 00:10:15 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

static int	tester_ft_code(int base)
{
	int	code[26];

	if (base < 36)
		return (base);
	tester_ft_bzero(code, 26);
	base = tester_ft_tolower(base);
	code['u' - 'a'] = 10;
	code['b' - 'a'] = 2;
	code['o' - 'a'] = 8;
	code['x' - 'a'] = 16;
	code['p' - 'a'] = 16;
	code['v' - 'a'] = 20;
	return (code[base - 'a']);
}

char	*tester_ft_ltostr(t_ulong n, int base)
{
	char	a[38];
	char	b[52];
	char	*conv;

	if (!n && base == 'p')
		return (tester_ft_strdup("(nil)"));
	if (!n)
		return (tester_ft_strdup("0"));
	b[51] = '\0';
	conv = b + 50;
	if (tester_ft_isupper(base))
		tester_ft_memcpy(a, "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ", 36);
	else
		tester_ft_memcpy(a, "0123456789abcdefghijklmnopqrstuvwxyz", 36);
	base = tester_ft_code(base);
	while (n)
	{
		*conv = a[n % base];
		n /= base;
		conv--;
	}
	conv++;
	return (tester_ft_strdup(conv));
}
