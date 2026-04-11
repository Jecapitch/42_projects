/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:10:12 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/12 00:10:11 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
	{
		ft_log(NULL, -1, __func__, "invalid file descriptor");
		return ;
	}
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return ;
	}
	if (fd < 0)
	{
		ft_log(NULL, -1, __func__, "invalid file descriptor");
		return ;
	}
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
	{
		ft_err_nonnull(NULL, -1, __func__);
		return ;
	}
	if (fd < 0)
	{
		ft_log(NULL, -1, __func__, "invalid file descriptor");
		return ;
	}
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
