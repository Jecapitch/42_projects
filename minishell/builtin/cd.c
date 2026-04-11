/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 07:24:51 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/21 00:03:34 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copycat(char *dest, char *key);

static void	copycat(char *dest, char *key)
{
	char	pwd[PATH_MAX + 1];
	size_t	size;

	size = PATH_MAX + 1;
	ft_bzero(pwd, size);
	getcwd(pwd, size);
	ft_strlcpy(dest, key, size);
	ft_strlcat(dest, "=", size);
	ft_strlcat(dest, pwd, size);
}

static void	cd_file_perror(char **argv)
{
	char	s[PATH_MAX + 5];

	ft_bzero(s, PATH_MAX + 5);
	ft_strlcat(s, "cd: ", 5);
	ft_strlcat(s, argv[1], PATH_MAX + 5);
	perror(s);
}

int	bi_cd(t_shdata *shdata, char **argv)
{
	char	pwd[PATH_MAX + 1];
	char	oldpwd[PATH_MAX + 1];

	ft_bzero(pwd, PATH_MAX + 1);
	ft_bzero(oldpwd, PATH_MAX + 1);
	if (!argv[1])
		ft_strlcpy(pwd, getenv("HOME"), PATH_MAX + 1);
	else if (ft_strncmp(argv[1], "-", 2) == 0)
		ft_strlcpy(pwd, getenv("OLDPWD"), PATH_MAX + 1);
	if (argv[1] && ft_strncmp(argv[1], "-", 2) != 0)
		ft_strlcat(pwd, argv[1], PATH_MAX + 1);
	copycat(oldpwd, "OLDPWD");
	if (chdir(pwd))
		return (cd_file_perror(argv), EX_FAILURE);
	if (ft_strncmp(argv[1], "-", 2) == 0)
		if (printf("%s\n", pwd) == -1)
			return (EX_FAILURE);
	copycat(pwd, "PWD");
	set_var(shdata, pwd, ISENV);
	set_var(shdata, oldpwd, ISENV);
	update_environ(shdata);
	prompt_value(shdata);
	return (EX_SUCCESS);
}
