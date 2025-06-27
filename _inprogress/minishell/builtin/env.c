/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 06:36:49 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	export_env(t_shdata *shdata, char *key_val)
{
	return (export_var(shdata->sh_environ, key_val));
}

int	load_environ(t_shdata *shdata)
{
	size_t	i;

	i = 0;
	if (!shdata)
		return (-1);
	if (init_var_list(shdata->sh_environ))
		return (errno);
	while (environ[i])
	{
		if (export_env(shdata, environ[i]))
			return (errno);
		i++;
	}
	return (0);
}

int	print_env_list(t_shdata *shdata, char sep)
{
	return (print_var_list(shdata->sh_environ, sep));
}
