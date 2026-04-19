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
#include <unistd.h>

static int	add_str_padding(t_flags flag, int sub, int pos)
{
	int		i;

	i = 0;
	if (flag.width - sub < 0)
		return (0);
	if ((has_flag(flag, '-') && pos == 0)
		|| (!has_flag(flag, '-') && pos == -1))
		while (i < flag.width - sub && ++i)
			ft_putchar_fd(' ', flag.fd);
	return (i);
}

int	print_str(char *str, t_flags flag)
{
	int	size;
	int	len;

	if (str == NULL && (flag.prec >= 6 || flag.prec < 0))
		str = "(null)";
	else if (str == NULL)
		str = "";
	len = ft_strlen(str);
	if (flag.prec < len && flag.prec >= 0)
		len = flag.prec;
	size = add_str_padding(flag, len, -1);
	size += write(flag.fd, str, len);
	size += add_str_padding(flag, len, 0);
	return (size);
}

int	print_percent(char c, t_flags flag)
{
	return (ft_putchar_fd(c, flag.fd));
}

int	print_char(char c, t_flags flag)
{
	int	size;

	size = add_str_padding(flag, 1, -1);
	size += ft_putchar_fd(c, flag.fd);
	size += add_str_padding(flag, 1, 0);
	return (size);
}
