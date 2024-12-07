/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:58:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/07 02:24:52 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	bufferize(const char *s, size_t len, t_buf *buffer)
{
	int				written;
	size_t			j;

	written = 0;
	j = 0;
	while (j < len && buffer->print_count != -1)
	{
		buffer->buffer[buffer->len] = *s;
		s++;
		buffer->len++;
		if (buffer->len == BUFFER_SIZE)
		{
			written = write(FD, buffer->buffer, buffer->len);
			if (written != -1)
				buffer->print_count += written;
			else
				buffer->print_count = -1;
			buffer->len = 0;
		}
		j++;
	}
	return (len);
}

static void	ft_toprint(va_list *ptr, t_buf *buffer, t_printf *format)
{
	char	*toprint;

	toprint = ft_conversion(ptr, format);
	if (!toprint)
	{
		buffer->print_count = -1;
		return ;
	}
	ft_end_format(toprint, format);
	ft_end_padding(format);
	while (format->align == RIGHT && format->padding == ' ' \
						&& format->padding_len-- > 0)
		bufferize(" ", 1, buffer);
	bufferize(format->sign, format->sign[0] != '\0', buffer);
	bufferize(format->lead, ft_countwhile(format->lead, '\0'), buffer);
	while ((format->padding == '0' && format->padding_len-- > 0))
		bufferize("0", 1, buffer);
	while (format->precision-- > 0)
		bufferize("0", 1, buffer);
	bufferize(toprint, format->arglen, buffer);
	free(toprint);
	while (format->align == LEFT && format->padding_len-- > 0)
		bufferize(" ", 1, buffer);
}

int	ft_printf(const char *fstr, ...)
{
	t_printf	format;
	t_buf		buffer;
	va_list		ptr;

	va_start(ptr, fstr);
	buffer.len = 0;
	buffer.print_count = 0;
	while (*fstr && buffer.print_count != -1)
	{
		fstr += bufferize(fstr, ft_countwhile(fstr, '%'), &buffer);
		if (*fstr == '%')
			fstr++;
		ft_format(fstr, &format);
		if (ft_isconv(format.conv))
		{
			ft_toprint(&ptr, &buffer, &format);
			fstr += ft_countwhile_set(fstr, FCONV) + 1;
		}
		else if (*fstr)
			bufferize("%", 1, &buffer);
	}
	va_end(ptr);
	if (write(FD, buffer.buffer, buffer.len) == -1)
		return (-1);
	return (buffer.print_count + buffer.len);
}
