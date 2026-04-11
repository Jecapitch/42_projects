/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:40:07 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 06:39:30 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_number_len(long n)
{
	return (ft_number_len_base(n, 10));
}

size_t	ft_unumber_len(unsigned long n)
{
	return (ft_unumber_len_base(n, 10));
}

size_t	ft_number_len_base(long n, unsigned int base)
{
	size_t	len;

	len = n < 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

size_t	ft_unumber_len_base(unsigned long n, unsigned int base)
{
	size_t	len;

	len = 0;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}
