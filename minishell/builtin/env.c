/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/20 23:23:00 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_env(t_shdata *shdata, char **argv)
{
	int	sep;
	int	isarg;

	sep = '\n';
	isarg = (argv[1] != NULL);
	if (isarg && ft_strncmp(argv[1], "-0", 3))
		return (errno = EINVAL, EX_FAILURE);
	if (isarg && argv[2])
		return (errno = E2BIG, EX_FAILURE);
	sep *= !isarg;
	return (print_var_list(shdata->variables, sep, ISENV, IGNORE_UNDEF));
}
