/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:33:54 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 13:25:46 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_shdata(t_shdata *shdata, t_line *line)
{
	ft_bzero(line, sizeof(t_line));
	ft_bzero(shdata, sizeof(t_shdata));
	shdata->builtin = ft_split(BUILTIN, ' ');
	if (!shdata->builtin \
			|| dup_std(shdata) == -1 \
			|| init_variables(shdata) == -1 \
			|| load_environ(shdata) == -1 \
			|| set_pwd(shdata) == -1 \
			|| load_history(shdata) == -1 \
			|| prompt_value(shdata) == -1)
		return (-1);
	return (0);
}

int	init_variables(t_shdata *shdata)
{
	char	*pid_k;
	char	*pid_v;

	pid_v = NULL;
	shdata->variables = ft_init_list_2();
	pid_k = ft_strdup("$=");
	if (!pid_k || !shdata->variables)
		return (pid_k = ft_free_safe(pid_k), \
				-1);
	pid_v = ft_itoa(ft_getpid());
	if (!pid_v)
		return (pid_k = ft_free_safe(pid_k), \
				-1);
	ft_strappend(&pid_k, pid_v);
	pid_v = ft_free_safe(pid_v);
	if (!pid_k || set_var(shdata, "?=0", ISENV) == -1 \
			|| set_var(shdata, pid_k, ISENV) == -1)
		return (pid_k = ft_free_safe(pid_k), \
				-1);
	pid_k = ft_free_safe(pid_k);
	return (0);
}

int	prompt_value(t_shdata *shdata)
{
	char	*prompt_start;

	prompt_start = NULL;
	shdata->ptr_prompt = ft_free_safe(shdata->ptr_prompt);
	prompt_start = ft_strrchr(getenv("PWD"), '/');
	shdata->ptr_prompt = ft_strjoin(prompt_start, PROMPT_SYMBOL);
	if (!shdata->ptr_prompt)
		return (-1);
	return (0);
}
