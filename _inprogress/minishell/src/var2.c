/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/12 13:28:09 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_var	*parse_var(char *variable, int isenv)
{
	t_var	*var;
	size_t	len;

	var = NULL;
	len = 0;
	if (!variable || !(*variable) \
		|| (!ft_isalpha(*variable) && *variable != '_'))
		return (NULL);
	while (variable[len] && (ft_isalnum(variable[len]) || variable[len] == '_'))
		len++;
	var = ft_calloc(1, sizeof(t_var));
	if (!var || !len || (variable[len] && variable[len] != '='))
		return (var = ft_free_safe(var), NULL);
	var->key = ft_substr(variable, 0, len);
	var->keylen = len;
	var->isenv = isenv;
	var->equal[0] = (variable[len] == '=') * '=';
	if (variable[len + 1])
		var->value = ft_strdup(variable + len + 1);
	else if (variable[len])
		var->value = ft_strdup("");
	var->keyval = ft_strjoin_sep(var->key, var->value, var->equal);
	if (!var->key || !var->keyval || !var->value)
		return (clear_var(var), var = ft_free_safe(var), NULL);
	return (var->vallen = ft_strlen(var->value), var);
}

int	set_var(t_shdata *shdata, char *variable, int isenv)
{
	t_node	*node;
	t_var	*var;

	node = NULL;
	var = NULL;
	if (!variable || !(*variable) \
		|| (!ft_isalpha(*variable) && *variable != '_'))
		return (-1);
	var = parse_var(variable, isenv);
	if (!var)
		return (-1);
	node = search_var(shdata->variables, var->key);
	if (set_node(shdata->variables, node, var) == -1)
		return (clear_var(var), var = ft_free_safe(var), -1);
	update_shdata_env(shdata, node);
	return (0);
}

void	clear_var(void *var_struct)
{
	t_var	*var;

	if (!var_struct)
		return ;
	var = (t_var *)var_struct;
	var->key = ft_free_safe(var->key);
	var->value = ft_free_safe(var->value);
	var->keyval = ft_free_safe(var->keyval);
	ft_bzero(var, sizeof(t_var));
}

int	set_node(t_list *var_list, t_node *node, t_var *var)
{
	if (!node)
	{
		node = ft_newnode(var);
		if (!node)
			return (-1);
		ft_append(var_list, node);
		return (0);
	}
	clear_var(node->content);
	node->content = ft_free_safe(node->content);
	node->content = var;
	return (0);
}
