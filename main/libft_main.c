/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/07 13:42:41 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This long and ugly program (*norminette aux oubliettes, dying of despair*)
checks most functions of the Libft project mandatory part. When possible,
they're compared with their model from libc on consecutive lines.

When needed (e.g. char check, search, copy and compare functions), it tests
several cases, sometimes including edge cases (e.g. ft_split, ft_atoi, ft_itoa).

Don't panic if fsanitizer gets mad. It can come from the values provided in
the tests, e.g. the pointers in standard memcpy. Change them ad lib. to understand
what's happening. If nothing works, then the cause could be your functions.

It's up to you to customize the tests to try your libft.

NB : this was made for MacOs. On Linux, functions non available in libc will crash.
Just comment them and it will be fine.

==================================FUNCTIONS==================================
===================================TESTED====================================

// CHAR CHECK
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);

// CHAR TRANSFORM
int			ft_toupper(int c);
int			ft_tolower(int c);

// STRING UTILS
size_t		ft_strlen(const char *s);
char		*ft_strtrim(const char *s1, const char *set);

// CAT & SPLIT
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

// ARRAY MEMORY
void		*ft_memset(void *b, int c, size_t len);

==================================NOT===================================
=================================TESTED=================================
                (unless you use them in other functions)

// ARRAY MEMORY
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);

// ARRAY ITERATE
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

// LIST UTILS
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);

// LIST ADD & DELETE
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *newnode);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
void		ft_lstdelone(t_list *lst, void (*del)(void *));

//LIST ITERATE
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

*/

#include "libft.h"
#include <stddef.h>
#include <inttypes.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>

