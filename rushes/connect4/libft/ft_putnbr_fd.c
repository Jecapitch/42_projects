/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s42.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:02:20 by nthys             #+#    #+#             */
/*   Updated: 2025/10/24 12:02:20 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <limits.h>

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t	size;

	size = 0;
	if (n == INT_MIN)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		size += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n >= 10)
		size += ft_putnbr_fd(n / 10, fd);
	return (size + ft_putchar_fd(n % 10 + '0', fd));
}
