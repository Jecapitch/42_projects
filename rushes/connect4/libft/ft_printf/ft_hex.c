/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s42.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:45:15 by nthys             #+#    #+#             */
/*   Updated: 2025/11/10 16:45:15 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft.h"
#include <limits.h>

static char	*get_prefix(long n, t_flags flag)
{
	if (flag.id == 'p' && n != 0)
		return ("0x");
	if (flag.id == 'x' && has_flag(flag, '#') && n != 0)
		return ("0x");
	if (flag.id == 'X' && has_flag(flag, '#') && n != 0)
		return ("0X");
	return (NULL);
}

int	print_ptr(unsigned long n, t_flags flag)
{
	const int	len = get_ulong_size(n, 16);
	const char	*prefix = get_prefix(n, flag);
	int			size;

	if (n == 0)
	{
		flag.prec = -1;
		return (print_str("(nil)", flag));
	}
	size = add_padding(flag, len, -1, prefix);
	if ((long)n == LONG_MIN || n > LONG_MAX)
		size += ft_putnbr_base_fd(n / 16, "0123456789abcdef", flag.fd)
			+ ft_putnbr_base_fd(n % 16, "0123456789abcdef", flag.fd);
	else
		size += ft_putnbr_base_fd(n, "0123456789abcdef", flag.fd);
	size += add_padding(flag, size, 1, NULL);
	return (size);
}

int	print_hex(unsigned int n, t_flags flag)
{
	const int	len = get_ulong_size(n, 16);
	const char	*prefix = get_prefix(n, flag);
	int			size;
	char		*base;

	if (flag.id == 'x')
		base = "0123456789abcdef";
	else if (flag.id == 'X')
		base = "0123456789ABCDEF";
	size = add_padding(flag, len, -1, prefix);
	if (n == 0)
		size += ft_putchar_fd('0', flag.fd);
	else
		size += ft_putnbr_base_fd(n, base, flag.fd);
	size += add_padding(flag, size, 1, NULL);
	return (size);
}
