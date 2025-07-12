/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/11 23:55:08 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*strip_line(char *line)
{
	char	*new_line;

	if (!line)
		return (NULL);
	new_line = ft_strstrip(line);
	line = ft_free_safe(line);
	return (new_line);
}

t_quote	check_quotes(const char *line)
{
	static int	state = CLOSED_QUOTE;

	while (*line)
	{
		if (state == CLOSED_QUOTE \
			&& ft_isset(*line, "\'\"`"))
		{
			state = *line;
			line++;
			continue ;
		}
		if (state != CLOSED_QUOTE && *line == state)
			state = CLOSED_QUOTE;
		line++;
	}
	return (state);
}

char	*close_quotes(char *line)
{
	char	*quote_line;
	char	*tmp;
	t_quote	quoted;

	quote_line = NULL;
	tmp = NULL;
	if (!line)
		return (NULL);
	quoted = check_quotes(line);
	while (quoted)
	{
		if (quoted == SINGLE_QUOTE)
			quote_line = readline(QUOTE_PROMPT);
		else if (quoted == DOUBLE_QUOTE)
			quote_line = readline(DQUOTE_PROMPT);
		else
			quote_line = readline(BQUOTE_PROMPT);
		quoted = check_quotes(quote_line);
		tmp = line;
		line = ft_strjoin_sep(line, quote_line, "\n");
		tmp = ft_free_safe(tmp);
		quote_line = ft_free_safe(quote_line);
	}
	return (line);
}
