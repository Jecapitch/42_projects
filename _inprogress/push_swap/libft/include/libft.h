/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/07 23:30:03 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <inttypes.h>
# include <limits.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}			t_bool;

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
t_bool		ft_isspace(int c); // suppl
t_bool		ft_isset(int c, const char *set); // suppl

// CHAR CASE
int			ft_toupper(int c);
int			ft_tolower(int c);

// STRINGS UTILS
size_t		ft_strlen(const char *s);
size_t		ft_countwhile(const char *s, const char endc); // suppl
size_t		ft_countwhile_set(const char *s, const char *endset); // suppl
size_t		ft_countwhile_condition(const char *s, int (*f)(int));
char		*ft_strtrim(const char *s1, const char *set);
void		ft_arr_reverse(void *arr, size_t size, size_t elem_size); // suppl
size_t		ft_count_words(const char *s, char c); // suppl
int			ft_count_seq(const char *s, int c);
///splitjoin
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(const char *s1, const char *s2);
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
void		ft_free_all(char **arr); // suppl

// INT-STR
size_t		ft_intlen(int n); // suppl
size_t		ft_uintlen(unsigned int u);
size_t		ft_ullen(unsigned long n, unsigned int base);
int			ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_ltostr(unsigned long n, int base);

// FILE
char		*get_next_line(int fd);

// PRINT
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putunbr_fd(unsigned int n, int fd);
void		ft_putmnbr_fd(int n, int fd); // suppl
int			ft_printf(const char *str, ...);

///// LISTS

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_list_double // suppl
{
	void					*content;
	struct s_list_double	*next;
	struct s_list_double	*prev;
}							t_list_2;

typedef struct s_list_start // suppl
{
	void	*first;
	void	*last;
	size_t	size;
}			t_list_start;

// LIST UTILS
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);

// LIST NODES – ADD & DELETE
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *newnode);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
void		ft_lstdelone(t_list *lst, void (*del)(void *));

//LIST ITERATE
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
