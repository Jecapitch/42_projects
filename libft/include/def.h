/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   def.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 13:19:18 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/13 16:24:45 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_H
# define DEF_H

# include "colors.h"

# define MAX_INT_LEN	10
# define BASE2			"01"
# define BASE8			"01234567"
# define BASE10			"0123456789"
# define BASE16			"0123456789abcdef"
# define BASE36			"0123456789abcdefghijklmnopqrstuvwxyz"
# define STDIN_FD		STDIN_FILENO
# define STDOUT_FD		STDOUT_FILENO
# define STDERR_FD		STDERR_FILENO

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1028
# endif

# ifndef MAX_FD
#  define MAX_FD		4096
# endif

typedef unsigned int	t_uint;
typedef unsigned char	t_uchar;
typedef unsigned long	t_ulong;

extern char				**environ;

#endif /* DEF_H */
