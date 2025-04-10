/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/02 13:42:39 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <inttypes.h>
# include <limits.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "lists.h"
# include "colors.h"

# ifndef STDIN
#  define STDIN		0
# endif
# ifndef STDOUT
#  define STDOUT	1
# endif
# ifndef STDERR
#  define STDERR	2
# endif

typedef enum e_case
{
	LOWER,
	UPPER
}			t_case;

// CHAR CHECK
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_isspace(int c);
int			ft_isset(int c, const char *set);
int			ft_isint(char *s);

// CHAR CASE
int			ft_toupper(int c);
int			ft_tolower(int c);

// STRINGS UTILS
size_t		ft_strlen(const char *s);
size_t		ft_countwhile(const char *s, const char endc);
size_t		ft_countwhile_set(const char *s, const char *endset);
size_t		ft_countwhile_condition(const char *s, int (*f)(int));
char		*ft_strtrim(const char *s1, const char *set);
void		ft_arr_reverse(void *arr, size_t size, size_t elem_size);
size_t		ft_count_words(const char *s, char c);
int			ft_count_seq(const char *s, int c);
///splitjoin
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_sep(const char *s1, const char *s2, const char sep);
char		**ft_split(const char *s, char c);

// ARRAY SEARCH
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

// ARRAY COPY
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_substr(const char *s, unsigned int start, size_t len);

// ARRAY COMPARE
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

///// ARRAY ITERATE
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

// ARRAY MEMORY
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		ft_free_all(char **arr);
void		ft_free_nul(void *ptr);

// INT-STR
size_t		ft_intlen(int n);
size_t		ft_intlen_base(int n, int base);
size_t		ft_uintlen(unsigned int u);
size_t		ft_ullen(unsigned long n, unsigned int base);
int			ft_atoi(const char *str);
long		ft_strtol(const char *str);
char		*ft_itoa(int n);
char		*ft_ltostr(unsigned long n, int base);

// ENVIRONMENT
char		*ft_getenv(char *name);
char		*ft_getenv_val(char *name);
char		*ft_getenv_key(char *name);

// READ FILE
char		*get_next_line(int fd);

// PRINT
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putunbr_fd(unsigned int n, int fd);
void		ft_putmnbr_fd(int n, int fd);

#endif