void charchecks(void)
{
	ft_putstr_fd("ft_isalpha('a') = ", 1); ft_putnbr_fd(ft_isalpha('a'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isalpha('a') = ", 1); ft_putnbr_fd(isalpha('a'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isalpha('8') = ", 1); ft_putnbr_fd(ft_isalpha('8'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isalpha('8') = ", 1); ft_putnbr_fd(isalpha('8'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isalpha('$') = ", 1); ft_putnbr_fd(ft_isalpha('$'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isalpha('$') = ", 1); ft_putnbr_fd(isalpha('$'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isdigit('a') = ", 1); ft_putnbr_fd(ft_isdigit('a'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isdigit('a') = ", 1); ft_putnbr_fd(isdigit('a'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isdigit('8') = ", 1); ft_putnbr_fd(ft_isdigit('8'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isdigit('8') = ", 1); ft_putnbr_fd(isdigit('8'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isdigit('$') = ", 1); ft_putnbr_fd(ft_isdigit('$'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isdigit('$') = ", 1); ft_putnbr_fd(isdigit('$'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isalnum('a') = ", 1); ft_putnbr_fd(ft_isalnum('a'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isalnum('a') = ", 1); ft_putnbr_fd(isalnum('a'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isalnum('8') = ", 1); ft_putnbr_fd(ft_isalnum('8'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isalnum('8') = ", 1); ft_putnbr_fd(isalnum('8'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isalnum('$') = ", 1); ft_putnbr_fd(ft_isalnum('$'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isalnum('$') = ", 1); ft_putnbr_fd(isalnum('$'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isascii('a') = ", 1); ft_putnbr_fd(ft_isascii('a'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isascii('a') = ", 1); ft_putnbr_fd(isascii('a'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isascii('8') = ", 1); ft_putnbr_fd(ft_isascii('8'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isascii('8') = ", 1); ft_putnbr_fd(isascii('8'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isascii('$') = ", 1); ft_putnbr_fd(ft_isascii('$'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isascii('$') = ", 1); ft_putnbr_fd(isascii('$'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isascii(132) = ", 1); ft_putnbr_fd(ft_isascii(132), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isascii(132) = ", 1); ft_putnbr_fd(isascii(132), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isprint('a') = ", 1); ft_putnbr_fd(ft_isprint('a'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isprint('a') = ", 1); ft_putnbr_fd(isprint('a'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isprint('8') = ", 1); ft_putnbr_fd(ft_isprint('8'), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isprint('8') = ", 1); ft_putnbr_fd(isprint('8'), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);
	
	ft_putstr_fd("ft_isprint(4) = ", 1); ft_putnbr_fd(ft_isprint(4), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("isprint(4) = ", 1); ft_putnbr_fd(isprint(4), 1); ft_putchar_fd('\n', 1);
}

void	transcase(void)
{
	char	a[] = "voici 30 minuscules devenues grandes !";
	char	a2[] = "voici 30 minuscules devenues grandes !";
	char	b[] = "VOICI 22 MAJUSCULES DECHUES...";
	char	b2[] = "VOICI 22 MAJUSCULES DECHUES...";
	int		i;

	ft_putstr_fd("char\ta[] = ", 1); ft_putendl_fd(a, 1);
	ft_putstr_fd("char\tb[] = ", 1); ft_putendl_fd(b, 1);

	ft_putendl_fd("", 1);
	i = 0;
	ft_putstr_fd("ft_toupper(a) = ", 1);
	while (a[i])
	{
		a[i] = ft_toupper(a[i]);
		i++;
	}
	ft_putendl_fd(a, 1);
	i = 0;
	ft_putstr_fd("toupper(a) = ", 1);

	while (a2[i])
	{
		a2[i] = toupper(a[i]);
		i++;
	}
	ft_putendl_fd(a, 1);

	ft_putendl_fd("", 1);

	i = 0;
	ft_putstr_fd("ft_tolower(b) = ", 1);
	while (b[i])
	{
		b[i] = ft_tolower(b[i]);
		i++;
	}
	ft_putendl_fd(b, 1);

	i = 0;
	ft_putstr_fd("tolower(b) = ", 1);
	while (b2[i])
	{
		b2[i] = tolower(b[i]);
		i++;
	}
	ft_putendl_fd(b, 1);
}

void	strings(void)
{
	char	a[] = "Cette phrase a une longueur de 34.";
	char	a2[] = "\"Cette phrase a une longueur de 34.\"";
	char	s[] = "\t ) .Cette phrase n'aurait-elle pas des trucs en trop ?)  \n";
	char	*s = NULL;
	char	s2[] = "\"\\t ) .Cette phrase n'aurait-elle pas des trucs en trop ?)  \\n\"";
	char	*trim;
	char	set[] = " \n\t.)";
	char	set2[] = "\" \\n\\t.)\"";

	ft_putstr_fd("char\ta[] = ", 1); ft_putstr_fd(a2, 1); ft_putendl_fd(";", 1);
	ft_putstr_fd("char\ts[] = ", 1); ft_putstr_fd(s2, 1); ft_putendl_fd(";", 1);
	ft_putstr_fd("char\tset[] = ", 1); ft_putstr_fd(set2, 1); ft_putendl_fd("", 1);
	ft_putendl_fd("char\t*trim;", 1);

	ft_putendl_fd("", 1);

	ft_putstr_fd("ft_strlen(a) = ", 1); ft_putnbr_fd(ft_strlen(a), 1); ft_putchar_fd('\n', 1);
	ft_putstr_fd("strlen(a) = ", 1); ft_putnbr_fd(strlen(a), 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);

	ft_putendl_fd("trim = ft_strtrim(s, set);", 1);
	trim = ft_strtrim(s, set);
	ft_putstr_fd("=> trim = ", 1); ft_putendl_fd(trim, 1);
	free(trim);
	ft_putendl_fd("free(trim);", 1);
}

void	splitjoin(void)
{
	int		i;
	char	a[15] = "Allons-y ";
	char	b[] = "Alonzo !";
	char	a2[15] = "Allons-y ";
	char	b2[] = "Alonzo !";
	size_t	len;	

	ft_putstr_fd("char\ta[15] = \"", 1); ft_putstr_fd(a, 1); ft_putendl_fd("\"", 1);
	ft_putstr_fd("char\tb[] = \"", 1); ft_putstr_fd(b, 1); ft_putendl_fd("\"", 1);

	ft_putendl_fd("", 1);

	len = ft_strlcat(a, b, 12);
	ft_putstr_fd("ft_strlcat(a, b, 12) = ", 1); ft_putendl_fd(a, 1);
	ft_putstr_fd("=> return = ", 1); ft_putnbr_fd(len, 1); ft_putendl_fd("", 1);
	len = ft_strlcat(a2, b2, 12);
	ft_putstr_fd("strlcat(a, b, 12) = ", 1); ft_putendl_fd(a2, 1);
	ft_putstr_fd("=> return = ", 1); ft_putnbr_fd(len, 1); ft_putendl_fd("", 1);
	
	ft_putendl_fd("", 1);

	char	c[] = "mini";
	char 	d[] = "keums";
	char	*j = ft_strjoin(c, d);

	ft_putstr_fd("char\tc[] = \"", 1); ft_putstr_fd(c, 1); ft_putendl_fd("\"", 1);
	ft_putstr_fd("char\td[] = \"", 1); ft_putstr_fd(d, 1); ft_putendl_fd("\"", 1);
	ft_putendl_fd("char\t*j;\n", 1);
	ft_putstr_fd("j = ft_strjoin(c, d) \n=> j = ", 1); ft_putendl_fd(j, 1);
	free(j);
	
	ft_putendl_fd("", 1);

	char	s[] = "Waterloo ! Waterloo ! Waterloo ! Morne plaine...";
	char	s2[] = "";
	char	**w;

	ft_putstr_fd("char	s[] = \"", 1); ft_putstr_fd(s, 1); ft_putendl_fd("\";", 1);
	ft_putstr_fd("char	s2[] = \"", 1); ft_putstr_fd(s2, 1); ft_putendl_fd("\";", 1);
	ft_putendl_fd("char	**w;\n", 1);

	w = ft_split(s, '!');
	ft_putstr_fd("w = ft_split(s, '!')\n=> w = ", 1);
	i = 0;
	while (w[i])
	{
		ft_putstr_fd(w[i], 1); ft_putstr_fd(" // ", 1);
		i++;
	}
	ft_free_str_arr(w);

	ft_putendl_fd("\n", 1);

	w = ft_split(s, 'Z');
	ft_putstr_fd("w = ft_split(s, 'Z')\n=> w = ", 1);
	i = 0;
	while (w[i])
	{
		ft_putstr_fd(w[i], 1); ft_putstr_fd(" // ", 1);
		i++;
	}
	ft_free_str_arr(w);

	ft_putendl_fd("\n", 1);

	w = ft_split(s2, '!');
	ft_putstr_fd("w = ft_split(s2, '!')\n=> w = ", 1);
	i = 0;
	while (w[i])
	{
		ft_putstr_fd(w[i], 1); ft_putstr_fd(" // ", 1);
		i++;
	}
	ft_free_str_arr(w);
}

void	search(void)
{
	char	s[] = "Portez ce vieux whisky au juge blond qui fume.";
	char	f[] = "whisky";

	ft_putstr_fd("char\ts[] = ", 1); ft_putendl_fd(s, 1);
	ft_putstr_fd("char\tf[] = ", 1); ft_putendl_fd(f, 1);
	ft_putendl_fd("", 1);
	
	char *ptr = ft_strchr("teste", 'e');
	ft_putstr_fd("ft_strchr(s, 'i') = ", 1); if (!ptr) ft_putendl_fd("NULL", 1); else ft_putendl_fd(ptr, 1);
	ft_putstr_fd("strchr(s, 'i') = ", 1); ft_putendl_fd(strchr(s, 'i'), 1);
	ft_putendl_fd("", 1);

	ft_putstr_fd("ft_strrchr(s, 'i') = ", 1); ft_putendl_fd(ft_strrchr(s, 'i'), 1);
	ft_putstr_fd("strrchr(s, 'i') = ", 1); ft_putendl_fd(strrchr(s, 'i'), 1);
	ft_putendl_fd("", 1);

	ft_putstr_fd("ft_strnstr(s, f, 40) = ", 1); ft_putendl_fd(ft_strnstr(s, f, 40), 1);
	ft_putstr_fd("strnstr(s, f, 40) = ", 1); ft_putendl_fd(strnstr(s, f, 40), 1);
	ft_putstr_fd("ft_strnstr(\"\", f, 40) = ", 1); ft_putendl_fd(ft_strnstr("", f, 40), 1);
	ft_putstr_fd("strnstr(\"\", f, 40) = ", 1); ft_putendl_fd(strnstr("", f, 40), 1);
	ft_putstr_fd("ft_strnstr(s, \"\", 40) = ", 1); ft_putendl_fd(ft_strnstr(s, "", 40), 1);
	ft_putstr_fd("strnstr(s, \"\", 40) = ", 1); ft_putendl_fd(strnstr(s, "", 40), 1);
	ft_putendl_fd("", 1);

	ft_putstr_fd("ft_memchr(s, 'e', sizeof(s)) = ", 1); ft_putendl_fd(ft_memchr(s, 'e', sizeof(s)), 1);
	ft_putstr_fd("memchr(s, 'e', sizeof(s)) = ", 1); ft_putendl_fd(memchr(s, 'e', sizeof(s)), 1);
	ft_putstr_fd("ft_memchr(\"\", 'e', sizeof(\"\")) = ", 1); ft_putendl_fd(ft_memchr("", 'e', sizeof("")), 1);
	ft_putstr_fd("memchr(\"\", 'e', sizeof(\"\")) = ", 1); ft_putendl_fd(memchr("", 'e', sizeof("")), 1);
	ft_putstr_fd("ft_memchr(s, 0, sizeof(s)) = ", 1); ft_putendl_fd(ft_memchr(s, 0, sizeof(s)), 1);
	ft_putstr_fd("memchr(s, 0, sizeof(s)) = ", 1); ft_putendl_fd(memchr(s, 0, sizeof(s)), 1);
	ft_putendl_fd("", 1);

	int n[] = {12, 45, 3, 10, 6};
	int	*res = ft_memchr(n, 10, sizeof(n));

	ft_putendl_fd("int\tn[] = {12, 45, 3, 10, 6};", 1);
	ft_putendl_fd("int\t*res = ft_memchr(n, 10, sizeof(n));", 1);
	ft_putendl_fd("", 1);

	ft_putstr_fd("res = ft_memchr(n, 10, sizeof(n));\n=> res = ", 1); if (!res) ft_putendl_fd("Not found", 1); else ft_putnbr_fd(*res, 1); ft_putchar_fd('\n', 1);
	res = memchr(n, 10, sizeof(n));
	ft_putstr_fd("res = memchr(n, 10, sizeof(n));\n=> res = ", 1); if (!res) ft_putendl_fd("Not found", 1); else ft_putnbr_fd(*res, 1); ft_putchar_fd('\n', 1);
	ft_putendl_fd("", 1);

	res = ft_memchr(n, 2, sizeof(n));
	ft_putstr_fd("res = ft_memchr(n, 2, sizeof(n))\n=> res = ", 1); if (!res) ft_putendl_fd("Not found", 1); else {ft_putnbr_fd(*res, 1); ft_putchar_fd('\n', 1);}
	res = memchr(n, 2, sizeof(n));
	ft_putstr_fd("res = memchr(n, 2, sizeof(n))\n=> res = ", 1); if (!res) ft_putendl_fd("Not found", 1); else {ft_putnbr_fd(*res, 1); ft_putchar_fd('\n', 1);}
}

void	copystr(void)
{
	char		dst[15];
	char		dst2[15];
	char		*dst3 = NULL;
	char		dst4[15];
	char		dst5[15];
	char		src[] = "et l'unique cordeau des trompettes marines";
	char		*dup;
	size_t		copied;
	char		*substring;

	ft_putendl_fd("char\tdst[15]", 1);
	ft_putendl_fd("char\tsrc[] = \"et l'unique cordeau des trompettes marines\"", 1);
	ft_putendl_fd("", 1);

	copied = ft_strlcpy(dst, src, 15);
	ft_putstr_fd("ft_strlcpy(dst, src, 15) => dst = ", 1); ft_putstr_fd(dst, 1); ft_putstr_fd(" // return = ", 1); ft_putnbr_fd(copied, 1); ft_putchar_fd('\n', 1);
	copied = strlcpy(dst2, src, 15);
	ft_putstr_fd("strlcpy(dst, src, 15) => dst = ", 1); ft_putstr_fd(dst2, 1); ft_putstr_fd(" // return = ", 1); ft_putnbr_fd(copied, 1); ft_putchar_fd('\n', 1);

	copied = ft_strlcpy(dst3, src, 15);
	ft_putstr_fd("ft_strlcpy(NULL, src, 15) => dst = ", 1); ft_putstr_fd(dst3, 1); ft_putstr_fd(" // return = ", 1); ft_putnbr_fd(copied, 1); ft_putchar_fd('\n', 1);
	copied = strlcpy(NULL, src, 15);
	ft_putstr_fd("strlcpy(NULL, src, 15) => dst = ", 1); ft_putstr_fd(dst2, 1); ft_putstr_fd(" // return = ", 1); ft_putnbr_fd(copied, 1); ft_putchar_fd('\n', 1);

	copied = ft_strlcpy(dst4, NULL, 15);
	ft_putstr_fd("ft_strlcpy(dst, NULL, 15) => dst = ", 1); ft_putstr_fd(dst4, 1); ft_putstr_fd(" // return = ", 1); ft_putnbr_fd(copied, 1); ft_putchar_fd('\n', 1);
	copied = strlcpy(dst4, NULL, 15);
	ft_putstr_fd("strlcpy(dst, NULL, 15) => dst = ", 1); ft_putstr_fd(dst4, 1); ft_putstr_fd(" // return = ", 1); ft_putnbr_fd(copied, 1); ft_putchar_fd('\n', 1);

	copied = ft_strlcpy(dst5, src, 0);
	ft_putstr_fd("ft_strlcpy(dst, src, 0) => dst = ", 1); ft_putstr_fd(dst5, 1); ft_putstr_fd(" // return = ", 1); ft_putnbr_fd(copied, 1); ft_putchar_fd('\n', 1);
	copied = strlcpy(dst5, src, 0);
	ft_putstr_fd("strlcpy(dst, src, 0) => dst = ", 1); ft_putstr_fd(dst5, 1); ft_putstr_fd(" // return = ", 1); ft_putnbr_fd(copied, 1); ft_putchar_fd('\n', 1);

	ft_putendl_fd("", 1);

	dup = ft_strdup(src);
	ft_putstr_fd("dup = ft_strdup(src) => dup = ", 1); ft_putendl_fd(dup, 1);
	free(dup);

//	ft_memcpy(dst + 5, dst + 12, 10);
//	memcpy(dst2 + 5, dst2 + 12, 10);
//	ft_putstr_fd("ft_memcpy(dst + 5, dst + 12, 10) => dst = ", 1); ft_putendl_fd(dst, 1);
//	ft_putstr_fd("memcpy(dst + 2, dst + 12, 10) => dst = ", 1); ft_putendl_fd(dst2, 1);
	
	ft_putendl_fd("", 1);

	ft_memmove(dst + 2, dst + 7, 3);
	memmove(dst2 + 2, dst2 + 7, 3);
	ft_putstr_fd("ft_memmove(dst + 2, dst + 7, 3) => dst = ", 1); ft_putendl_fd(dst, 1);
	ft_putstr_fd("memmove(dst2 + 2, dst2 + 7, 3) => dst = ", 1); ft_putendl_fd(dst2, 1);

	ft_putendl_fd("", 1);

	substring = ft_substr(src, 8, 9);
	ft_putstr_fd("ft_substr(src, src + 8, 9) = ", 1); ft_putendl_fd(substring, 1);
	free(substring);
}

void	copy_int(void)
{
	int	dst[15];
	int	dst2[15];
	int	src[] = {25, 10, 945, 7436, 42, 987};
	int	i;

	ft_memset(dst, -1, sizeof(dst));
	memset(dst2, -1, sizeof(dst2));
	ft_putendl_fd("int\tdst[15]; [initialisé avec ft_memset(dst, -1, sizeof(dst))]", 1);
	ft_putendl_fd("int\tdst2[15]; [initialisé avec memset(dst2, -1, sizeof(dst))]", 1);
	ft_putendl_fd("int\tsrc[] = {25, 10, 945, 7436, 42, 987};", 1);
	ft_putendl_fd("", 1);

	ft_memcpy(dst + 4, src + 2, 4 * sizeof(int));
	ft_putstr_fd("ft_memcpy(dst + 4, src + 2, 4 * sizeof(int)) => dst = ", 1);
	i = 0;
	while (i < 15)
	{
		ft_putnbr_fd(dst[i], 1); ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putendl_fd("", 1);

	memcpy(dst2 + 4, src + 2, 4 * sizeof(int));
	ft_putstr_fd("memcpy(dst2 + 4, src + 2, 4 * sizeof(intt)) => dst2 = ", 1);
	i = 0;
	while (i < 15)
	{
		ft_putnbr_fd(dst2[i], 1); ft_putstr_fd(" ", 1);
		i++;
	}

	ft_putendl_fd("", 1);

	ft_memmove(dst + 4, dst + 2, 4 * sizeof(*dst));
	ft_putstr_fd("ft_memmove(dst + 4, dst + 2, 4 * sizeof(*dst)) => dst = ", 1);
	i = 0;
	while (i < 15)
	{
		ft_putnbr_fd(dst[i], 1); ft_putstr_fd(" ", 1);
		i++;
	}
	ft_putendl_fd("", 1);

	memmove(dst2 + 4, dst2 + 2, 4 * sizeof(*dst2));
	ft_putstr_fd("memmove(dst2 + 4, dst2 + 2, 4 * sizeof(*dst2)) => dst2 = ", 1);
	i = 0;
	while (i < 15)
	{
		ft_putnbr_fd(dst2[i], 1); ft_putstr_fd(" ", 1);
		i++;
	}

	ft_putendl_fd("", 1);
}

void	compare(void)
{
	char	x[] = "alors quoi";
	char	z[] = "alors quoi";
	char	y[] = "alors qwoi";
	int		a[] = {10, 25, 987};
	int		b[] = {10, 25, 987};
	int		c[] = {10, 25, 986};

	ft_putendl_fd("char	x[] = \"alors quoi\";", 1);
	ft_putendl_fd("char	y[] = \"alors quoi\";", 1);
	ft_putendl_fd("char	z[] = \"alors qwoi\";", 1);
	ft_putendl_fd("int\t\ta[] = {10, 25, 987};", 1);
	ft_putendl_fd("int\t\tb[] = {10, 25, 987};", 1);
	ft_putendl_fd("int\t\tc[] = {10, 25, 986};", 1);
	ft_putendl_fd("", 1);

	ft_putstr_fd("ft_strncmp(x, y, 4) = ", 1); ft_putnbr_fd(ft_strncmp(x, y, 4), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("strncmp(x, y, 4) = ", 1); ft_putnbr_fd(strncmp(x, y, 4), 1); ft_putendl_fd("", 1);
	ft_putendl_fd("", 1);

	ft_putstr_fd("ft_strncmp(x, z, 4) = ", 1); ft_putnbr_fd(ft_strncmp(x, z, 4), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("strncmp(x, z, 4) = ", 1); ft_putnbr_fd(strncmp(x, z, 4), 1); ft_putendl_fd("", 1);
	ft_putendl_fd("", 1);

	ft_putstr_fd("ft_memcmp(x, z, 10) = ", 1); ft_putnbr_fd(ft_memcmp(x, y, 10), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("memcmp(x, z, 10) = ", 1); ft_putnbr_fd(memcmp(x, y, 10), 1); ft_putendl_fd("", 1);
	ft_putendl_fd("", 1);

	ft_putstr_fd("ft_memcmp(x, z, 10) = ", 1); ft_putnbr_fd(ft_memcmp(x, z, 10), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("memcmp(x, z, 10) = ", 1); ft_putnbr_fd(memcmp(x, z, 10), 1); ft_putendl_fd("", 1);
	ft_putendl_fd("", 1);

	ft_putstr_fd("ft_memcmp(&a, &b, 10) = ", 1); ft_putnbr_fd(ft_memcmp(&a, &b, 10), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("memcmp(&a, &b, 10) = ", 1); ft_putnbr_fd(memcmp(&a, &b, 10), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("ft_memcmp(&a, &c, 10) = ", 1); ft_putnbr_fd(ft_memcmp(&a, &c, 10), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("memcmp(&a, &c, 10) = ", 1); ft_putnbr_fd(memcmp(&a, &c, 10), 1); ft_putendl_fd("", 1);
}

void	intstr(void)
{
	char	*z;
	int		a = -32545;
	int 	b = 32456;
	int		c = 0;
	int		d = 10000;
	int		e = INT_MAX;
	int		f = INT_MIN;
	char	m[] = " \n \t-4568";
	char	n[] = " \n \t4568";
	char	o[] = " \n \t0";
	char	p[] = " \n \t10000";
	char	q[] = "\010 947483647sred";
	char	r[] = "-2147483648";
	char	s[] = "3254656734243323";
	char	t[] = "6546457646345314356476587683465245244365";
	char	m2[] = " \\n \\t-4568";
	char	n2[] = " \\n \\t4568";
	char	o2[] = " \\n \t0";
	char	p2[] = " \\n \\t10000";

	ft_putendl_fd("char	*z;", 1);
	ft_putstr_fd("int\ta = ", 1); ft_putnbr_fd(a, 1); ft_putendl_fd("", 1);
	ft_putstr_fd("int\tb = ", 1); ft_putnbr_fd(b, 1); ft_putendl_fd("", 1);
	ft_putstr_fd("int\tc = ", 1); ft_putnbr_fd(c, 1); ft_putendl_fd("", 1);
	ft_putstr_fd("int\td = ", 1); ft_putnbr_fd(d, 1); ft_putendl_fd("", 1);
	ft_putstr_fd("int\te = ", 1); ft_putnbr_fd(e, 1); ft_putendl_fd("", 1);
	ft_putstr_fd("int\tf = ", 1); ft_putnbr_fd(f, 1); ft_putendl_fd("", 1);
	ft_putstr_fd("char\tm[] = \"", 1); ft_putstr_fd(m2, 1); ft_putendl_fd("\"", 1);
	ft_putstr_fd("char\tn[] = \"", 1); ft_putstr_fd(n2, 1); ft_putendl_fd("\"", 1);
	ft_putstr_fd("char\to[] = \"", 1); ft_putstr_fd(o2, 1); ft_putendl_fd("\"", 1);
	ft_putstr_fd("char\tp[] = \"", 1); ft_putstr_fd(p2, 1); ft_putendl_fd("\"", 1);
	ft_putstr_fd("char\tq[] = \"", 1); ft_putstr_fd(q, 1); ft_putendl_fd("\"", 1);
	ft_putstr_fd("char\tr[] = \"", 1); ft_putstr_fd(r, 1); ft_putendl_fd("\"", 1);
	ft_putstr_fd("char\ts[] = \"", 1); ft_putstr_fd(s, 1); ft_putendl_fd("\"", 1);
	ft_putstr_fd("char\tt[] = \"", 1); ft_putstr_fd(t, 1); ft_putendl_fd("\"", 1);

	ft_putendl_fd("", 1);

	ft_putstr_fd("ft_putnbr_fd(ft_atoi(m), 1); => ", 1); ft_putnbr_fd(ft_atoi(m), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("ft_putnbr_fd(atoi(m), 1); => ", 1); ft_putnbr_fd(atoi(m), 1); ft_putendl_fd("", 1);

	ft_putstr_fd("ft_putnbr_fd(ft_atoi(n), 1); => ", 1); ft_putnbr_fd(ft_atoi(n), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("ft_putnbr_fd(atoi(n), 1); => ", 1); ft_putnbr_fd(atoi(n), 1); ft_putendl_fd("", 1);

	ft_putstr_fd("ft_putnbr_fd(ft_atoi(o), 1); => ", 1); ft_putnbr_fd(ft_atoi(o), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("ft_putnbr_fd(atoi(o), 1); => ", 1); ft_putnbr_fd(atoi(o), 1); ft_putendl_fd("", 1);

	ft_putstr_fd("ft_putnbr_fd(ft_atoi(p), 1); => ", 1); ft_putnbr_fd(ft_atoi(p), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("ft_putnbr_fd(atoi(p), 1); => ", 1); ft_putnbr_fd(atoi(p), 1); ft_putendl_fd("", 1);

	ft_putstr_fd("ft_putnbr_fd(ft_atoi(q), 1); => ", 1); ft_putnbr_fd(ft_atoi(q), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("ft_putnbr_fd(atoi(q), 1); => ", 1); ft_putnbr_fd(atoi(q), 1); ft_putendl_fd("", 1);

	ft_putstr_fd("ft_putnbr_fd(ft_atoi(r), 1); => ", 1); ft_putnbr_fd(ft_atoi(r), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("ft_putnbr_fd(atoi(r), 1); => ", 1); ft_putnbr_fd(atoi(r), 1); ft_putendl_fd("", 1);

	ft_putstr_fd("ft_putnbr_fd(ft_atoi(s), 1); => ", 1); ft_putnbr_fd(ft_atoi(s), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("ft_putnbr_fd(atoi(s), 1); => ", 1); ft_putnbr_fd(atoi(s), 1); ft_putendl_fd("", 1);

	ft_putstr_fd("ft_putnbr_fd(ft_atoi(t), 1); => ", 1); ft_putnbr_fd(ft_atoi(t), 1); ft_putendl_fd("", 1);
	ft_putstr_fd("ft_putnbr_fd(atoi(t), 1); => ", 1); ft_putnbr_fd(atoi(t), 1); ft_putendl_fd("", 1);

	ft_putendl_fd("", 1);

	z = ft_itoa(a);
	ft_putendl_fd("z = ft_itoa(a);", 1);
	ft_putstr_fd("ft_putstr_fd(z, 1); => ", 1); ft_putendl_fd(z, 1);
	free(z);

	z = ft_itoa(b);
	ft_putendl_fd("z = ft_itoa(b);", 1);
	ft_putstr_fd("ft_putstr_fd(z, 1); => ", 1); ft_putendl_fd(z, 1);
	free(z);

	z = ft_itoa(c);
	ft_putendl_fd("z = ft_itoa(c);", 1);
	ft_putstr_fd("ft_putstr_fd(z, 1); => ", 1);
	ft_putendl_fd(z, 1);
	free(z);

	z = ft_itoa(d);
	ft_putendl_fd("z = ft_itoa(d);", 1);
	ft_putstr_fd("ft_putstr_fd(z, 1); => ", 1);
	ft_putendl_fd(z, 1);
	free(z);

	z = ft_itoa(e);
	ft_putendl_fd("z = ft_itoa(e);", 1);
	ft_putstr_fd("ft_putstr_fd(z, 1); => ", 1);
	ft_putendl_fd(z, 1);
	free(z);

	z = ft_itoa(f);
	ft_putendl_fd("z = ft_itoa(f);", 1);
	ft_putstr_fd("ft_putstr_fd(z, 1); => ", 1);
	ft_putendl_fd(z, 1);
	free(z);
}

#include <stdio.h>
int	main(void)
{
	ft_putendl_fd("", 1);
	charchecks();
	ft_putendl_fd("\n==========\n", 1);
	transcase();
	ft_putendl_fd("\n==========\n", 1);
	strings();
	ft_putendl_fd("\n==========\n", 1);
	splitjoin();
	ft_putendl_fd("\n==========\n", 1);
	search();
	ft_putendl_fd("\n==========\n", 1);
	copystr();
	ft_putendl_fd("\n==========\n", 1);
	copy_int();
	ft_putendl_fd("\n==========\n", 1);
	compare();
	ft_putendl_fd("\n==========\n", 1);
	intstr();
	ft_putendl_fd("", 1);
	return (0);
}
