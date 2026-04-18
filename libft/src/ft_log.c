/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 03:10:41 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/11 00:37:04 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_err_nonnull(const char *file, int line, const char *fct)
{
	ft_log(file, line, fct, BRED "error" CRESET \
				": argument null where non-null expected");
}

void	ft_log(const char *file, int line, const char *func, \
				const char *msg)
{
	if (!(file && *file) && !(func && *func) && !(msg && *msg))
		return ;
	if (file && *file)
	{
		ft_dprintf(STDERR_FD, "%s", file);
		if (line > 0)
			ft_dprintf(STDERR_FD, ":%d", line);
		if ((func && *func) || (msg && *msg))
			ft_putstr_fd(": ", STDERR_FD);
	}
	if (func && *func)
	{
		ft_dprintf(STDERR_FD, "%s", func);
		if (msg && *msg)
			ft_putstr_fd(": ", STDERR_FD);
	}
	if (msg && *msg)
		ft_dprintf(STDERR_FD, "%s", msg);
	ft_putchar_fd('\n', STDERR_FD);
}
