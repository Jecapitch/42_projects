/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/17 01:31:18 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_quote(int c)
{
	return (ft_isset(c, "\"'"));
}

int	get_quote_state(t_line *line, size_t i)
{
	if (!line || !line->line)
		return (0);
	if (!is_quote(line->line[i]))
		return (line->quote_state);
	if (!line->quote_state)
		return ((line->quote_state = line->line[i]));
	if (line->quote_state == line->line[i])
		return ((line->quote_state = CLOSED_QUOTE));
	return (line->quote_state);
}

t_quote	check_quotes(t_line *line, size_t len)
{
	size_t	i;

	line->quote_state = CLOSED_QUOTE;
	i = 0;
	if (!line || !line->line)
		return (0);
	while (line->line[i])
	{
		if (line->quote_state != SINGLE_QUOTE && i < len - 1 \
				&& line->line[i] == '\\')
			i += 2;
		else
			line->quote_state = get_quote_state(line, i++);
	}
	return (line->quote_state);
}

char	*close_quotes(t_line *line)
{
	char	*quote_line;
	t_quote	quoted;
	char	*tmp;

	quote_line = NULL;
	tmp = NULL;
	if (!line || !line->line)
		return (NULL);
	quoted = check_quotes(line, line->len);
	while (quoted)
	{
		quote_line = readline(&((quoted == DOUBLE_QUOTE) \
			* (DQUOTE_PROMPT - QUOTE_PROMPT))[QUOTE_PROMPT]);
		if (!quote_line)
			return (line->line = ft_free_safe(line->line), NULL);
		tmp = line->line;
		line->line = ft_strjoin_sep(line->line, quote_line, "\n");
		quote_line = ft_free_safe(quote_line);
		tmp = ft_free_safe(tmp);
		line->len = ft_strlen(line->line);
		quoted = check_quotes(line, line->len);
	}
	return (line->line);
}
