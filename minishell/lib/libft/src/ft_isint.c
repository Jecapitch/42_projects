/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:11:05 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/22 23:35:00 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *s)
{
	long	n;
	size_t	i;

	n = ft_strtol(s);
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	i += (s[i] == '+' || s[i] == '-');
	if (!(s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
