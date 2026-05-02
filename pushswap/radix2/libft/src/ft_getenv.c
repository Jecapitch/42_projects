/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:09:40 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/24 18:55:59 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
About extern char **environ, cf. man execve : "the use of a third argument to
the main function is not specified in POSIX.1; according to POSIX.1, the
environment should be accessed via the external variable environ(7)."
*/

char	*ft_getenv(const char *name)
{
	extern char	**environ;
	size_t		size;

	if (!name)
		return (ft_err_nonnull(NULL, -1, __func__), NULL);
	if (!environ)
		return (NULL);
	size = ft_strlen(name);
	while (*environ && ft_strncmp(*environ, name, size + 1))
		environ++;
	if (*environ)
		return (*environ + ft_strlen_delim(*environ, '=') + 1);
	return (NULL);
}
