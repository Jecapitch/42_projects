/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:48:40 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 04:39:32 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getpid(void)
{
	int		fd;
	char	buffer[128];

	ft_bzero(buffer, sizeof(buffer));
	fd = open("/proc/self/stat", O_RDONLY);
	if (fd == -1 || read(fd, buffer, sizeof(buffer)) == -1)
	{
		ft_fprintf(STDERR_FD, "ft_get_pid: " BRED "error" CRESET);
		return (-1);
	}
	close(fd);
	if (!(*buffer))
		return (-1);
	return (ft_atoi(buffer));
}
