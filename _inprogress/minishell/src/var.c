/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 06:17:27 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	export_var(t_list *var_list, char *keyval)
{
	t_node	*node;
	char	**key_val;
	char	*key;
	char	*val;

	node = NULL;
	key_val = NULL;
	key = NULL;
	val = NULL;
	if (!keyval || !(*keyval))
		return (0);
	key_val = ft_split(keyval, '=');
	if (!key_val)
		return (errno);
	key = key_val[0];
	val = key_val[1];
	node = search_var(key, var_list);
	if (add_var_list(var_list, node, \
			key, val) == -1)
		return (ft_free_all(key_val), errno);
	ft_free_all(key_val);
	return (0);
}

t_node	*search_var(const char *var, const t_list *var_list)
{
	t_node	*node;
	char	*key;
	size_t	len;

	node = NULL;
	key = NULL;
	len = 0;
	if (!var || !var_list)
		return (0);
	node = var_list->first;
	while (node)
	{
		key = ((t_var *)node->content)->key;
		len = ((t_var *)node->content)->keylen;
		if (ft_strncmp(var, key, len + 1) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_node	*set_node(t_list *var_list, t_node *node)
{
	if (node)
	{
		ft_free_nul(((t_var *)node->content)->key);
		ft_free_nul(((t_var *)node->content)->value);
		ft_free_nul(((t_var *)node->content)->key_val);
		ft_free_nul(node->content);
		return (node);
	}
	node = ft_newnode(NULL);
	if (!node)
		return (NULL);
	ft_append(var_list, node);
	return (node);
}

int	add_var_list(t_list *var_list, t_node *node, char *newkey, char *newval)
{
	t_var	*var;

	var = NULL;
	if (!newkey)
		return (-1);
	node = set_node(var_list, node);
	var = malloc(sizeof(t_var));
	if (!node || !var)
		return (ft_free_nul(var), errno);
	node->content = var;
	var->key = ft_strdup(newkey);
	var->value = NULL;
	if (var->key)
		return (errno);
	var->keylen = ft_strlen(var->key);
	if (newval)
	{
		var->value = ft_strdup(newval);
		if (!var->value)
			return (errno);
	}
	var->key_val = ft_strjoin_sep(var->key, var->value, '=');
	if (!var->key_val)
		return (errno);
	return (0);
}

int	print_var_list(const t_list *var_list, const char sep)
{
	t_node	*node;
	char	*var;

	var = NULL;
	node = var_list->first;
	while (node != var_list->last)
	{
		var = ft_strjoin_sep(((t_var *)node->content)->key, \
				((t_var *)node->content)->value, '=');
		if (!var)
			return (errno);
		if (printf("%s%c", var, sep) == -1)
			return (ft_free_nul(var), errno);
		ft_free_nul(var);
		node = node->next;
	}
	var = ft_strjoin_sep(((t_var *)node->content)->key, \
			((t_var *)node->content)->value, '=');
	if (!var)
		return (errno);
	if (printf("%s\n", var) == -1)
		return (ft_free_nul(var), errno);
	ft_free_nul(var);
	return (0);
}
