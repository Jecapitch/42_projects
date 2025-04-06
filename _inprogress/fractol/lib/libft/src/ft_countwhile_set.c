/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwhile_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:17:35 by jpiscice          #+#    #+#             */
/*   Updated: 2024/11/23 14:17:53 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwhile_set(const char *s, const char *endset)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] && !ft_isset(s[len], endset))
		len++;
	return (len);
}
