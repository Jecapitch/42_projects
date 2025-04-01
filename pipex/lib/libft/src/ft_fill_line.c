/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 00:16:22 by jpiscice          #+#    #+#             */
/*   Updated: 2025/04/01 00:16:26 by jpiscice         ###   ########.fr       */
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
		perror("ft_calloc");
		exit(EXIT_FAILURE);
	}
	ft_memset(blank, fill, size);
	ft_printf("%s%c\n", blank, end);
	free(blank);
}
