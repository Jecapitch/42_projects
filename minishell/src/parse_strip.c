/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_strip.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/01 20:36:06 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*convert_nl(char *line)
{
	char	*tmp;
	char	**split_nl;
	size_t	i;

	tmp = NULL;
	if (!line || !(*line))
		return (line = ft_free_safe(line), NULL);
	split_nl = ft_split(line, '\n');
	line = ft_free_safe(line);
	if (!split_nl)
		return (ft_free_str_arr(split_nl), NULL);
	line = ft_strdup(split_nl[0]);
	if (!line)
		return (ft_free_str_arr(split_nl), NULL);
	i = 1;
	while (line && split_nl[i])
	{
		tmp = line;
		line = ft_strjoin_sep(line, split_nl[i], "\\n");
		tmp = ft_free_safe(tmp);
		i++;
	}
	return (ft_free_str_arr(split_nl), line);
}

char	*strip_line(char *line)
{
	char	*newline;
	char	*tmp;
	size_t	len;

	tmp = line;
	newline = NULL;
	if (!line || !(*line))
		return (line = ft_free_safe(line), NULL);
	while (ft_isspace(*line))
		line++;
	len = ft_strlen(line);
	while (len > 1 && ft_isspace(line[len - 1]))
		len--;
	len += (line[len - 1] == '\\');
	newline = ft_substr(line, 0, len);
	tmp = ft_free_safe(tmp);
	return (newline);
}
