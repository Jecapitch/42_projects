/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 01:04:11 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*init_var_list(void)
{
	t_list	*var_list;

	var_list = NULL;
	var_list = ft_init_list();
	return (var_list);
}

char	*get_var_key(t_node *node)
{
	t_var	*var;

	var = NULL;
	if (!node)
		return (NULL);
	var = (t_var *)node->content;
	return (var->key);
}

char	*get_var_val(t_node *node)
{
	t_var	*var;

	var = NULL;
	if (!node)
		return (NULL);
	var = (t_var *)node->content;
	return (var->value);
}

t_node	*search_var(const char *var_key, const t_list *var_list)
{
	t_node	*node;
	char	*key;
	size_t	len;
	t_var	*nvar;

	node = NULL;
	key = NULL;
	nvar = NULL;
	len = 0;
	if (!var_key || !var_list)
		return (0);
	node = var_list->first;
	while (node)
	{
		nvar = (t_var *)node->content;
		key = nvar->key;
		len = nvar->keylen + 1;
		if (ft_strncmp(var_key, key, len) == 0)
			break ;
		node = node->next;
	}
	return (node);
}

int	print_var_list(const t_list *var_list, const char sep)
{
	t_node	*node;
	t_var	*var;

	node = NULL;
	var = NULL;
	if (!var_list)
		return (-1);
	node = var_list->first;
	while (node != var_list->last)
	{
		var = (t_var *)node->content;
		if (printf("%s%c", var->keyval, sep) == -1)
			return (-1);
		node = node->next;
	}
	var = (t_var *)node->content;
	if (printf("%s\n", var->keyval) == -1)
		return (-1);
	return (0);
}
