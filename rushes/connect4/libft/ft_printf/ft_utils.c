/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s42.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 16:48:49 by nthys             #+#    #+#             */
/*   Updated: 2025/11/10 16:48:49 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	get_ulong_size(unsigned long n, int base)
{
	int	size;

	size = 0;
	while ((n != 0 || n + size == 0) && ++size)
		n /= base;
	return (size);
}

int	get_uint_size(unsigned int n, int base)
{
	int	size;

	size = 0;
	while ((n != 0 || n + size == 0) && ++size)
		n /= base;
	return (size);
}

int	get_int_size(int n, int base)
{
	int	size;

	size = 0;
	while ((n != 0 || n + size == 0) && ++size)
		n /= base;
	return (size);
}

int	has_flag(t_flags flag, char c)
{
	while (*flag.flags && flag.size--)
		if (*flag.flags++ == c)
			return (1);
	return (0);
}
