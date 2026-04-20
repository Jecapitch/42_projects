/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_libft.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/20 17:37:30 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_LIBFT_H
# define TESTER_LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <inttypes.h>
# include <limits.h>
# include <stdarg.h>

# define TEST_NAME		"libtest.a"
# define MAX_INT_LEN	10
# define BASE10			"0123456789"
# define STDIN_FD		STDIN_FILENO
# define STDOUT_FD		STDOUT_FILENO
# define STDERR_FD		STDERR_FILENO

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1028
# endif

# ifndef MAX_FD
#  define MAX_FD		4096
# endif

typedef unsigned int			t_uint;
typedef unsigned char			t_uchar;
typedef unsigned long			t_ulong;

/* CHAR CHECK */
int			tester_ft_isalpha(int c);
int			tester_ft_isdigit(int c);
int			tester_ft_isalnum(int c);
int			tester_ft_isascii(int c);
int			tester_ft_isprint(int c);
int			tester_ft_isspace(int c);
int			tester_ft_isset(int c, const char *set);
int			tester_ft_isset_hash(int c, const int hash[256]);
int			tester_ft_isint(const char *s, const char *base);

/* CHAR CASE */
int			tester_ft_isupper(int c);
int			tester_ft_islower(int c);
int			tester_ft_toupper(int c);
int			tester_ft_tolower(int c);

/* STRINGS */
size_t		tester_ft_strlen(const char *s);
size_t		tester_ft_strlen_delim(const char *s, const char endc);
size_t		tester_ft_strlen_delim_set(const char *s, const char *endset);
size_t		tester_ft_strlen_condition(const char *s, int (*f)(int));
char		*tester_ft_strtrim(const char *s1, const char *set);
char		*tester_ft_strstrip(const char *s1);
void		*tester_ft_reverse_tab(void *tab, size_t size, size_t elem_size);
size_t		tester_ft_count_words(const char *s, char c);
size_t		tester_ft_count_words_set(const char *s, const char *set);

/* /splitjoin */
size_t		tester_ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*tester_ft_strjoin(const char *s1, const char *s2);
char		*tester_ft_strjoin_sep(const char *s1, const char *s2, const char *sep);
int			tester_ft_strappend(char **dest, char *src);
char		**tester_ft_split(const char *s, char c);
char		**tester_ft_split_set(const char *s, const char *set);
char		**tester_ft_split_mark(const char *s, const char *mark, const char *set);

/* ARRAY SEARCH */
void		*tester_ft_memchr(const void *s, int c, size_t n);
char		*tester_ft_strchr(const char *s, int c);
char		*tester_ft_strchr_set(const char *s, char *set);
char		*tester_ft_strrchr(const char *s, int c);
char		*tester_ft_strrchr_set(const char *s, char *set);
char		*tester_ft_strnstr(const char *haystack, const char *needle, size_t len);

/* ARRAY COPY */
size_t		tester_ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*tester_ft_strdup(const char *s1);
char		*tester_ft_strldup(const char *s, size_t len);
void		*tester_ft_memcpy(void *dst, const void *src, size_t n);
void		*tester_ft_memmove(void *dst, const void *src, size_t len);
char		*tester_ft_substr(const char *s, t_uint start, size_t len);

/* ARRAY COMPARE */
int			tester_ft_strncmp(const char *s1, const char *s2, size_t n);
int			tester_ft_memcmp(const void *s1, const void *s2, size_t n);

/* /// ARRAY ITERATE */
char		*tester_ft_strmapi(const char *s, char (*f)(t_uint, char));
void		tester_ft_striteri(char *s, void (*f)(t_uint, char*));

/* ARRAY MEMORY */
void		tester_ft_bzero(void *s, size_t n);
void		*tester_ft_memset(void *b, int c, size_t len);
void		*tester_ft_calloc(size_t count, size_t size);
void		*tester_ft_realloc(void *ptr, size_t old_size, size_t new_size);
void		tester_ft_free_str_tab(char **arr);
void		*tester_ft_free_safe(void *ptr);

/* INT-STR */
size_t		tester_ft_number_len(long n);
size_t		tester_ft_number_len_base(long n, t_uint base);
size_t		tester_ft_unumber_len(t_ulong u);
size_t		tester_ft_unumber_len_base(t_ulong n, t_uint base);
int			tester_ft_atoi(const char *str);
long		tester_ft_strtol(const char *s, const char *base);
t_ulong		tester_ft_strtoul(const char *s, const char *base);
char		*tester_ft_itoa(int n);
char		*tester_ft_ltostr(t_ulong n, int base);

/* ENVIRONMENT */
char		*tester_ft_getenv(char *name);
char		*tester_ft_getenv_val(char *name);
char		*tester_ft_getenv_key(char *name);

/* READ FILE */
char		*get_next_line(int fd);

