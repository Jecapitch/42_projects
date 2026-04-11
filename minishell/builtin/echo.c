/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emarlier <emarlier@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 23:21:08 by jpiscice          #+#    #+#             */
/*   Updated: 2025/08/20 23:17:34 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bi_echo(char **argv)
{
	int		nl;
	size_t	i;

	nl = '\n';
	i = 1;
	if (ft_strncmp(argv[1], "-n", 3) == 0)
	{
		nl = '\0';
		i++;
	}
	while (argv[i])
	{
		if (printf("%s", argv[i]) == -1)
			return (EX_FAILURE);
		i++;
		if (argv[i] && printf(" ") == -1)
			return (EX_FAILURE);
	}
	if (nl && printf("%c", nl) == -1)
		return (EX_FAILURE);
	return (EX_SUCCESS);
}
