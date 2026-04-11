/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 22:25:57 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/20 22:30:48 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_line	*alloc_line(char *s, t_flag *flags)
{
	t_line	*line;

	line = NULL;
	line = ft_calloc(1, sizeof(t_line));
	if (!line)
		return (NULL);
	line->line = s;
	line->flags = flags;
	line->len = ft_strlen(s);
	line->quote_state = 0;
	return (line);
}

void	*free_line_struct(t_line *line)
{
	if (!line)
		return (NULL);
	line->line = ft_free_safe(line->line);
	line->flags = ft_free_safe(line->flags);
	line = ft_free_safe(line);
	return (NULL);
}

void	free_cmdline(t_line *line)
{
	line->line = ft_free_safe(line->line);
	line->flags = ft_free_safe(line->flags);
}
