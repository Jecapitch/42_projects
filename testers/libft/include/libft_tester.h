/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:41:33 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/17 02:59:23 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

#include "libft.h"
#include "colors.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <inttypes.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include <sys/wait.h>
#ifdef __linux__
# include <bsd/string.h>
#endif

#define STR(x)	#x
#define STRF(x) STR(x)

#define OK		BGRN"OK"CRESET
#define KO		BRED"KO"CRESET
#define ERROR	BRED"error"CRESET
#define CRASHOK	YEL"crash (OK)"CRESET

#endif /* LIBFT_TESTER_H */
