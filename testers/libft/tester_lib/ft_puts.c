/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:10:12 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 14:50:50 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

void	tester_ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
	{
		tester_ft_log(NULL, -1, __func__, "invalid file descriptor");
		return ;
	}
	write(fd, &c, 1);
}

void	tester_ft_putstr_fd(char *s, int fd)
{
	int	err;

	err = 0;
	if (!s)
	{
		err |= 1;
		tester_ft_err_nonnull(NULL, -1, __func__);
	}
	if (fd < 0)
	{
		err |= 1;
		tester_ft_log(NULL, -1, __func__, "invalid file descriptor");
	}
	if (err)
		return ;
	write(fd, s, tester_ft_strlen(s));
}

void	tester_ft_putendl_fd(char *s, int fd)
{
	int	err;

	err = 0;
	if (!s)
	{
		err |= 1;
		tester_ft_err_nonnull(NULL, -1, __func__);
	}
	if (fd < 0)
	{
		err |= 1;
		tester_ft_log(NULL, -1, __func__, "invalid file descriptor");
	}
	if (err)
		return ;
	tester_ft_putstr_fd(s, fd);
	tester_ft_putchar_fd('\n', fd);
}
