/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/28 00:51:58 by jpiscice         ###   ########.fr       */
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

void	free_var(void *node_content)
{
	t_var	*var;

	var = (t_var *)node_content;
	ft_free_nul(var->key);
	ft_free_nul(var->value);
	ft_free_nul(var->key_val);
	var->key = NULL;
	var->value = NULL;
	var->key_val = NULL;
	var->keylen = 0;
}

int	print_var_list(const t_list *var_list, const char sep)
{
	t_node	*node;
	t_var	var;

	node = NULL;
	if (!var_list)
		return (-1);
	node = var_list->first;
	while (node != var_list->last)
	{
		var = *(t_var *)node->content;
		if (printf("%s%c", var.key_val, sep) == -1)
			return (-1);
		node = node->next;
	}
	var = *(t_var *)node->content;
	if (printf("%s\n", var.key_val) == -1)
		return (-1);
	return (0);
}
