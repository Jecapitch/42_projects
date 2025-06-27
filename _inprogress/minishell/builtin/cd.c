/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 07:24:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 22:40:39 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	cd(const char *path, t_shdata *shdata)
{
	char	expanded_path[MAXPATHLEN + 1];
	size_t	len;

	ft_bzero(expanded_path, MAXPATHLEN + 1);
	len = 0;
	getcwd(shdata->oldpwd, MAXPATHLEN);
	if (*path == '~')
	{
		len = ft_strlcpy(expanded_path, shdata->home_path, MAXPATHLEN + 1);
		path++;
	}
	ft_strlcpy(expanded_path + len, path, MAXPATHLEN + 1 - len);
	if (chdir(expanded_path) \
		|| !getcwd(shdata->cwd, MAXPATHLEN) \
		|| export_var(shdata, shdata->sh_environ, "PWD", expanded_path) \
		|| export_var(shdata, shdata->sh_environ, "OLDPWD", shdata->oldpwd))
		return (errno);
	prompt_value(shdata);
	return (0);
}
