/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:14:23 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 13:21:39 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# define FCONV			"sdipucxXbBovV%"
# define FFLAGS			"-+.0# "

typedef enum e_align
{
	RIGHT,
	LEFT
}			t_align;

typedef struct s_buf			t_buf;
typedef struct s_print_format	t_printf;

struct s_buf
{
	char	buffer[BUFFER_SIZE];
	size_t	len;
	int		print_count;
};

struct s_print_format
{
	int		min_len;
	int		precision;
	int		arglen;
	int		padding_len;
	int		full_len;
	t_align	align;
	char	*flags;
	char	conv;
	char	padding;
	char	sign[2];
	char	lead[3];
};

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_base(int nbr, char *base, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr_fd(t_uint n, int fd);
int		ft_isflag(int c);
int		ft_isconv(int c);
char	*chartostr(int c);
void	init_format(t_printf *format);
void	ft_format(const char *fstr, t_printf *format);
char	*ft_conversion(va_list *ptr, t_printf *format);
void	ft_end_format(char *s, t_printf *format);
void	ft_end_padding(t_printf *format);
int		ft_printf(const char *fstr, ...);
int		ft_fprintf(int fd, const char *fstr, ...);
int		ft_print_tab(void *arr, int data_type, \
					const char sep[], size_t arr_size);
void	ft_fill_line(size_t len, size_t maxlen, int fill, int end);

#endif /*FT_PRINTF_H*/
