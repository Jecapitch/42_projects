/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:30:23 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 01:40:06 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bi_export(t_shdata *shdata, char **args)
{
	char	**keyval;
	int		status;

	keyval = NULL;
	status = 0;
	if (argc < 2)
		return (0);
	while (*argv)
	{
		if (ft_strchr(*argv, '=', ft_strlen(args) + 1))
		{
			keyval = ft_split(*argv);
			if (export_var(shdata, shdata->environ, keyval[0], \
							keyval[1]) == -1)
				return (ft_free_all(keyval), keyval = NULL, -1);
			ft_free_all(keyval);
			keyval = NULL;
		}
		argv++;
	}
	return (0);
}
