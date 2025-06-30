/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:57:22 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/30 15:31:04 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	end_program(t_shdata *shdata)
{
	save_history(shdata);
	save_oldpwd(shdata);
	ft_listclear(&shdata->history, ft_free_nul);
	ft_listclear(&shdata->environ, clear_var);
	ft_listclear(&shdata->variables, clear_var);
	set_zero(shdata);
	clear_history();
	return (-1);
}
