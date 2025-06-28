/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 07:24:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/28 02:41:12 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	cd(const char *path, t_shdata *shdata)
{
	char	resolved_path[MAXPATHLEN + 1];

	ft_bzero(resolved_path, MAXPATHLEN + 1);
	getcwd(shdata->oldpwd, MAXPATHLEN);
	if (!path)
		ft_strlcpy(resolved_path, shdata->home_path, MAXPATHLEN + 1);
	else
		ft_strlcpy(resolved_path, path, MAXPATHLEN + 1);
	if (chdir(resolved_path) \
		|| !getcwd(shdata->cwd, MAXPATHLEN) \
		|| export_var(shdata, shdata->sh_environ, "PWD", resolved_path) \
		|| export_var(shdata, shdata->sh_environ, "OLDPWD", shdata->oldpwd))
		return (-1);
	prompt_value(shdata);
	return (0);
}
