/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/25 12:41:59 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*strip_line(const char *line)
{
	char	*line_to_strip;
	char	*new_line;

	line_to_strip = (char *)line;
	if (!line)
		return (NULL);
	new_line = ft_strstrip(line_to_strip);
	ft_free_nul(line_to_strip);
	return (new_line);
}

t_quote	check_quotes(const char *line)
{
	int	state;

	state = CLOSED_QUOTE;
	while (*line)
	{
		if (state == CLOSED_QUOTE \
			&& (*line == SINGLE_QUOTE || *line == DOUBLE_QUOTE))
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
		else
			quote_line = readline(DQUOTE_PROMPT);
		tmp = line;
		line = ft_strjoin(line, "\n");
		ft_free_nul(tmp);
		tmp = line;
		line = ft_strjoin(line, quote_line);
		ft_free_nul(quote_line);
		ft_free_nul(tmp);
		quoted = check_quotes(line);
	}
	return (line);
}
