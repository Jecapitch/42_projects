/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 04:35:37 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/19 12:09:19 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a[12];
	char	*conv;
	int		isneg;
	long	ln;

	isneg = n < 0;
	ln = n;
	if (isneg)
		ln = -ln;
	a[10] = '0';
	a[11] = '\0';
	conv = a + 10 - (!n);
	while (ln)
	{
		*conv = ln % 10 + '0';
		ln /= 10;
		conv--;
	}
	if (isneg)
		*conv = '-';
	else
		conv++;
	write(fd, conv, ft_strlen(conv));
}
