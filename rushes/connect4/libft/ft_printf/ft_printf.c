/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:29:13 by nthys             #+#    #+#             */
/*   Updated: 2026/04/19 18:23:48 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "libft.h"
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	char	*next;
	int		size;
	int		arg_size;

	if (format == NULL)
		return (-1);
	next = ft_strchr(format, '%');
	size = 0;
	while (next)
	{
		size += next - format;
		format += write(fd, format, next - format) + 1;
		arg_size = print_args(fd, &format, ap);
		if (arg_size < 0)
			return (-1);
		size += arg_size;
		next = ft_strchr(++format, '%');
	}
	next = ft_strchr(format, '\0');
	size += next - format;
	format += write(fd, format, next - format);
	return (size);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		size;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	size = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (size);
}

int	ft_vprintf(const char *format, va_list ap)
{
	return (ft_vdprintf(1, format, ap));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		size;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	size = ft_vprintf(format, ap);
	va_end(ap);
	return (size);
}
