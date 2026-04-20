/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:58:25 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 16:36:55 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

int	tester_ft_isflag(int c)
{
	return (tester_ft_isset(c, FFLAGS));
}

int	tester_ft_isconv(int c)
{
	return (tester_ft_isset(c, FCONV));
}

char	*tester_chartostr(int c)
{
	char	*s;

	s = tester_ft_calloc(2, sizeof(char));
	if (!s)
		return (NULL);
	*s = c;
	return (s);
}
