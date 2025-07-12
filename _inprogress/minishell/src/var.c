/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/12 01:44:17 by jpiscice         ###   ########.fr       */
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

t_node	*search_var(t_list *var_list, const char *var_key)
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
		return (NULL);
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

int	print_var_list(const t_list *var_list, int sep, \
					int isenv, int include_blank)
{
	t_node	*node;
	t_var	*var;

	node = NULL;
	var = NULL;
	if (!var_list)
		return (-1);
	node = var_list->first;
	while (node)
	{
		var = (t_var *)node->content;
		if (!(isenv && !var->isenv))
		{
			if (var->value && var->vallen)
				printf("%s='%s'%c", var->key, var->value, sep);
			else if (var->value && include_blank)
				printf("%s=''%c", var->key, sep);
			else if (include_blank)
				printf("%s%c", var->key, sep);
		}
		node = node->next;
	}
	printf("\n");
	return (0);
}
