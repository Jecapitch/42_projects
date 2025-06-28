/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:21:08 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 22:46:39 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	echo(const char **args)
{
	int		nl;
	size_t	i;

	nl = '\n';
	if (ft_strncmp(*args, "-n", 3))
		nl = '\0';
	i = 0;
	args++;
	if (ft_strncmp(*args, "-n", 3) == 0)
	{
		nl = '\0';
		args++;
	}
	while (args[i])
	{
		if (printf("%s", *args) == -1)
			return (-1);
		args++;
	}
	if (printf("%c", nl) == -1)
		return (-1);
	return (0);
}
