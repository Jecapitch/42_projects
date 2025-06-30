/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 15:59:57 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	export_var(t_shdata *shdata, t_list *var_list, \
				char *key, char *value)
{
	t_node	*node;

	node = NULL;
	if (!key || !(*key)) 
		return (-1);
	node = search_var(key, shdata->variables);
	if (add_var_list(shdata->variables, node, key, value))
		return (-1);
	if (var_list == shdata->environ || ft_strncmp(key, "HOME", 5))
	{
		node = search_var(key, shdata->environ);
		if (add_var_list(shdata->environ, node, key, value))
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
	if (!newval)
		var->value = ft_strdup("''");
	else
		var->value = ft_strdup(newval);
	if (!var->value)
		return (-1);
	return (0);
}

t_node	*reset_node(t_list *var_list, t_node *node)
{
	t_var	*var;

	var = NULL;
	if (!var_list)
		return (NULL);
	if (!node)
		node = ft_newnode(NULL);
	if (!node)
		return (NULL);
	if (!node->content)
		node->content = ft_calloc(1, sizeof(t_var));
	if (!node->content)
		return (ft_free_nul(node), NULL);
	var = (t_var *)node->content;
	clear_var(var);
	ft_append(var_list, node);
	return (node);
}

void	clear_var(void *node_content)
{
	t_var	*var;

	var = (t_var *)node_content;
	ft_free_nul(var->key);
	ft_free_nul(var->value);
	var->key = NULL;
	var->value = NULL;
	var->keylen = 0;
}

int	export_var_default(t_shdata *shdata)
{
	char	buffer[PATH_MAX + 1];

	ft_bzero(buffer, PATH_MAX + 1);
	if (export_var(shdata, shdata->environ, \
				"PWD", getcwd(buffer, PATH_MAX + 1)) == -1 \
		|| export_var(shdata, shdata->environ, \
						"OLDPWD", \
						get_var_val(search_var("OLDPWD", shdata->environ)))
		|| export_var(shdata, shdata->variables, \
					"HISTSIZE", HISTORY_SIZE) == -1 \
		|| export_var(shdata, shdata->variables, \
					"HISTFILE", HISTORY_FILE) == -1) 
		return (-1);
	return (0);
}
