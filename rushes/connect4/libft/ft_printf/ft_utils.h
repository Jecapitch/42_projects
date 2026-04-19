/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:44:37 by nthys             #+#    #+#             */
/*   Updated: 2026/04/19 18:23:18 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdarg.h>

typedef struct s_flags
{
	int		size;
	int		prec;
	int		total_size;
	int		width;
	int		fd;
	char	id;
	char	*flags;
}			t_flags;

// FT_ARGS_C
int			print_args(int fd, const char **fmt, va_list ap);
// FT_UTILS_C
int			get_ulong_size(unsigned long n, int base);
int			get_uint_size(unsigned int n, int base);
int			get_int_size(int n, int base);
int			has_flag(t_flags flag, char c);
// FT_PADDING_C
int			add_padding(t_flags flag, int sub, int pos, const char *prefix);
// FT_INT_C
int			print_unsigned(unsigned int n, t_flags flag);
int			print_int(int n, t_flags flag);
// FT_HEX_C
int			print_ptr(unsigned long n, t_flags flag);
int			print_hex(unsigned int n, t_flags flag);
// FT_CHARS_C
int			print_percent(char c, t_flags flag);
int			print_str(char *str, t_flags flag);
int			print_char(char c, t_flags flag);

#endif // FT_UTILS_H
