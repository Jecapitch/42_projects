/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 20:47:15 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list_2	*init_var_list(void)
{
	t_list_2	*var_list;

	var_list = NULL;
	var_list = ft_init_list_2();
	return (var_list);
}

t_var	*parse_var(char *variable, int isenv)
{
	t_var	*var;
	size_t	len;

	var = NULL;
	if (!variable || !(*variable))
		return (NULL);
	len = var_key_len(variable);
	if (variable[len] && variable[len] != '=')
		return (NULL);
	var = ft_calloc(1, sizeof(t_var));
	if (!var)
		return (NULL);
	var->key = ft_substr(variable, 0, len);
	if (variable[len] && variable[len + 1])
		var->value = ft_strdup(variable + len + 1);
	else
		var->value = ft_strdup("");
	var->keyval = ft_strdup(variable);
	if (!var->key || !var->value || !var->keyval)
		return (clear_var(var), var = ft_free_safe(var), NULL);
	var->keylen = len;
	var->vallen = ft_strlen(var->value);
	var->isenv = isenv;
	var->equal = (variable[len] == '=') * '=';
	return (var);
}

int	set_var(t_shdata *shdata, char *variable, int isenv)
{
	t_node_2	*node;
	t_var		*var;

	node = NULL;
	var = NULL;
	if (!variable || !(*variable) \
		|| (!ft_isalpha(*variable) && !ft_isset(*variable, "_?$")))
	{
		ft_fprintf(STDOUT_FILENO, "%s: not a valid identifier\n", \
											variable);
		return (-1);
	}
	var = parse_var(variable, isenv);
	if (!var)
		return (-1);
	node = search_var(shdata->variables, var->key);
	if (set_node_2(shdata->variables, node, var) == -1)
		return (clear_var(var), var = ft_free_safe(var), -1);
	update_shdata_env(shdata, var->key, var->value);
	return (0);
}

int	set_node_2(t_list_2*var_list, t_node_2 *node, t_var *var)
{
	if (!node)
	{
		node = ft_newnode_2(var);
		if (!node)
			return (-1);
		ft_append_2(var_list, node);
		return (0);
	}
	free_var(node->content);
	node->content = var;
	return (0);
}
