/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwhile_condition.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:17:35 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/06 13:01:41 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwhile_condition(const char *s, int (*f)(int))
{
	size_t	len;

	if (!s || !f)
		return (0);
	len = 0;
	while (s[len] && f(s[len]))
		len++;
	return (len);
}
