/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:53:16 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 19:07:38 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	tilde_substitue(char **line, size_t i);
static int	dollar_substitue(t_list_2 *var_list, char **line, size_t *i);

static int	tilde_substitue(char **line, size_t i)
{
	char	*subline;

	subline = ft_substr(*line, 0, i);
	if (!subline || ft_strappend(&subline, getenv("HOME")) \
		|| ft_strappend(&subline, *line + i + 1))
		return (-1);
	*line = ft_free_safe(*line);
	*line = subline;
	return (0);
}

static int	dollar_substitue(t_list_2 *var_list, char **line, size_t *i)
{
	char		*subline;
	char		*varname;
	char		*val;
	size_t		len;

	varname = NULL;
	val = NULL;
	subline = ft_substr(*line, 0, *i);
	len = ft_isset((*line)[*i + 1], "$?") \
			+ ft_countwhile_condition(&(*line)[*i + 1], ft_isalnum);
	varname = ft_substr(*line, *i + 1, len);
	val = get_var_val(search_var(var_list, varname));
	if (!subline || !varname \
		|| ft_strappend(&subline, val) \
		|| ft_strappend(&subline, *line + *i + len + 1))
		return (varname = ft_free_safe(varname), \
				subline = ft_free_safe(subline), \
				*line = ft_free_safe(*line), \
				-1);
	varname = ft_free_safe(varname);
	*line = ft_free_safe(*line);
	*line = subline;
	if (!val)
		--*i;
	return (0);
}

char	*expand_variable(t_shdata *shdata, t_line *line)
{
	size_t	i;

	i = 0;
	if (!line || !line->line)
		return (NULL);
	while (line->line[i])
	{
		if (!(line->flags[i] & (F_TILDE | F_DOLLAR)))
		{
			i++;
			continue ;
		}
		if (((line->flags[i] & F_TILDE) \
				&& tilde_substitue(&line->line, i) == -1) \
			|| ((line->flags[i] & F_DOLLAR) \
				&& dollar_substitue(shdata->variables, &line->line, &i) == -1))
			return (line->line = ft_free_safe(line->line), NULL);
		preflag_line(line);
		line->len = ft_strlen(line->line);
		i++;
	}
	return (line->line);
}

char	*expand_heredoc(t_shdata *shdata, char *text)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (text[i])
	{
		if (text[i] == '\\')
			i += (text[i + 1] != '\0');
		else if (text[i] == '$')
		{
			if (dollar_substitue(shdata->variables, &text, &i) == -1)
				return (text = ft_free_safe(text), NULL);
		}
		i++;
	}
	i = 0;
	while (text[i])
	{
		if (text[i] != '\\' || (text[i] == '\\' && text[i + 1] == '\\'))
			text[j++] = text[i];
		i++;
	}
	text[j] = '\0';
	return (text);
}

void	remove_quotes(t_line *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line->line[i])
	{
		if (line->flags[i] & F_REGULAR)
		{
			line->line[j] = line->line[i];
			line->flags[j] = line->flags[i];
			j++;
		}
		i++;
	}
	while (line->line[j])
	{
		line->line[j] = '\0';
		line->flags[j] = F_EOL;
		j++;
	}
	line->len = ft_strlen(line->line);
}
