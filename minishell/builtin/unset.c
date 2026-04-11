/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:15:31 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/20 23:19:45 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_unset(t_shdata *shdata, char **argv)
{
	t_node_2	*node;
	size_t		i;

	node = NULL;
	i = 1;
	if (!argv || !(*argv))
		return (EX_FAILURE);
	while (argv[i])
	{
		node = search_var(shdata->variables, argv[i]);
		ft_extract_2(shdata->variables, node);
		if (node)
			free_var(node->content);
		node = ft_free_safe(node);
		i++;
	}
	update_environ(shdata);
	return (EX_SUCCESS);
}
