/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:33:54 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/20 20:33:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	load_environ(t_shdata *shdata)
{
	size_t	i;

	i = 0;
	if (!environ)
		return (0);
	while (environ[i])
	{
		if (set_var(shdata, environ[i], ISENV) == -1)
			return (-1);
		i++;
	}
	update_environ(shdata);
	return (0);
}

void	update_shdata_env(t_shdata *shdata, char *key, char *val)
{
	if (ft_strncmp(key, "HOME", ft_strlen("HOME") + 1) == 0)
		shdata->ptr_home_path = val;
	else if (ft_strncmp(key, "PWD", ft_strlen("PWD") + 1) == 0)
		shdata->ptr_cwd = val;
	else if (ft_strncmp(key, "OLDPWD", ft_strlen("OLDPWD") + 1) == 0)
		shdata->ptr_oldpwd = val;
	else if (ft_strncmp(key, "HISTFILE", ft_strlen("HISTFILE") + 1) == 0)
		shdata->ptr_history_file = val;
	else if (ft_strncmp(key, "HISTSIZE", ft_strlen("HISTSIZE") + 1) == 0)
		shdata->history_size = ft_strtol(val);
}

int	update_environ(t_shdata *shdata)
{
	ft_free_str_arr(shdata->sh_environ);
	shdata->sh_environ = environ_arr(shdata->variables);
	environ = shdata->sh_environ;
	if (!environ)
		return (-1);
	return (0);
}

char	**environ_arr(t_list_2 *var_list)
{
	char		**env_arr;
	t_node_2	*node;
	t_var		*var;
	size_t		i;

	node = NULL;
	var = NULL;
	env_arr = ft_calloc(var_list->size + 1, sizeof(char *));
	if (!env_arr)
		return (NULL);
	node = var_list->first;
	i = 0;
	while (node)
	{
		var = (t_var *)node->content;
		if (var->isenv)
		{
			env_arr[i] = ft_strdup(var->keyval);
			if (!env_arr[i])
				return (ft_free_str_arr(env_arr), env_arr = NULL, NULL);
			i++;
		}
		node = node->next;
	}
	return (env_arr);
}

int	set_pwd(t_shdata *shdata)
{
	char	*shell_var;
	char	*cwd;
	int		e;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (-1);
	shell_var = ft_strjoin_sep("PWD", cwd, "=");
	cwd = ft_free_safe(cwd);
	if (!shell_var)
		return (-1);
	e = set_var(shdata, shell_var, ISENV);
	shell_var = ft_free_safe(shell_var);
	if (e)
		return (-1);
	update_environ(shdata);
	return (0);
}
