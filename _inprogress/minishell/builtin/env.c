/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 23:56:23 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bi_env(t_shdata *shdata, char **args)
{
	int	sep;
	int	isarg;

	sep = '\n';
	isarg = (args[1] != NULL);
	if (isarg && (ft_strncmp(args[1], "-0", 3) || args[2]))
		return (-1);
	sep *= !isarg;
	return (print_var_list(shdata->environ, sep));
}
