/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_bs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/07 17:25:18 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_bs(t_line *line, size_t len)
{
	size_t	n;

	n = 0;
	if (!line || !line->line || !len)
		return (0);
	while (len && line->line[len - 1] == '\\')
	{
		n++;
		len--;
	}
	return (n % 2);
}

char	*close_bs(t_line *line)
{
	char	*bs_line;
	char	*tmp;

	bs_line = NULL;
	tmp = NULL;
	if (!line || !line->line)
		return (NULL);
	line->line = strip_line(line->line);
	while (check_bs(line, line->len) && line)
	{
		tmp = line->line;
		line->len -= 1;
		line->line = ft_substr(line->line, 0, line->len);
		tmp = ft_free_safe(tmp);
		bs_line = readline("> ");
		if (!bs_line)
			return (line->line = ft_free_safe(line->line), NULL);
		ft_strappend(&line->line, bs_line);
		line->line = strip_line(line->line);
		line->len = ft_strlen(line->line);
		bs_line = ft_free_safe(bs_line);
	}
	return (line->line);
}
