/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:57:22 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/28 00:54:16 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	end_program(t_shdata *shdata)
{
	save_history(shdata);
	save_oldpwd(shdata);
	ft_listclear(&shdata->sh_history, ft_free_nul);
	ft_listclear(&shdata->sh_environ, free_var);
	ft_listclear(&shdata->sh_variables, free_var);
	set_zero(shdata);
	clear_history();
	return (errno);
}
