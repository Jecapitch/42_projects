/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 15:41:33 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/26 23:03:21 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

#include "libft.h"
#include "tester_libft.h"
#include "colors.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
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

#define OK		GRN"OK"CRESET
#define KO		RED"KO"CRESET
#define ERROR	RED"error"CRESET
#define CRASHOK	YEL"crash (OK)"CRESET

#endif /* LIBFT_TESTER_H */
