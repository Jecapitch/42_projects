/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/20 23:21:56 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_var_key(t_node_2 *node)
{
	t_var	*var;

	var = NULL;
	if (!node)
		return (NULL);
	var = (t_var *)node->content;
	if (!var)
		return (NULL);
	return (var->key);
}

char	*get_var_val(t_node_2 *node)
{
	t_var	*var;

	var = NULL;
	if (!node)
		return (NULL);
	var = (t_var *)node->content;
	if (!var)
		return (NULL);
	return (var->value);
}

t_node_2	*search_var(t_list_2*var_list, const char *var_key)
{
	t_node_2	*node;
	char		*key;

	node = NULL;
	key = NULL;
	if (!var_key || !var_list)
		return (NULL);
	node = var_list->first;
	while (node)
	{
		key = get_var_key(node);
		if (ft_strncmp(var_key, key, ft_strlen(var_key) + 1) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

int	print_var_list(const t_list_2*var_list, int sep, \
					int isenv, int include_blank)
{
	t_node_2	*node;
	t_var		*var;

	node = NULL;
	var = NULL;
	if (!var_list)
		return (EX_SUCCESS);
	node = var_list->first;
	while (node)
	{
		var = (t_var *)node->content;
		if (!(isenv && !var->isenv) && (var->vallen || include_blank))
			if (printf("%s%c", var->keyval, sep) == -1)
				return (EX_FAILURE);
		node = node->next;
	}
	printf("\n");
	return (EX_SUCCESS);
}

size_t	var_key_len(char *variable)
{
	size_t	len;

	len = 0;
	if (!variable || (!ft_isalpha(*variable) && !ft_isset(*variable, "_?$")))
		return (0);
	while (variable[len] && (ft_isalnum(variable[len]) || variable[len] == '_'))
		len++;
	if (!len && ft_isset(variable[0], "?$") \
			&& (!variable[1] || variable[1] == '='))
		len = 1;
	return (len);
}
