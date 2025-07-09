/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:31:10 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/09 14:05:54 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_var	*split_var(char *variable)
{
	t_var	*var;
	char	*keyval[2];
	size_t	i;

	var = NULL;
	ft_bzero(keyval, 3);
	i = 0;
	if (!variable || !(*variable))
		return (NULL);
	var = ft_calloc(1, sizeof(t_var));
	if (!var)
	{
		perror("ft_calloc");
		return (NULL);
	}
	keyval[0] = *variable;
	while (variable[i] && variable[i] != '=')
		i++;
	if (variable[i] == '=')
	{
		var->equal_sign[0] = '=';
		variable[i] = '\0';
		quote = !quote;
		keyval[1] = &variable[i + 1]
	}
}

int	export_var(t_shdata *shdata, t_list *var_list, \
				char *key, char *value)
{
	t_node	*node;
	t_var	*var;

	node = NULL;
	var = NULL;
	if (!variable || !(*variable) || !var_list)
		return (-1);
	node = search_var(*key, shdata->variables);
	reset_node(node, key, value);
	if (add_var_list(shdata->variables, node, key, value) == -1)
		return (-1);
	node = search_var(key, shdata->environ);
	if (node || var_list == shdata->environ || ft_strncmp(*key, "HOME", 5))
	{
		if (add_var_list(shdata->environ, node, key, value) == -1)
			return (-1);
	}
	update_shdata_env(shdata);
	return (0);
}

int	add_var_list(t_list *var_list, t_node *node, char *key, char *value)
{
	t_var	*var;
	size_t	keylen;

	var = NULL;
	keylen = ft_strlen(*key);
	node = reset_node(var_list, node);
	if (!node)
		return (-1);
	var = (t_var *)node->content;
	var->key = *key;
	var->value = *value;
	if (key[len - 1] == '=')
	{
		var->equal_sign[0] = '=';
		(*key)[len - 1] = '\0';
		len--;
	}
	var->keylen = len;
	return (0);
}

t_node	*reset_node(t_list *var_list, t_node *node)
{
	t_var	*var;

	var = NULL;
	if (!var_list)
		return (NULL);
	if (!node)
	{
		node = ft_newnode(NULL);
		if (!node)
			return (NULL);
		ft_bzero(var, sizeof(t_var));
	}
	var = (t_var *)node->content;
	if (!var)
		var = ft_calloc(1, sizeof(t_var));
	if (!var)
		return (NULL);
	clear_var(var);
	return (node);
}

void	clear_variable(t_var *var)
{
	ft_free_nul(var->key);
	ft_free_nul(var->value);
	ft_free_nul(var->keyval);
	ft_bzero(var, sizeof(t_var));
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
