/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:21:17 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 20:06:31 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	opening_quote_flag(t_line *line, size_t *i, size_t *j)
{
	if (is_quote(line->line[*i]))
	{
		line->flags[*j] &= ~F_REGULAR;
		line->quote_state = get_quote_state(line, (*i));
		line->flags[(*j)] |= (F_DQUOTE * (line->quote_state == DOUBLE_QUOTE)) \
						| (F_QUOTE * (line->quote_state == SINGLE_QUOTE));
	}
}

int	symbol_flag(t_line *line, size_t i)
{
	if (line->line[i] == '$')
		return (F_DOLLAR);
	if (line->quote_state == CLOSED_QUOTE)
	{
		if (ft_isspace(line->line[i]))
			return (F_SPACE);
		if (line->line[i] == '~' && (!i || ft_isspace(line->line[i - 1])))
			return (F_TILDE);
		if (line->line[i] == '*')
			return (F_STAR);
		if (line->line[i] == '?')
			return (F_QUEST_MARK);
		if (line->line[i] == '|')
			return (F_PIPE);
		if (line->line[i] == ';')
			return (F_SEMICOLON);
		if (line->line[i] == '=')
			return (F_EQUAL);
	}
	return (F_REGULAR);
}

int	init_flag_fun(t_line *line, size_t *i, size_t *j, char **newline)
{
	size_t	len;

	*i = 0;
	*j = 0;
	*newline = NULL;
	line->flags = ft_free_safe(line->flags);
	line->len = ft_strlen(line->line);
	len = line->len;
	if (!line->line)
		return (-1);
	*newline = ft_calloc(len + 1, sizeof(char));
	line->flags = ft_calloc(len + 1, sizeof(t_flag));
	if (!(*newline) || !line->flags)
		return (*newline = ft_free_safe(*newline), \
				line->flags = ft_free_safe(line->flags), -1);
	return (0);
}

void	init_flag_value(t_line *line, size_t i, char *newline, size_t j)
{
	newline[j] = line->line[i];
	line->flags[j] |= (F_REGULAR \
						| (F_QUOTE * (line->quote_state == SINGLE_QUOTE)) \
						| (F_DQUOTE * (line->quote_state == DOUBLE_QUOTE)));
}
