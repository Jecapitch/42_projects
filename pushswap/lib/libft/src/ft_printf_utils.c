/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:58:25 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/07 02:22:08 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(int c)
{
	return (ft_isset(c, FFLAGS));
}

int	ft_isconv(int c)
{
	return (ft_isset(c, FCONV));
}

char	*chartostr(int c)
{
	char	*s;

	s = ft_calloc(2, sizeof(char));
	if (!s)
		return (NULL);
	*s = c;
	return (s);
}
