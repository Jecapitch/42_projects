/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:43:07 by nthys             #+#    #+#             */
/*   Updated: 2026/04/19 18:24:12 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft.h"
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

static int	is_flag(const char c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '0' || c == '-')
		return (1);
	return (0);
}

static int	get_precision(t_flags *flag, const char **fmt)
{
	int	i;

	flag->prec = -1;
	i = 0;
	if (**fmt == '.' && ++i)
	{
		++*fmt;
		flag->prec = ft_atoi(*fmt);
		while (ft_isdigit(**fmt) && ++i)
			++*fmt;
	}
	return (i);
}

static struct s_flags	parse_flag(const char **fmt, int fd)
{
	t_flags	flag;
	int		i;

	i = 0;
	flag.id = 0;
	flag.width = 0;
	flag.fd = fd;
	while (is_flag(**fmt) && ++i)
		++*fmt;
	flag.size = i;
	flag.flags = (char *)*fmt - i;
	if (ft_isdigit(**fmt))
	{
		flag.width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt) && ++i)
			++*fmt;
	}
	i += get_precision(&flag, fmt);
	flag.id = **fmt;
	flag.total_size = i + 1;
	return (flag);
}

int	print_args(int fd, const char **fmt, va_list ap)
{
	const t_flags	flag = parse_flag(fmt, fd);

	if (flag.id == 's')
		return (print_str(va_arg(ap, char *), flag));
	if (flag.id == 'c')
		return (print_char(va_arg(ap, int), flag));
	if (flag.id == '%')
		return (ft_putchar_fd('%', fd));
	if (flag.id == 'd' || flag.id == 'i')
		return (print_int(va_arg(ap, int), flag));
	if (flag.id == 'u')
		return (print_unsigned(va_arg(ap, unsigned int), flag));
	if (flag.id == 'p')
		return (print_ptr(va_arg(ap, unsigned long), flag));
	if (flag.id == 'x')
		return (print_hex(va_arg(ap, unsigned int), flag));
	if (flag.id == 'X')
		return (print_hex(va_arg(ap, unsigned int), flag));
	if (flag.id == 0)
		return (-1);
	return (ft_putchar_fd('%', fd) + write(fd, flag.flags, flag.total_size));
}
