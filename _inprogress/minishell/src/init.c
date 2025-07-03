/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:33:54 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 23:38:38 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_zero(t_shdata *shdata)
{
	ft_free_nul(shdata->ptr_cwd);
	ft_free_nul(shdata->ptr_oldpwd);
	ft_free_nul(shdata->ptr_history_file);
	ft_free_nul(shdata->ptr_prompt);
	ft_free_nul(shdata->environ);
	ft_free_nul(shdata->variables);
	ft_free_nul(shdata->history);
}

int	init_shdata(t_shdata *shdata)
{
	set_zero(shdata);
	shdata->variables = init_var_list();
	load_environ(shdata);
	load_history(shdata);
	shdata->ptr_oldpwd = shdata->ptr_cwd;
	if (!shdata->environ || !shdata->variables \
		|| shdata->fd_history == -1 || shdata->fd_oldpwd == -1)
		return (-1);
	prompt_value(shdata);
	return (0);
}

int	prompt_value(t_shdata *shdata)
{
	char	*prompt_start;

	prompt_start = NULL;
	ft_free_nul(shdata->ptr_prompt);
	prompt_start = ft_strrchr(shdata->ptr_cwd, '/');
	shdata->ptr_prompt = ft_strjoin(prompt_start, PROMPT_SYMBOL);
	if (!shdata->ptr_prompt)
		return (-1);
	return (0);
}
