/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/28 20:10:52 by Jeremie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_node	*search_var(const char *var, const t_list *var_list)
{
	t_node	*node;
	char	*key;
	size_t	len;
	t_var	*nvar;

	node = NULL;
	key = NULL;
	nvar = NULL;
	len = 0;
	if (!var || !var_list)
		return (0);
	node = var_list->first;
	while (node)
	{
		nvar = (t_var *)node->content;
		key = nvar->key;
		len = nvar->keylen + 1;
		if (ft_strncmp(var, key, len) == 0)
			break ;
		node = node->next;
	}
	return (node);
}

int	export_var(t_shdata *shdata, t_list *var_list, char *key, char *val)
{
	t_node	*node;
	t_var	*var;

	node = NULL;
	var = NULL;
	if (!key || !(*key))
		return (-1);
	node = search_var(key, var_list);
	node = reset_node(var_list, node);
	if (!node)
		return (-1);
	if (add_var_list(node, key, val))
		return (-1);
	var = (t_var *)node->content;
	if (ft_strncmp(var->key, "HOME", 5) == 0)
		shdata->home_path = var->value;
	return (0);
}

int	add_var_list(t_node *node, char *newkey, char *newval)
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
	if (!var->key)
		return (-1);
	node->content = var;
	var->keylen = ft_strlen(var->key);
	if (newval)
	{
		var->value = ft_strdup(newval);
		if (!var->value)
			return (-1);
	}
	var->key_val = ft_strjoin_sep(var->key, var->value, '=');
	if (!var->key_val)
		return (-1);
	return (0);
}

t_node	*reset_node(t_list *var_list, t_node *node)
{
	t_var	*var;

	if (node)
	{
		var = (t_var *)node->content;
		ft_free_nul(var->key);
		ft_free_nul(var->value);
		ft_free_nul(var->key_val);
		ft_free_nul(node->content);
		return (node);
	}
	node = ft_newnode(NULL);
	if (!node)
		return (NULL);
	ft_append(var_list, node);
	return (node);
}
