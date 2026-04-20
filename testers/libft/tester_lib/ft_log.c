/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 03:10:41 by jepiscic          #+#    #+#             */
/*   Updated: 2026/04/14 23:23:30 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_libft.h"

void	tester_ft_err_nonnull(const char *file, int line, const char *fct)
{
	tester_ft_log(file, line, fct, BRED "error" CRESET \
				": argument null where non-null expected");
}

void	tester_ft_log(const char *file, int line, const char *func, \
				const char *msg)
{
	if (!(file && *file) && !(func && *func) && !(msg && *msg))
		return ;
	if (file && *file)
	{
		tester_ft_fprintf(STDERR_FD, "%s", file);
		if (line > 0)
			tester_ft_fprintf(STDERR_FD, ":%d", line);
		if ((func && *func) || (msg && *msg))
			tester_ft_putstr_fd(": ", STDERR_FD);
	}
	if (func && *func)
	{
		tester_ft_fprintf(STDERR_FD, "%s", func);
		if (msg && *msg)
			tester_ft_putstr_fd(": ", STDERR_FD);
	}
	if (msg && *msg)
		tester_ft_fprintf(STDERR_FD, "%s", msg);
	tester_ft_putchar_fd('\n', STDERR_FD);
}
