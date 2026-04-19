/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s42.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:16:06 by nthys             #+#    #+#             */
/*   Updated: 2025/11/05 16:16:06 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft.h"

int	add_padding(t_flags flag, int sub, int pos, const char *prefix)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (has_flag(flag, '0') && pos == -1 && flag.prec < 0)
		c = '0';
	flag.prec -= sub;
	if (flag.prec >= 0 && pos == -1)
		sub += flag.prec;
	if (prefix && c == '0')
		i += ft_putstr_fd((char *)prefix, flag.fd);
	else if (prefix)
		i += ft_strlen(prefix);
	if ((!has_flag(flag, '-') && pos == -1)
		|| (has_flag(flag, '-') && pos == 1))
		while (i < flag.width - sub && ++i)
			ft_putchar_fd(c, flag.fd);
	if (prefix && c != '0')
		ft_putstr_fd((char *)prefix, flag.fd);
	if (flag.prec >= 0 && pos == -1)
		while (flag.prec-- > 0 && ++i)
			ft_putchar_fd('0', flag.fd);
	return (i);
}
