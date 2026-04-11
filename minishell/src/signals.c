/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarlier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:04:20 by emarlier          #+#    #+#             */
/*   Updated: 2025/08/07 20:14:12 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	inter_sigint_handler(int sig)
{
	write(STDIN_FILENO, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	g_signal = sig;
}

void	line_sigint_handler(int sig)
{
	write(STDIN_FILENO, "\n", 1);
	close(STDIN_FILENO);
	g_signal = sig;
}

void	set_sigquit_handler(void sigquit(int))
{
	struct sigaction	sa;

	g_signal = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = sigquit;
	sigaction(SIGQUIT, &sa, NULL);
}

void	set_sigint_handler(void sigint(int))
{
	struct sigaction	sa;

	g_signal = 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sa.sa_handler = sigint;
	sigaction(SIGINT, &sa, NULL);
}
