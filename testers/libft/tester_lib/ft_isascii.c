/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:11:35 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 05:36:23 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

int	tester_ft_isspace(int c)
{
	return (c == ' ' \
			|| c == '\n' \
			|| c == '\t' \
			|| c == '\r' \
			|| c == '\f' \
			|| c == '\v');
}

int	tester_ft_isascii(int n)
{
	return (n >= 0 && n <= 127);
}

int	tester_ft_isprint(int n)
{
	return (n >= ' ' && n <= '~');
}
