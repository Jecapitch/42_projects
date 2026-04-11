/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 21:53:19 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 01:13:35 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_end_redirect(t_line *line, size_t len)
{
	if (!line || !line->line || !len)
		return (0);
	while (ft_isspace(line->line[len - 1]))
		len--;
	if (len)
		return (line->line[len - 1] == '<' || line->line[len - 1] == '>');
	return (0);
}

int	check_redirect(t_line *line)
{
	int		c;
	size_t	i;

	i = 0;
	if (!line || !line->line)
		return (0);
	while (line->line[i])
	{
		c = '\0';
		i = loop_to_set(line, i, "<>");
		if (ft_isset(line->line[i], "<>"))
		{
			c = line->line[i];
			i += (1 + (line->line[i] == line->line[i + 1]));
		}
		while (ft_isspace(line->line[i]))
			i++;
		if (c && (ft_isset(line->line[i], ";><") || !line->line[i]))
			return (ft_fprintf(STDERR_FILENO, PARSE_ERR, c), -1);
	}
	return (0);
}

void	redirect_flag(t_line *line, size_t *i, char *newline, size_t *j)
{
	newline[*j] = ' ';
	line->flags[(*j)++] |= F_SPACE;
	if (line->line[*i + 1] == '>')
	{
		line->flags[*j] |= F_OUT_APPEND;
		(*i)++;
	}
	else if (line->line[*i + 1] == '<')
	{
		line->flags[*j] |= F_HEREDOC;
		(*i)++;
	}
	else if (line->line[*i] == '>')
		line->flags[*j] |= F_OUT_REDIR;
	else if (line->line[*i] == '<')
		line->flags[*j] |= F_IN_REDIR;
	(*j)--;
	while (ft_isspace(line->line[*i + 1]))
		(*i)++;
}
