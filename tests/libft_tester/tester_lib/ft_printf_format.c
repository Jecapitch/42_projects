/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:45:09 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 16:36:47 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

void	tester_init_format(t_printf *format)
{
	format->min_len = 0;
	format->precision = -1;
	format->arglen = 0;
	format->padding_len = 0;
	format->full_len = 0;
	format->align = RIGHT;
	format->conv = 0;
	format->padding = ' ';
	tester_ft_bzero(format->sign, 2);
	tester_ft_bzero(format->lead, 3);
}

char	*tester_ft_conversion(va_list *ptr, t_printf *format)
{
	char	*s;

	s = NULL;
	if (format->conv == 's')
	{
		s = (char *)va_arg(*ptr, const char *);
		if (!s && format->precision < 6 && format->precision > -1)
			s = tester_ft_strdup("");
		else if (!s)
			s = tester_ft_strdup("(null)");
		else
			s = tester_ft_strdup(s);
	}
	else if (format->conv == 'd' || format->conv == 'i')
		s = tester_ft_itoa(va_arg(*ptr, int));
	else if (format->conv == 'c')
		s = tester_chartostr(va_arg(*ptr, int));
	else if (format->conv == '%')
		s = tester_ft_strdup("%");
	else if (format->conv == 'p')
		s = tester_ft_ltostr(va_arg(*ptr, t_ulong), format->conv);
	else if (tester_ft_isset(format->conv, "uxXbBovV"))
		s = tester_ft_ltostr(va_arg(*ptr, t_uint), format->conv);
	return (s);
}

void	tester_ft_format(const char *fstr, t_printf *format)
{
	tester_init_format(format);
	while (*fstr && tester_ft_isflag(*fstr) && *fstr != '.')
	{
		if (*fstr == '-')
			format->align = LEFT;
		else if (*fstr == '#')
			format->lead[0] = '0';
		else if (*fstr == '+' || (*fstr == ' ' && !*fstr))
			format->sign[0] = *fstr;
		else if (*fstr == '0')
			format->padding = '0';
		fstr++;
	}
	if (tester_ft_isdigit(*fstr))
		format->min_len = tester_ft_atoi(fstr);
	fstr += tester_ft_strlen_condition(fstr, &tester_ft_isdigit);
	if (*fstr == '.')
	{
		format->precision = 0;
		fstr++;
		if (tester_ft_isdigit(*fstr))
			format->precision = tester_ft_atoi(fstr);
	}
	fstr += tester_ft_strlen_condition(fstr, &tester_ft_isdigit);
	format->conv = *fstr;
}

void	tester_ft_end_format(char *s, t_printf *format)
{
	if (!tester_ft_isset(format->conv, "sc%") && *s == '0' && !format->precision)
		*s = '\0';
	if (*s && tester_ft_strncmp(s, "0", format->arglen + 1) != 0 \
			&& tester_ft_isset(format->conv, "xXbBvV"))
		format->lead[1] = format->conv;
	else if (s && format->conv == 'p' && tester_ft_strncmp(s, "(nil)", 6) != 0)
		tester_ft_strlcpy(format->lead, "0x", 3);
	else if (s && format->conv == 'o')
		format->lead[1] = '\0';
	else
		tester_ft_bzero(format->lead, 3);
	if (!tester_ft_isset(format->conv, "di"))
		format->sign[0] = '\0';
	else if (*s == '-')
	{
		format->sign[0] = '-';
		tester_ft_memmove(s, s + 1, tester_ft_strlen(s + 1) + 1);
	}
	if (*s && format->conv == 's' && format->precision > -1)
		tester_ft_strlcpy(s, s, format->precision + 1);
	if (format->align == LEFT || format->precision > -1 \
			|| tester_ft_isset(format->conv, "sc%"))
		format->padding = ' ';
	format->arglen = tester_ft_strlen(s);
}

void	tester_ft_end_padding(t_printf *format)
{
	if (format->conv == 'c')
		format->arglen = 1;
	format->full_len = format->arglen;
	if (format->precision > format->arglen && !tester_ft_isset(format->conv, "sc%"))
		format->precision -= format->arglen;
	else
		format->precision = 0;
	if (format->conv == 'o' && format->precision > 0)
		format->lead[0] = '\0';
	format->full_len += (format->precision + (format->sign[0] != '\0') \
						+ tester_ft_strlen(format->lead));
	if (format->min_len > format->full_len && format->conv != '%')
		format->padding_len = format->min_len - format->full_len;
	else
		format->padding_len = 0;
	if (format->precision)
		format->padding = ' ';
}
