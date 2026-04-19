/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthys <nthys@student.s42.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:56:20 by nthys             #+#    #+#             */
/*   Updated: 2025/10/24 11:56:20 by nthys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return (0);
	return (ft_putstr_fd(s, fd) + ft_putchar_fd('\n', fd));
}
