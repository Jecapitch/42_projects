/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_seq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:05:24 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/19 23:57:27 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_seq(const char *s, int c)
{
	int	n;

	n = 0;
	while (*s && *s != c)
	{
		n += (*s == c);
		s++;
	}
	return (n);
}