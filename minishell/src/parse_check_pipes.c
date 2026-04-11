/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/17 20:47:16 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_end_pipe(t_line *line, size_t len)
{
	size_t	bs;

	bs = 0;
	if (!line || !line->line || !len)
		return (0);
	while (len && ft_isspace(line->line[len - 1]))
		len--;
	bs = check_bs(line, len);
	return (!bs && line->line[len - 1] == '|');
}

int	check_pipes(t_line *line)
{
	size_t	i;

	i = 0;
	if (!line || !line->line)
		return (0);
	while (line->line[i])
	{
		while (ft_isspace(line->line[i]))
			i++;
		if (line->line[i] == '|')
			return (ft_fprintf(STDERR_FILENO, PARSE_ERR, '|'), -1);
		i = loop_to_set(line, i, "|;<>");
		if (line->line[i] == '|')
		{
			i++;
			while (ft_isspace(line->line[i]))
				i++;
			if (line->line[i] == ';')
				return (ft_fprintf(STDERR_FILENO, PARSE_ERR, ';'), -1);
			continue ;
		}
		if (line->line[i])
			i++;
	}
	return (0);
}

char	*close_pipeline(t_line *line)
{
	char	*pipeline;
	int		piped;

	pipeline = NULL;
	if (!line || !line->line)
		return (NULL);
	if (check_pipes(line) == -1)
		return (pipeline = ft_free_safe(pipeline), \
				line->line = ft_free_safe(line->line), NULL);
	piped = check_end_pipe(line, line->len);
	while (piped && line->line)
	{
		pipeline = readline("pipe > ");
		if (!pipeline)
			return (line->line = ft_free_safe(line->line), NULL);
		line->len += ft_strlen(pipeline);
		ft_strappend(&line->line, pipeline);
		if (check_pipes(line) == -1)
			return (pipeline = ft_free_safe(pipeline), \
					line->line = ft_free_safe(line->line), NULL);
		pipeline = ft_free_safe(pipeline);
		piped = check_end_pipe(line, line->len);
	}
	return (line->line);
}
