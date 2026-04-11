/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 22:21:17 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 21:10:18 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	preflag_helper(t_line *line, size_t *i);
static void	index_increment(size_t *i, size_t *j);

static void	preflag_helper(t_line *line, size_t *i)
{
	if (is_quote(line->line[*i]))
	{
		line->flags[(*i)] |= (F_DQUOTE * (line->quote_state == DOUBLE_QUOTE)) \
						| (F_QUOTE * (line->quote_state == SINGLE_QUOTE));
		line->flags[*i] &= ~F_REGULAR;
		line->quote_state = get_quote_state(line, (*i));
		line->flags[(*i)] |= (F_DQUOTE * (line->quote_state == DOUBLE_QUOTE)) \
						| (F_QUOTE * (line->quote_state == SINGLE_QUOTE));
	}
	else if (line->quote_state != SINGLE_QUOTE && line->line[*i] == '\\')
	{
		*i += (line->line[*i + 1] != '\0');
		if (line->line[*i])
			line->flags[*i] |= F_REGULAR;
	}
	else if (line->quote_state == CLOSED_QUOTE && line->line[*i] == ';')
		line->flags[*i] |= F_SEMICOLON;
	else if (line->quote_state == CLOSED_QUOTE && line->line[*i] == ' ')
		line->flags[*i] |= F_SPACE;
	else if (line->quote_state != SINGLE_QUOTE && line->line[*i] == '$')
		line->flags[*i] |= F_DOLLAR;
}

int	preflag_line(t_line *line)
{
	size_t	i;

	i = 0;
	line->len = ft_strlen(line->line);
	if (!line->line)
		return (-1);
	line->flags = ft_free_safe(line->flags);
	line->flags = ft_calloc(line->len + 1, sizeof(t_flag));
	if (!line->flags)
		return (-1);
	while (line->line[i])
	{
		line->quote_state = get_quote_state(line, i);
		line->flags[i] |= F_REGULAR;
		preflag_helper(line, &i);
		i++;
	}
	return (line->len = i, 0);
}

int	flag_line(t_line *line)
{
	size_t	i;
	size_t	j;
	char	*newline;

	if (init_flag_fun(line, &i, &j, &newline) == -1)
		return (-1);
	while (line->line[i])
	{
		init_flag_value(line, i, newline, j);
		if (is_quote(line->line[i]) \
				&& (!line->quote_state || line->line[i] == line->quote_state))
			opening_quote_flag(line, &i, &j);
		else if (line->quote_state == SINGLE_QUOTE)
			escape_quote(line, &i, newline, &j);
		else if (line->line[i] == '\\')
			escaping(line, &i, newline, &j);
		else if (!line->quote_state && ft_isset(line->line[i], "<>"))
			redirect_flag(line, &i, newline, &j);
		else if (ft_isset(line->line[i], OPERATORS))
			line->flags[j] |= symbol_flag(line, i);
		if (line->line[i])
			index_increment(&i, &j);
	}
	return (line->line = ft_free_safe(line->line), line->line = newline, \
			line->len = j, 0);
}

static void	index_increment(size_t *i, size_t *j)
{
	(*i)++;
	(*j)++;
}
