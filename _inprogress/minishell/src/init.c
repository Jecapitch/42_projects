/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:33:54 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/12 02:09:52 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	set_zero(t_shdata *shdata)
{
	shdata->ptr_cwd = NULL;
	shdata->ptr_cwd = NULL;
	shdata->ptr_history_file = NULL;
	shdata->ptr_prompt = NULL;
	shdata->variables = NULL;
	shdata->history = NULL;
}

int	init_shdata(t_shdata *shdata)
{
	set_zero(shdata);
	shdata->variables = ft_init_list();
	if (!shdata->variables)
		return (-1);
	if (load_environ(shdata) == -1)
		return (-1);
	if (load_history(shdata) == -1)
		return (-1);
	if (prompt_value(shdata))
		return (-1);
	return (0);
}

int	prompt_value(t_shdata *shdata)
{
	char	*prompt_start;

	prompt_start = NULL;
	shdata->ptr_prompt = ft_free_safe(shdata->ptr_prompt);
	prompt_start = ft_strrchr(shdata->ptr_cwd, '/');
	shdata->ptr_prompt = ft_strjoin(prompt_start, PROMPT_SYMBOL);
	if (!shdata->ptr_prompt)
		return (-1);
	return (0);
}
