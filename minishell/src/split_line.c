/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:34:37 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/25 20:33:53 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	count_words_flag(const t_line *line, const t_flag flag);
static size_t	countwhile_flag(const t_line *line, size_t start, \
								const t_flag flag);
static t_flag	*subflags(t_flag *flags, size_t len);

static size_t	count_words_flag(const t_line *line, const t_flag flag)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	if (!line || !line->line)
		return (0);
	if (!line->flags)
		return (1);
	while (line->flags[i])
	{
		if (!(line->flags[i] & flag))
			count++;
		while (line->flags[i] && !(line->flags[i] & flag))
			i++;
		while (line->flags[i] && (line->flags[i] & flag))
			i++;
	}
	return (count);
}

static size_t	countwhile_flag(const t_line *line, size_t start, \
								const t_flag flag)
{
	size_t	count;

	count = 0;
	if (!line || !line->line || !line->flags)
		return (0);
	while (line->flags[start] \
			&& !(line->flags[start] & flag))
	{
		start++;
		count++;
	}
	return (count);
}

t_line	**free_splitline(t_line **splitline)
{
	size_t	i;

	i = 0;
	if (!splitline)
		return (NULL);
	while (splitline[i])
	{
		splitline[i] = free_line_struct(splitline[i]);
		i++;
	}
	splitline = ft_free_safe(splitline);
	splitline = NULL;
	return (NULL);
}

static t_flag	*subflags(t_flag *flags, size_t len)
{
	t_flag	*subf;

	if (!flags)
		return (NULL);
	subf = ft_calloc(len + 1, sizeof(t_flag));
	if (!subf)
		return (NULL);
	ft_memmove(subf, flags, len * sizeof(t_flag));
	return (subf);
}

t_line	**split_line(t_line *line, const t_flag flag)
{
	t_line			**splitline;
	size_t			i;
	size_t			j;
	size_t			len;
	const size_t	n_words = count_words_flag(line, flag);

	if (!line || !line->line || !n_words)
		return (NULL);
	i = 0;
	j = 0;
	splitline = ft_calloc(n_words + 1, sizeof(t_line *));
	if (!splitline)
		return (NULL);
	while (line->flags[i] && j < n_words)
	{
		while (line->line[i] && (line->flags[i] & flag))
			i++;
		len = countwhile_flag(line, i, flag);
		splitline[j] = alloc_line(ft_substr(&line->line[i], 0, len), \
						subflags(&line->flags[i], len));
		if (!splitline[j++])
			return (splitline = free_splitline(splitline), NULL);
		i += len;
	}
	return (splitline);
}
