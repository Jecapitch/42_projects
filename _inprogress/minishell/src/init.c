/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:33:54 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/28 00:59:50 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_zero(t_shdata *shdata)
{
	ft_bzero(shdata->cwd, MAXPATHLEN + 1);
	ft_bzero(shdata->oldpwd, MAXPATHLEN + 1);
	ft_bzero(shdata->history_file, MAXPATHLEN + 1);
	ft_bzero(shdata->oldpwd_file, MAXPATHLEN + 1);
	ft_bzero(shdata->prompt, MAXPATHLEN + 1);
	shdata->sh_environ = NULL;
	shdata->sh_variables = NULL;
	shdata->sh_history = NULL;
}

int	init_shdata(t_shdata *shdata)
{
	set_zero(shdata);
	if (!getcwd(shdata->cwd, MAXPATHLEN + 1))
		return (-1);
	load_environ(shdata);
	load_history(shdata);
	load_oldpwd(shdata);
	shdata->sh_variables = init_var_list();
	if (!shdata->sh_environ || !shdata->sh_variables \
		|| shdata->fd_history == -1 || shdata->fd_oldpwd == -1)
		return (-1);
	prompt_value(shdata);
	return (0);
}

int	load_environ(t_shdata *shdata)
{
	char	**key_val;

	key_val = NULL;
	shdata->sh_environ = init_var_list();
	if (!shdata->sh_environ)
		return (-1);
	while (*environ)
	{
		key_val = ft_split(*environ, '=');
		if (!key_val || export_var(shdata, shdata->sh_environ, \
			key_val[0], key_val[1]))
			return (ft_free_all(key_val), -1);
		ft_free_all(key_val);
		environ++;
	}
	return (0);
}

char	*prompt_value(t_shdata *shdata)
{
	size_t	cwd_len;
	size_t	len;

	len = MAXPATHLEN + 1 + PROMPT_SYM_LEN;
	cwd_len = ft_strlcpy(shdata->prompt, ft_strrchr(shdata->cwd, '/'), len);
	ft_strlcpy(shdata->prompt + cwd_len, PROMPT_SYMBOL, len - cwd_len);
	return (shdata->prompt);
}
