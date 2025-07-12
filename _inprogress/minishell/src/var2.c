/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/12 01:15:09 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_var	*parse_var(char *variable, int isenv)
{
	t_var	*var;
	size_t	len;

	var = NULL;
	len = ft_countwhile_condition(variable, ft_isalpha);
	if (!len || (variable[len] && variable[len] != '='))
		return (NULL);
	var = ft_calloc(1, sizeof(t_var));
	if (!var)
		return (NULL);
	var->key = ft_substr(variable, 0, len);
	var->keylen = len;
	var->isenv = isenv;
	if (!variable[len])
		var->keyval = ft_strdup(var->key);
	else if (variable[len + 1])
		var->value = ft_strdup(variable + len + 1);
	else
		var->value = ft_strdup("");
	if (var->value)
		var->keyval = ft_strjoin_sep(var->key, var->value, "=");
	var->vallen = ft_strlen(var->value);
	if (!var->key || !var->keyval || (variable[len] && !var->value))
		return (clear_var(var), var = ft_free_safe(var), NULL);
	return (var);
}

int	set_var(t_shdata *shdata, char *variable, int isenv)
{
	t_node	*node;
	t_var	*var;
	int		found;

	node = NULL;
	var = NULL;
	if (!variable || !(*variable))
		return (-1);
	var = parse_var(variable, isenv);
	if (!var)
		return (-1);
	node = search_var(shdata->variables, var->key);
	found = (node != NULL);
	node = set_node(node, var);
	if (!node)
		return (-1);
	if (!found)
		ft_append(shdata->variables, node);
	update_shdata_env(shdata, node);
	return (0);
}

void	clear_var(void *var_struct)
{
	t_var	*var;

	var = (t_var *)var_struct;
	var->key = ft_free_safe(var->key);
	var->value = ft_free_safe(var->value);
	var->keyval = ft_free_safe(var->keyval);
	ft_bzero(var, sizeof(var));
}

t_node	*set_node(t_node *node, t_var *var)
{
	t_var	*node_var;

	node_var = NULL;
	if (!var)
		return (NULL);
	if (!node)
	{
		node = ft_newnode(NULL);
		if (!node)
			return (NULL);
		ft_bzero(node, sizeof(t_node));
	}
	node_var = (t_var *)node->content;
	clear_var(node_var);
	node_var = ft_free_safe(node_var);
	node_var = var;
	return (node);
}
