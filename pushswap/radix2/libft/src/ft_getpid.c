/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:48:40 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 18:41:51 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getpid(void)
{
	int		fd;
	char	buffer[64];

	ft_bzero(buffer, sizeof(buffer));
	fd = open("/proc/self/stat", O_RDONLY);
	if (fd == -1 || read(fd, buffer, sizeof(buffer)) == -1)
	{
		ft_log("", -1, __func__, "error");
		return (-1);
	}
	close(fd);
	if (!(*buffer))
		return (-1);
	return (ft_atoi(buffer));
}
