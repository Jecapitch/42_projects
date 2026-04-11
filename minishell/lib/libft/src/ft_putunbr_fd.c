/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:10:12 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/19 12:20:34 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	str[10];
	char	*conv;

	str[9] = '\0';
	str[8] = '0';
	conv = str + 8 - (!n);
	while (n)
	{
		*conv = n % 10 + '0';
		n /= 10;
		conv--;
	}
	conv++;
	write(fd, conv, ft_strlen(conv));
}
