/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s42.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:48:33 by nthys             #+#    #+#             */
/*   Updated: 2025/10/30 10:48:33 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <unistd.h>

size_t	ft_putnbr_base_fd(long n, char *base, int fd)
{
	size_t		size;
	const int	base_size = ft_strlen(base);

	size = 0;
	if (n < 0 && n)
	{
		size += ft_putchar_fd('-', fd);
		if (n == LONG_MIN)
		{
			size += ft_putchar_fd(base[n % base_size], fd);
			n /= base_size;
		}
		n *= -1;
	}
	if (n >= base_size || n <= -base_size)
		size += ft_putnbr_base_fd(n / base_size, base, fd);
	return (size + ft_putchar_fd(base[n % base_size], fd));
}