/* PROCESS */
int			tester_ft_getpid(void);

/* PRINT */
void		tester_ft_putchar_fd(char c, int fd);
void		tester_ft_putstr_fd(char *s, int fd);
void		tester_ft_putendl_fd(char *s, int fd);
void		tester_ft_putnbr_base(int nbr, char *base, int fd);
void		tester_ft_putnbr_fd(int n, int fd);
void		tester_ft_putunbr_fd(t_uint n, int fd);

/* LOG */
void		tester_ft_err_nonnull(const char *file, int line, const char *fct);
void		tester_ft_log(const char *file, int line, const char *func, \
					const char *msg);

# ifndef LIST_H
#  define LIST_H

typedef struct s_list			t_list;

struct s_list
{
	void	*content;
	t_list	*next;
};

/* LIST UTILS */
int			tester_ft_lstsize(t_list *lst);
t_list		*tester_ft_lstlast(t_list *lst);

/* LIST ADD */
t_list		*tester_ft_lstnew(void *content);
void		tester_ft_lstadd_front(t_list **lst, t_list *newnode);
void		tester_ft_lstadd_back(t_list **lst, t_list *newnode);

/* LIST DELETE */
void		tester_ft_lstdelone(t_list *lst, void (*del)(void *));
void		tester_ft_lstclear(t_list **lst, void (*del)(void *));

/* LIST ITERATE */
void		tester_ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*tester_ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

# endif /*LIST_H*/

# ifndef FT_PRINTF_H
#  define FT_PRINTF_H
#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE	1024
#  endif
#  define FCONV			"sdipucxXbBovV%"
#  define FFLAGS		"-+.0# "

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

int			tester_ft_isflag(int c);
int			tester_ft_isconv(int c);
char		*tester_chartostr(int c);
void		tester_init_format(t_printf *format);
void		tester_ft_format(const char *fstr, t_printf *format);
char		*tester_ft_conversion(va_list *ptr, t_printf *format);
void		tester_ft_end_format(char *s, t_printf *format);
void		tester_ft_end_padding(t_printf *format);
int			tester_ft_printf(const char *fstr, ...);
int			tester_ft_fprintf(int fd, const char *fstr, ...);

# endif /*FT_PRINTF*/

# ifndef COLOR_H
#  define COLOR_H

/*
 * This is free and unencumbered software released into the public domain.
 *
 * For more information, please refer to <https://unlicense.org>

source:  https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
 */

/* Regular text */
#  define BLK "\e[0;30m"
#  define RED "\e[0;31m"
#  define GRN "\e[0;32m"
#  define YEL "\e[0;33m"
#  define BLU "\e[0;34m"
#  define MAG "\e[0;35m"
#  define CYN "\e[0;36m"
#  define WHT "\e[0;37m"

/* Regular bold text */
#  define BBLK "\e[1;30m"
#  define BRED "\e[1;31m"
#  define BGRN "\e[1;32m"
#  define BYEL "\e[1;33m"
#  define BBLU "\e[1;34m"
#  define BMAG "\e[1;35m"
#  define BCYN "\e[1;36m"
#  define BWHT "\e[1;37m"

/* Regular underline text */
#  define UBLK "\e[4;30m"
#  define URED "\e[4;31m"
#  define UGRN "\e[4;32m"
#  define UYEL "\e[4;33m"
#  define UBLU "\e[4;34m"
#  define UMAG "\e[4;35m"
#  define UCYN "\e[4;36m"
#  define UWHT "\e[4;37m"

/* Regular background */
#  define BLKB "\e[40m"
#  define REDB "\e[41m"
#  define GRNB "\e[42m"
#  define YELB "\e[43m"
#  define BLUB "\e[44m"
#  define MAGB "\e[45m"
#  define CYNB "\e[46m"
#  define WHTB "\e[47m"

/* High intensty text */
#  define HBLK "\e[0;90m"
#  define HRED "\e[0;91m"
#  define HGRN "\e[0;92m"
#  define HYEL "\e[0;93m"
#  define HBLU "\e[0;94m"
#  define HMAG "\e[0;95m"
#  define HCYN "\e[0;96m"
#  define HWHT "\e[0;97m"

/* Bold high intensity text */
#  define BHBLK "\e[1;90m"
#  define BHRED "\e[1;91m"
#  define BHGRN "\e[1;92m"
#  define BHYEL "\e[1;93m"
#  define BHBLU "\e[1;94m"
#  define BHMAG "\e[1;95m"
#  define BHCYN "\e[1;96m"
#  define BHWHT "\e[1;97m"

/* Reset */
#  define RESET "\e[0m"
#  define CRESET "\e[0m"
#  define COLOR_RESET "\e[0m"

# endif /*COLOR_H*/

#endif /*LIBFT_H*/
