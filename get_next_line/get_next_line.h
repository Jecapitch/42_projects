/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:59:48 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/23 10:30:28 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1024
# endif

# ifndef MAX_FD
#  define MAX_FD		4096
# endif

char	*get_next_line(int fd);
size_t	ft_count_endl(char buffer[]);
void	ft_copy(char *dst, char *src, size_t len);
char	*ft_join(char *s1, size_t len_s1, char buffer[], size_t len_buffer);

#endif /* GET_NEXT_LINE_H */
