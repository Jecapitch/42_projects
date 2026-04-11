/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:50:13 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/23 21:22:28 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_exit(t_shdata *shdata, t_pipeline *pipeline, char **argv, int status)
{
	if (argv && argv[0] && argv[1] && argv[2])
	{
		errno = E2BIG;
		perror(argv[0]);
		return (128);
	}
	if (argv && argv[0] && argv[1])
	{
		if (ft_isint(argv[1]))
			status = ft_atoi(argv[1]);
		else
		{
			errno = EINVAL;
			ft_fprintf(STDERR_FILENO, "exit: %s: numeric argument " \
										"required\n", argv[1]);
			status = 128;
		}
	}
	if (argv)
		ft_printf("exit\n");
	free_pipeline(pipeline);
	end_program(shdata);
	exit((unsigned char)status);
}
