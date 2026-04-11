/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 01:30:23 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/20 23:18:45 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_export(t_shdata *shdata, char **argv)
{
	t_node_2	*node;
	t_var		*var;
	size_t		i;

	node = NULL;
	var = NULL;
	i = 0;
	if (!argv || !argv[0])
		return (0);
	if (!argv[1])
		return (print_var_list(shdata->variables, '\n', ISENV, INCLUDE_UNDEF));
	while (argv[++i])
	{
		var = parse_var(argv[i], ISENV);
		if (!var)
			continue ;
		node = search_var(shdata->variables, var->key);
		if (!node || *var->value)
			set_var(shdata, argv[i], ISENV);
		else
			((t_var *)node->content)->isenv = ISENV;
		free_var(var);
	}
	update_environ(shdata);
	return (EX_SUCCESS);
}
