/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:21:08 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 06:20:55 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	echo(char **args)
{
	int	nl;

	nl = '\n';
	args++;
	if (ft_strncmp(*args, "-n", ft_strlen(*args)) == 0)
	{
		nl = '\0';
		args++;
	}
	while (*args)
	{
		if (printf("%s", *args) == -1)
			return (errno);
		args++;
	}
	if (printf("%c", nl) == -1)
		return (errno);
	return (0);
}
