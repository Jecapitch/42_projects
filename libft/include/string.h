/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 13:22:15 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "libft.h"

/* LENGTH */
size_t		ft_strlen(const char *s);
size_t		ft_strlen_delim(const char *s, const char endc);
size_t		ft_strlen_delim_set(const char *s, const char *endset);
size_t		ft_strlen_condition(const char *s, int (*f)(int));
size_t		ft_count_words(const char *s, char c);
size_t		ft_count_words_set(const char *s, const char *set);

/* MODIFY */
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_strstrip(const char *s1);
char		*ft_strmapi(const char *s, char (*f)(t_uint, char));
void		ft_striteri(char *s, void (*f)(t_uint, char*));

/* JOIN */
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_sep(const char *s1, const char *s2, const char *sep);
int			ft_strappend(char **dest, char *src);

/* SPLIT */
char		**ft_split(const char *s, char c);
char		**ft_split_set(const char *s, const char *set);
char		**ft_split_mark(const char *s, const char *mark, const char *set);

/* SEARCH */
void		*ft_memchr(const void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strchr_set(const char *s, char *set);
char		*ft_strrchr(const char *s, int c);
char		*ft_strrchr_set(const char *s, char *set);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

/* COPY */
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strdup(const char *s1);
char		*ft_strldup(const char *s, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_substr(const char *s, t_uint start, size_t len);

/* COMPARE */
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/* SET */
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);

#endif /* STRING_H */
