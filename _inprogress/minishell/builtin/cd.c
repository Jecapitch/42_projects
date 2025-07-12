/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 07:24:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/07/12 03:13:48 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bi_cd(t_shdata *shdata, char **args)
{
	char	path[PATH_MAX + 1];

	ft_bzero(path, PATH_MAX + 1);
	if (args[1] && args[2])
		return (false);
	getcwd(shdata->ptr_oldpwd, PATH_MAX);
	if (ft_strlcpy(path, args[1], PATH_MAX + 1) == 0)
		if (ft_strlcpy(path, shdata->ptr_home_path, PATH_MAX + 1))
			ft_strlcpy(path, shdata->ptr_oldpwd, PATH_MAX + 1);
	if (ft_strncmp(args[1], "-", 2) == 0)
		ft_strlcpy(path, shdata->ptr_oldpwd, PATH_MAX + 1);
	if (chdir(path) \
		|| !getcwd(shdata->ptr_cwd, PATH_MAX + 1) \
		|| set_var(shdata, ft_strjoin_sep("PWD", path, "="), \
					1) \
		|| set_var(shdata, ft_strjoin_sep("OLDPWD", shdata->ptr_oldpwd, "="), \
					1))
		return (false);
	prompt_value(shdata);
	return (true);
}
