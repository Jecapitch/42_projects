/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 19:35:26 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stddef.h>
# include <inttypes.h>
# include <limits.h>
# include "def.h"
# include "string.h"
# include "ft_printf.h"
# include "list.h"

# define PROG_NAME		"libft.a"

/* CHAR CHECK */
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprintable(int c);
int			ft_isspace(int c);
int			ft_isset(int c, const char *set);
int			ft_isset_hash(int c, const int hash[256]);
int			ft_isnum(const char *s);
int			ft_isint(const char *s);

/* CHAR CASE */
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/* TAB */
void		*ft_reverse_tab(void *tab, size_t size, size_t elem_size);
void		ft_free_str_tab(char **arr);

/* ALLOC */
void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *ptr, size_t new_size);
void		*ft_free_safe(void *ptr);

/* INT-STR */
size_t		ft_number_len(long n);
size_t		ft_number_len_base(long n, t_uint base);
size_t		ft_unumber_len(t_ulong u);
size_t		ft_unumber_len_base(t_ulong n, t_uint base);
int			ft_atoi(const char *str);
long		ft_strtol(const char *s, const char *base);
t_ulong		ft_strtoul(const char *s, const char *base);
char		*ft_itoa(int n);
char		*ft_ltostr(t_ulong n, int base);

/* ENVIRONMENT */
char		*ft_getenv(const char *name);

/* READ FILE */
char		*get_next_line(int fd);

/* PROCESS */
int			ft_getpid(void);

/* PRINT */

/* LOG */
void		ft_err_nonnull(const char *file, int line, const char *fct);
void		ft_log(const char *file, int line, const char *func, \
					const char *msg);

#endif /* LIBFT_H */
