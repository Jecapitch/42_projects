/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmunbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:10:12 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/10 22:42:58 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmunbr_fd(unsigned int n, int fd)
{
	char	*str;
	size_t	len;

	len = ft_uintlen(n);
	str = ft_calloc(len + 1, sizeof(char));
	str[0] = '0';
	while (n)
	{
		str[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	ft_putstr_fd(str, fd);
	free(str);
}
