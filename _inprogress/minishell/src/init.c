/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:33:54 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 06:33:10 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_argc(int argc)
{
	if (argc == 1)
		return (0);
	ft_fprintf(STDERR_FILENO, NAME": No argument allowed\n");
	return (1);
}

int	init_shdata(t_shdata *shdata)
{
	char	*oldpwd;

	oldpwd = NULL;
	shdata->sh_environ = NULL;
	shdata->sh_variables = NULL;
	ft_memset(shdata->cwd, 0, MAXPATHLEN + 1);
	ft_memset(shdata->oldpwd, 0, MAXPATHLEN + 1);
	ft_strlcpy(shdata->home_path, getenv("HOME"), MAXPATHLEN);
	getcwd(shdata->cwd, MAXPATHLEN);
	if (!*shdata->cwd)
		return (errno);
	if (load_environ(shdata) || init_var_list(shdata->sh_variables))
		return (errno);
	shdata->fd_history = load_history(shdata);
	shdata->fd_oldpwd = load_oldpwd(shdata);
	if (shdata->fd_history == -1 || shdata->fd_oldpwd == -1)
		return (errno);
	oldpwd = get_next_line(shdata->fd_oldpwd);
	if (oldpwd)
		ft_strlcpy(shdata->oldpwd, oldpwd, MAXPATHLEN + 1);
	ft_free_nul(oldpwd);
	if (close_oldpwd(shdata->fd_oldpwd) == -1)
		return (errno);
	prompt_value(shdata);
	return (0);
}

int	init_var_list(t_list *var_list)
{
	var_list = ft_init_list();
	if (!var_list)
		return (errno);
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
