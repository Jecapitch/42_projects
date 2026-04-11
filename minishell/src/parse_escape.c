/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_escape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:21:17 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 04:09:07 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	escaping(t_line *line, size_t *i, char *newline, size_t *j)
{
	(*i)++;
	if (!line->line[*i])
		return ;
	if (!line->quote_state)
		escape_regular(line, i, newline, j);
	else
		escape_dquote(line, i, newline, j);
}

void	escape_regular(t_line *line, size_t *i, char *newline, size_t *j)
{
	newline[*j] = line->line[*i];
	line->flags[*j] |= F_REGULAR;
}

void	escape_quote(t_line *line, size_t *i, char *newline, size_t *j)
{
	while (line->line[*i] && line->line[*i] != SINGLE_QUOTE)
	{
		newline[*j] = line->line[*i];
		line->flags[*j] = (F_REGULAR);
		(*i)++;
		(*j)++;
	}
	newline[*j] = line->line[*i];
	line->flags[*j] = F_QUOTE;
	line->quote_state = CLOSED_QUOTE;
}

void	escape_dquote(t_line *line, size_t *i, char *newline, size_t *j)
{
	if (!ft_isset(line->line[*i], "$\"\\"))
	{
		newline[*j] = '\\';
		line->flags[*j] = (F_REGULAR | F_DQUOTE);
		(*j)++;
	}
	newline[*j] = line->line[*i];
	line->flags[*j] |= (F_REGULAR | F_DQUOTE);
}
