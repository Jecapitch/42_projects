/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/25 21:09:11 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_flag_line(t_line *line)
{
	size_t	i;

	i = 0;
	if (!line || !line->line)
		return ;
	while (i < line->len)
	{
		if (line->line[i] == ' ')
			ft_printf("sp  ");
		else if (line->line[i] == '\n')
			ft_printf("\\n  ");
		else if (line->line[i] == '\t')
			ft_printf("\\t  ");
		else if (line->line[i] == '\a')
			ft_printf("bel ");
		else
			ft_printf("%-3c ", line->line[i]);
		ft_printf("%#.7x\n", (int)line->flags[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_shdata	shdata;
	t_line		line;

	(void)argv;
	if (argc != 1)
	{
		errno = E2BIG;
		return (perror(NAME), errno);
	}
	if (init_shdata(&shdata, &line) == -1)
		return (perror("minishell: init"), end_program(&shdata), errno);
	while (1)
	{
		set_sigint_handler(inter_sigint_handler);
		set_sigquit_handler(SIG_IGN);
		line.line = line_read(&shdata, &line);
		set_sigint_handler(SIG_IGN);
		if (!line.line)
			continue ;
		history_add(&shdata, line.line);
		if (preflag_line(&line) == -1)
			ft_fprintf(STDERR_FILENO, NAME": parse error\n");
		process_cmds(&shdata, &line);
		free_cmdline(&line);
	}
}
