/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 07:24:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 05:33:16 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	cd(const char *path, t_shdata *shdata)
{
	char	expanded_path[MAXPATHLEN + 1];
	size_t	len;

	ft_memset(expanded_path, 0, MAXPATHLEN + 1);
	len = 0;
	getcwd(shdata->oldpwd, MAXPATHLEN);
	if (*path == '~')
	{
		len = ft_strlcpy(expanded_path, shdata->home_path, MAXPATHLEN + 1);
		path++;
	}
	ft_strlcpy(expanded_path + len, path, MAXPATHLEN + 1 - len);
	if (chdir(expanded_path) == -1 \
		|| !getcwd(shdata->cwd, MAXPATHLEN))
		return (perror("cd"), -1);
	prompt_value(shdata);
	return (0);
}

// vérifier que l'environnement est bien modifié
// quand ce sera dans son propre terminal
int	pwd(void)
{
	if (printf("%s\n", getenv("PWD")) == -1)
		return (errno);
	return (0);
}
