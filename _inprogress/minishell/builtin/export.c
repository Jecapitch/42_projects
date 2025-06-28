/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:30:23 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/28 02:16:15 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	export(t_shdata *shdata)
{
	char	**key_val;
	int		status;

	key_val = NULL;
	status = 0;
	if (argc < 2)
		return (0);
	while (*argv)
	{
		if (ft_strchr(*argv, '=', ft_strlen(argv) + 1))
		{
			key_val = ft_split(*argv);
			if (export_var(shdata, shdata->sh_environ, key_val[0], key_val[1]))
				return (ft_free_all(key_val), key_val = NULL, -1);
			ft_free_all(key_val);
			key_val = NULL;
		}
		argv++;
	}
	return (0);
}
