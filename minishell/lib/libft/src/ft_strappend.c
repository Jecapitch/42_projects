/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:21:00 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/10 09:30:18 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strappend(char **dest, char *src)
{
	char	*newline;

	newline = NULL;
	if (!dest)
		return (1);
	newline = ft_strjoin(*dest, src);
	*dest = ft_free_safe(*dest);
	*dest = newline;
	return (*dest == NULL);
}
