/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:52:48 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/18 11:01:04 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_ullen(unsigned long n, unsigned int base)
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
