/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:47:55 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 06:37:29 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv)
{
	t_shdata	shdata;
	t_line		line;

	(void)argv;
	if (check_argc(argc))
		exit(EXIT_FAILURE);
	line.line = NULL;
	if (init_shdata(&shdata) == -1)
		return (end_program(&shdata), EXIT_FAILURE);
//	print_env_list(&shdata, '\n');
	while (1)
	{
		line.line = readline(shdata.prompt);
		line.line = close_quotes(line.line);
		line.line = strip_line(line.line);
		save_history(line.line, shdata.fd_history);
		if (ft_strncmp(line.line, "exit", 5) == 0)
			break ;
		ft_free_nul((line.line));
	}
	ft_free_nul(line.line);
	end_program(&shdata);
	exit(EXIT_SUCCESS);
}
