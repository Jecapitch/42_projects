/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:58:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 16:19:49 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

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

static void	tester_ft_toprint(va_list *ptr, t_buf *buffer, t_printf *format, int fd)
{
	char	*toprint;

	toprint = tester_ft_conversion(ptr, format);
	if (!toprint)
	{
		buffer->print_count = -1;
		return ;
	}
	tester_ft_end_format(toprint, format);
	tester_ft_end_padding(format);
	while (format->align == RIGHT && format->padding == ' ' \
						&& format->padding_len-- > 0)
		bufferize(" ", 1, buffer, fd);
	bufferize(format->sign, format->sign[0] != '\0', buffer, fd);
	bufferize(format->lead, tester_ft_strlen_delim(format->lead, '\0'), buffer, fd);
	while ((format->padding == '0' && format->padding_len-- > 0))
		bufferize("0", 1, buffer, fd);
	while (format->precision-- > 0)
		bufferize("0", 1, buffer, fd);
	bufferize(toprint, format->arglen, buffer, fd);
	free(toprint);
	while (format->align == LEFT && format->padding_len-- > 0)
		bufferize(" ", 1, buffer, fd);
}

int	tester_ft_printf(const char *fstr, ...)
{
	t_printf	format;
	t_buf		buffer;
	va_list		ptr;

	if (!fstr)
		return (tester_ft_err_nonnull(NULL, -1, __func__), -1);
	tester_ft_bzero(&buffer, sizeof(t_buf));
	va_start(ptr, fstr);
	while (*fstr && buffer.print_count != -1)
	{
		fstr += bufferize(fstr, tester_ft_strlen_delim(fstr, '%'), &buffer, STDIN_FD);
		fstr += (*fstr == '%');
		tester_ft_format(fstr, &format);
		if (tester_ft_isconv(format.conv))
		{
			tester_ft_toprint(&ptr, &buffer, &format, STDIN_FD);
			fstr += tester_ft_strlen_delim_set(fstr, FCONV) + 1;
		}
		else if (*fstr)
			bufferize("%", 1, &buffer, STDIN_FD);
	}
	va_end(ptr);
	if (write(STDIN_FD, buffer.buffer, buffer.len) == -1)
		return (-1);
	return (buffer.print_count + buffer.len);
}
