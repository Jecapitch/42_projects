/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 01:32:05 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	export_var(t_shdata *shdata, t_list *var_list, \
				char *variable, char *escvar)
{
	t_node	*node;
	char	**keyval;

	node = NULL;
	keyval = NULL;
	if (!variable || !(*variable) \
		|| ft_countwhile(escvar, 0) == ft_strlen(variable))
		return (-1);
	keyval = ft_split_mark(variable, escvar, "=");
	if (!keyval)
		return (-1);
	node = search_var(keyval[0], shdata->variables);
	if (add_var_list(shdata->variables, node, keyval[0], keyval[1]))
		return (-1);
	if (var_list == shdata->environ || ft_strncmp(keyval[0], "HOME", 5))
	{
		node = search_var(keyval[0], shdata->environ);
		if (add_var_list(shdata->environ, node, keyval[0], keyval[1]))
			return (-1);
	}
	update_shdata_env(shdata);
	return (0);
}

int	add_var_list(t_list *var_list, t_node *node, char *newkey, char *newval)
{
	t_var	*var;

	var = NULL;
	if (!newkey)
		return (-1);
	var = ft_calloc(sizeof(t_var), 1);
	if (!var)
		return (-1);
	var->key = ft_strdup(newkey);
	var->value = NULL;
	node = reset_node(var_list, node);
	if (!var->key || !node)
		return (ft_free_nul(var->key), var->key = NULL, -1);
	node->content = var;
	var->keylen = ft_strlen(var->key);
	if (newval)
	{
		var->value = ft_strdup(newval);
		if (!var->value)
			return (-1);
	}
	var->keyval = ft_strjoin_sep(var->key, var->value, '=');
	if (!var->keyval)
		return (-1);
	return (0);
}

t_node	*reset_node(t_list *var_list, t_node *node)
{
	t_var	*var;

	var = NULL;
	if (!var_list)
		return (NULL);
	if (node)
	{
		var = (t_var *)node->content;
		ft_free_nul(var->key);
		ft_free_nul(var->value);
		ft_free_nul(var->keyval);
		ft_free_nul(node->content);
		return (node);
	}
	node = ft_newnode(NULL);
	if (!node)
		return (NULL);
	ft_append(var_list, node);
	return (node);
}

void	free_var(void *node_content)
{
	t_var	*var;

	var = (t_var *)node_content;
	ft_free_nul(var->key);
	ft_free_nul(var->value);
	ft_free_nul(var->keyval);
	var->key = NULL;
	var->value = NULL;
	var->keyval = NULL;
	var->keylen = 0;
}

int	export_var_default(t_shdata *shdata)
{
	char	buffer[PATH_MAX + 1];

	ft_bzero(buffer, PATH_MAX + 1);
	if (export_var(shdata, shdata->environ, \
				"PWD", getcwd(buffer, PATH_MAX + 1)) == -1 \
		|| export_var(shdata, shdata->environ, \
						"OLDPWD", 
		|| export_var(shdata, shdata->variables, \
					"HISTSIZE", HISTORY_SIZE) == -1 \
		|| export_var(shdata, shdata->variables, \
					"HISTFILE", HISTORY_FILE) == -1 \
		|| export_var(shdata, shdata->variables, \
					"OLDPWDFILE", OLDPWD_FILE) == -1)
		return (-1);
	return (0);
}
