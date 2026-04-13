/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 12:34:43 by jepiscic         ###   ########.fr       */
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
# include "list.h"
# include "colors.h"

# define PROG_NAME		"libft.a"
# define MAX_INT_LEN	10
# define BASE10			"0123456789"
# define STDIN_FD		STDIN_FILENO
# define STDOUT_FD		STDOUT_FILENO
# define STDERR_FD		STDERR_FILENO

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1028
# endif

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;
typedef unsigned long	t_ulong;
typedef enum e_case		t_case;

extern char				**environ;

enum e_case
{
	LOWER,
	UPPER
};

// CHAR CHECK
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprintable(int c);
int			ft_isspace(int c);
int			ft_isset(int c, const char *set);
int			ft_isset_hash(int c, const int hash[256]);
int			ft_isint(const char *s, const char *base);

// CHAR CASE
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

// STRINGS
size_t		ft_strlen(const char *s);
size_t		ft_strlen_delim(const char *s, const char endc);
size_t		ft_strlen_delim_set(const char *s, const char *endset);
size_t		ft_strlen_condition(const char *s, int (*f)(int));
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_strstrip(const char *s1);
void		*ft_reverse_tab(void *tab, size_t size, size_t elem_size);
size_t		ft_count_words(const char *s, char c);
size_t		ft_count_words_set(const char *s, const char *set);

///splitjoin
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_sep(const char *s1, const char *s2, const char *sep);
int			ft_strappend(char **dest, char *src);
char		**ft_split(const char *s, char c);
char		**ft_split_set(const char *s, const char *set);
char		**ft_split_mark(const char *s, const char *mark, const char *set);

// ARRAY SEARCH
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strchr_set(const char *s, char *set);
char		*ft_strrchr(const char *s, int c);
char		*ft_strrchr_set(const char *s, char *set);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

// ARRAY COPY
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
char		*ft_strldup(const char *s, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_substr(const char *s, t_uint start, size_t len);

// ARRAY COMPARE
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

///// ARRAY ITERATE
char		*ft_strmapi(const char *s, char (*f)(t_uint, char));
void		ft_striteri(char *s, void (*f)(t_uint, char*));

// ARRAY MEMORY
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *ptr, size_t old_size, size_t new_size);
void		ft_free_str_tab(char **arr);
void		*ft_free_safe(void *ptr);

// INT-STR
size_t		ft_number_len(long n);
size_t		ft_number_len_base(long n, t_uint base);
size_t		ft_unumber_len(t_ulong u);
size_t		ft_unumber_len_base(t_ulong n, t_uint base);
int			ft_atoi(const char *str);
long		ft_strtol(const char *s, const char *base);
t_ulong		ft_strtoul(const char *s, const char *base);
char		*ft_itoa(int n);
char		*ft_ltostr(t_ulong n, int base);

// ENVIRONMENT
char		*ft_getenv(char *name);
char		*ft_getenv_val(char *name);
char		*ft_getenv_key(char *name);

// READ FILE
char		*get_next_line(int fd);

// PROCESS
int			ft_getpid(void);

// PRINT
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_base(int nbr, char *base, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putunbr_fd(t_uint n, int fd);

// LOG
void		ft_err_nonnull(const char *file, int line, const char *fct);
void		ft_log(const char *file, int line, const char *func, \
					const char *msg);

#endif
