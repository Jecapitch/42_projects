/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:21:08 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/28 19:34:37 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	bi_echo(const char **args)
{
	int		nl;
	size_t	i;

	nl = '\n';
	i = 1;
	if (ft_strncmp(args[1], "-n", 3) == 0)
	{
		nl = '\0';
		i++;
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
