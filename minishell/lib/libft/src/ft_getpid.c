/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:48:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/13 23:16:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getpid(void)
{
	int		fd;
	char	buffer[65];

	ft_bzero(buffer, sizeof(buffer));
	fd = open("/proc/self/stat", O_RDONLY);
	if (fd == -1 || read(fd, buffer, sizeof(buffer) - 1) == -1)
	{
		ft_fprintf(STDERR_FILENO, "ft_get_pid: error");
		return (-1);
	}
	close(fd);
	if (!(*buffer))
		return (-1);
	return (ft_atoi(buffer));
}
