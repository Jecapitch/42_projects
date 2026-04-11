/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:57:22 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/26 13:25:56 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_exit_var(t_shdata *shdata, int val)
{
	char	*var;
	char	*tmp;

	var = ft_strdup("?=");
	tmp = ft_itoa((unsigned char)val);
	if (!var || !tmp || ft_strappend(&var, tmp) == -1)
		return (var = ft_free_safe(var), tmp = ft_free_safe(tmp), -1);
	tmp = ft_free_safe(tmp);
	set_var(shdata, var, ISENV);
	var = ft_free_safe(var);
	return (0);
}

int	end_program(t_shdata *shdata)
{
	save_history(shdata);
	rl_clear_history();
	free_shdata(shdata);
	return (-1);
}
