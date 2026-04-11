/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:58:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/11 22:16:58 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	bufferize(const char *s, size_t len, t_buf *buffer, int fd)
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
			written = write(fd, buffer->buffer, buffer->len);
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

static void	ft_toprint(va_list *ptr, t_buf *buffer, t_printf *format, int fd)
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
		bufferize(" ", 1, buffer, fd);
	bufferize(format->sign, format->sign[0] != '\0', buffer, fd);
	bufferize(format->lead, ft_strlen_delim(format->lead, '\0'), buffer, fd);
	while ((format->padding == '0' && format->padding_len-- > 0))
		bufferize("0", 1, buffer, fd);
	while (format->precision-- > 0)
		bufferize("0", 1, buffer, fd);
	bufferize(toprint, format->arglen, buffer, fd);
	free(toprint);
	while (format->align == LEFT && format->padding_len-- > 0)
		bufferize(" ", 1, buffer, fd);
}

int	ft_fprintf(int fd, const char *fstr, ...)
{
	t_printf	format;
	t_buf		buffer;
	va_list		ptr;

	if (!fstr)
		return (ft_err_nonnull(NULL, -1, __func__), -1);
	ft_bzero(&buffer, sizeof(t_buf));
	va_start(ptr, fstr);
	while (*fstr && buffer.print_count != -1)
	{
		fstr += bufferize(fstr, ft_strlen_delim(fstr, '%'), &buffer, fd);
		fstr += (*fstr == '%');
		ft_format(fstr, &format);
		if (ft_isconv(format.conv))
		{
			ft_toprint(&ptr, &buffer, &format, fd);
			fstr += ft_strlen_delim_set(fstr, FCONV) + 1;
		}
		else if (*fstr)
			bufferize("%", 1, &buffer, fd);
	}
	va_end(ptr);
	if (write(fd, buffer.buffer, buffer.len) == -1)
		return (-1);
	return (buffer.print_count + buffer.len);
}
