/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 19:29:05 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*handle_signal_in_completion(t_shdata *shdata, int stdinfd)
{
	if (g_signal != SIGINT)
	{
		close(stdinfd);
		ft_printf("unexpected EOF\n");
		bi_exit(shdata, NULL, NULL, EX_MISUSE);
	}
	dup2(stdinfd, STDIN_FILENO);
	close(stdinfd);
	return (NULL);
}

char	*line_read(t_shdata *shdata, t_line *line)
{
	int	stdinfd;

	line->line = readline(shdata->ptr_prompt);
	if (!line->line)
		bi_exit(shdata, NULL, NULL, EX_SUCCESS);
	line->len = ft_strlen(line->line);
	if (check_pipes(line) == -1 || check_redirect(line))
		return (line->line = ft_free_safe(line->line), NULL);
	while (check_end_pipe(line, line->len) \
			|| check_quotes(line, line->len) \
			|| check_bs(line, line->len))
	{
		stdinfd = dup(STDIN_FILENO);
		set_sigint_handler(line_sigint_handler);
		line->line = close_quotes(line);
		line->line = close_pipeline(line);
		line->line = close_bs(line);
		if (!line->line)
			return (handle_signal_in_completion(shdata, stdinfd));
		if (check_pipes(line) == -1 || check_redirect(line))
			line->line = ft_free_safe(line->line);
		close_if_isopen(stdinfd);
	}
	line->line = strip_line(line->line);
	return (line->line);
}

size_t	loop_to_set(t_line *line, size_t i, char *set)
{
	while (line->line[i])
	{
		if (line->quote_state != SINGLE_QUOTE && line->line[i + 1] \
				&& line->line[i] == '\\')
			i++;
		else
			line->quote_state = get_quote_state(line, i);
		if (!line->quote_state && ft_isset(line->line[i], set))
			break ;
		i++;
	}
	return (i);
}
