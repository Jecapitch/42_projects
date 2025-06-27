/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 05:57:22 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/25 23:41:02 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	end_program(t_shdata *shdata)
{
	close(shdata->fd_history);
	clear_history();
	shdata->fd_oldpwd = open_oldpwd(shdata);
	save_oldpwd(shdata->cwd, shdata->fd_oldpwd);
	close(shdata->fd_oldpwd);
	return (errno);
}
