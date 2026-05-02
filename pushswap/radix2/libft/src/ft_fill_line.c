/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:16:22 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 04:14:08 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fill_line(size_t len, size_t maxlen, int fill, int end)
{
	char	*blank;
	size_t	size;

	size = maxlen - len - 1;
	blank = ft_calloc(size + 1, sizeof(char));
	if (!blank)
	{
		ft_dprintf(STDERR_FD, \
					"ft_fill_line: "BRED"error"CRESET": ft_calloc");
		return ;
	}
	ft_memset(blank, fill, size);
	blank[size - 1] = end;
	ft_putendl_fd(blank, 1);
	free(blank);
}
