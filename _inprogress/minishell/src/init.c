/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:33:54 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 01:28:40 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_zero(t_shdata *shdata)
{
	shdata->ptr_cwd = NULL;
	shdata->ptr_oldpwd = NULL;
	shdata->ptr_history_file = NULL;
	shdata->ptr_oldpwd_file = NULL;
	shdata->ptr_prompt = NULL;
	shdata->environ = NULL;
	shdata->variables = NULL;
	shdata->history = NULL;
}

int	init_shdata(t_shdata *shdata)
{
	set_zero(shdata);
	shdata->variables = init_var_list();
	load_environ(shdata);
	load_history(shdata);
	load_oldpwd(shdata);
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
