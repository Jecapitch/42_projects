/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/28 01:23:09 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv)
{
	t_shdata	shdata;
	t_line		line;

	(void)argv;
	if (argc != 1)
		return (ft_fprintf(STDERR_FILENO, NAME": No argument allowed\n"), \
				EXIT_FAILURE);
	line.line = NULL;
	line.type = NULL;
	if (init_shdata(&shdata) == -1)
		return (end_program(&shdata), EXIT_FAILURE);
	while (1)
	{
		line.line = readline(shdata.prompt);
		line.line = close_quotes(line.line);
		line.line = strip_line(line.line);
		history_add(shdata.sh_history, line.line);
		if (ft_strncmp(line.line, "exit", 5) == 0)
			break ;
	}
	end_program(&shdata);
	exit(EXIT_SUCCESS);
}
