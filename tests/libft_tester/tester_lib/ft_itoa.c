/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 00:39:49 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 15:30:17 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

char	*tester_ft_itoa(int n)
{
	char	*s;
	size_t	i;
	long	ln;

	ln = n;
	s = tester_ft_calloc(16, sizeof(char));
	if (!s)
		return (NULL);
	s[0] = '0';
	if (n < 0)
		ln *= -1;
	i = 0;
	while (ln)
	{
		s[i] = ln % 10 + '0';
		ln /= 10;
		i++;
	}
	if (n < 0)
		s[i++] = '-';
	s = tester_ft_reverse_tab(s, i, sizeof(char));
	s = tester_ft_recalloc(s, 16, tester_ft_strlen(s) + 1);
	return (s);
}
