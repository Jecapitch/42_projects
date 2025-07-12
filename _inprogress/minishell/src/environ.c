/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:33:54 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/12 02:07:44 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	load_environ(t_shdata *shdata)
{
	if (!environ)
		return (0);
	while (*environ)
	{
		if (set_var(shdata, *environ, 1) == -1)
			return (-1);
		environ++;
	}
	return (0);
}

void	update_shdata_env(t_shdata *shdata, t_node *node)
{
	char	*key;
	char	*val;

	key = get_var_key(node);
	val = get_var_val(node);
	if (ft_strncmp(key, "HOME", 5) == 0)
		shdata->ptr_home_path = val;
	else if (ft_strncmp(key, "PWD", 4) == 0)
		shdata->ptr_cwd = val;
	else if (ft_strncmp(key, "OLDPWD", 7) == 0)
		shdata->ptr_oldpwd = val;
	else if (ft_strncmp(key, "HISTFILE", 9) == 0)
		shdata->ptr_history_file = val;
	else if (ft_strncmp(key, "HISTSIZE", 9) == 0)
		shdata->history_size = ft_strtol(val);
}

char	**ve_environ(t_list *var_list)
{
	char	**env_table;
	t_node	*node;
	t_var	*var;
	size_t	i;

	env_table = NULL;
	node = NULL;
	var = NULL;
	env_table = ft_calloc(var_list->size + 1, sizeof(char *));
	if (!env_table)
		return (NULL);
	node = var_list->first;
	i = 0;
	while (node)
	{
		var = (t_var *)node->content;
		env_table[i] = ft_strdup(var->keyval);
		if (!env_table[i])
			return (ft_free_str_arr(env_table), \
					env_table = NULL, \
					NULL);
		node = node->next;
		i++;
	}
	return (env_table);
}
