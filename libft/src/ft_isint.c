/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:11:05 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/18 23:24:19 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *s)
{
	char	*str;
	int		n;
	int		res;
	size_t	len;
	int		neg;

	n = ft_atoi(s);
	str = ft_itoa(n);
	while (ft_isspace(*s))
		s++;
	neg = (*s == '-');
	s += (*s == '+' || *s == '-');
	if (!*s)
		return (0);
	while (*s == '0')
		s++;
	len = ft_strlen(s);
	res = (ft_strncmp(s, str + neg, len) == 0);
	free(str);
	return (res);
}
