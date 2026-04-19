/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ids.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s42.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:37:32 by nthys             #+#    #+#             */
/*   Updated: 2025/10/31 14:37:32 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft.h"
#include <limits.h>

static char	*get_prefix(int n, t_flags flag)
{
	if (flag.id != 'u' && n < 0)
		return ("-");
	else if (flag.id != 'u' && has_flag(flag, '+'))
		return ("+");
	else if (flag.id != 'u' && has_flag(flag, ' '))
		return (" ");
	return (NULL);
}

int	print_unsigned(unsigned int n, t_flags flag)
{
	int			size;
	const int	len = get_uint_size(n, 10);

	size = add_padding(flag, len, -1, NULL);
	if (n > UINT_MAX / 2)
		size += ft_putnbr_fd(n / 10, flag.fd)
			+ ft_putnbr_fd((unsigned int)n % 10, flag.fd);
	else
		size += ft_putnbr_fd(n, flag.fd);
	size += add_padding(flag, size, 1, NULL);
	return (size);
}

static int	print_neg(int n, t_flags flag)
{
	int			size;
	const int	len = get_int_size(n, 10);
	const char	*prefix = get_prefix(n, flag);

	size = add_padding(flag, len, -1, prefix);
	if (n == INT_MIN)
		size += ft_putnbr_fd(-(n / 10), flag.fd)
			+ ft_putnbr_fd(-(n % 10), flag.fd);
	else
		size += ft_putnbr_fd(-n, flag.fd);
	size += add_padding(flag, size, 1, NULL);
	return (size);
}

int	print_int(int n, t_flags flag)
{
	int			size;
	const int	len = get_int_size(n, 10);
	const char	*prefix = get_prefix(n, flag);

	if (n < 0)
		return (print_neg(n, flag));
	size = add_padding(flag, len, -1, prefix);
	size += ft_putnbr_fd(n, flag.fd);
	size += add_padding(flag, size, 1, NULL);
	return (size);
}
