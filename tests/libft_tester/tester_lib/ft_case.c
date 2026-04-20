/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 05:22:57 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/16 01:34:42 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

int	tester_ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	tester_ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	tester_ft_tolower(int c)
{
	if (tester_ft_isupper(c))
		c += ('a' - 'A');
	return (c);
}

int	tester_ft_toupper(int c)
{
	if (tester_ft_islower(c))
		c += ('A' - 'a');
	return (c);
}
