/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 07:24:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/29 00:36:44 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bi_cd(t_shdata *shdata, char **args)
{
	char	path[PATH_MAX + 1];

	ft_bzero(path, PATH_MAX + 1);
	if (args[1] && args[2])
		return (-1);
	getcwd(shdata->ptr_oldpwd, PATH_MAX);
	if (ft_strlcpy(path, args[1], PATH_MAX + 1) == 0)
		ft_strlcpy(path, shdata->ptr_home_path, PATH_MAX + 1);
	if (chdir(path) \
		|| !getcwd(shdata->ptr_cwd, PATH_MAX) \
		|| export_var(shdata, shdata->environ, "PWD", path) \
		|| export_var(shdata, shdata->environ, "OLDPWD", shdata->ptr_oldpwd))
		return (-1);
	prompt_value(shdata);
	return (0);
}
