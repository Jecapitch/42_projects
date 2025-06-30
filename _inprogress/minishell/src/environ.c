/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:33:54 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 16:00:45 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	load_environ(t_shdata *shdata)
{
	char	**keyval;

	keyval = NULL;
	shdata->environ = init_var_list();
	if (!shdata->environ)
		return (-1);
	if (!environ)
		return (0);
	while (*environ)
	{
		keyval = ft_split(*environ, '=');
		if (!keyval || export_var(shdata, shdata->environ, \
			keyval[0], keyval[1]))
			return (ft_free_all(keyval), -1);
		ft_free_all(keyval);
		environ++;
	}
	update_shdata_env(shdata);
	return (0);
}

void	update_shdata_env(t_shdata *shdata)
{
	t_node	*node;
	char	*key;
	char	*val;

	key = NULL;
	val = NULL;
	node = shdata->variables->first;
	while (node)
	{
		key = get_var_key(node);
		val = get_var_val(node);
		if (ft_strncmp(key, "HOME", 5) == 0)
			shdata->ptr_home_path = val;
		else if (ft_strncmp(key, "PWD", 4) == 0)
			shdata->ptr_cwd = get_var_val(search_var(key, shdata->environ));
		else if (ft_strncmp(key, "OLDPWD", 7) == 0)
			shdata->ptr_oldpwd = get_var_val(search_var(key, shdata->environ));
		else if (ft_strncmp(key, "HISTFILE", 9) == 0)
			shdata->ptr_history_file = val;
		else if (ft_strncmp(key, "HISTSIZE", 9) == 0)
			shdata->history_size = ft_strtol(val);
		node = node->next;
	}
}
