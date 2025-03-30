/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 23:09:40 by jpiscice          #+#    #+#             */
/*   Updated: 2025/03/26 19:26:40 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
About extern char **environ, cf. man execve : "the use of a third argument to
the main function is not specified in POSIX.1; according to POSIX.1, the
environment should be accessed via the external variable environ(7)."
*/

char	*ft_getenv(char *name)
{
	extern char	**environ;
	size_t		size;

	if (!name)
		return (NULL);
	size = ft_strlen(name);
	while (*environ && ft_strncmp(*environ, name, size))
		environ++;
	return (ft_strdup(*environ));
}

char	*ft_getenv_val(char *name)
{
	char	*entry;
	char	*val;

	if (!name)
		return (NULL);
	entry = ft_getenv(name);
	if (!entry)
		return (NULL);
	val = ft_strdup(entry + ft_countwhile(name, '=') + 1);
	free(entry);
	return (val);
}

char	*ft_getenv_key(char *name)
{
	char	*entry;
	char	*val;
	size_t	size;

	if (!name)
		return (NULL);
	entry = ft_getenv(name);
	if (!entry)
		return (NULL);
	size = ft_countwhile(name, '=');
	val = ft_calloc(size + 1, sizeof(char));
	if (!val)
		return (free(entry), NULL);
	ft_strlcpy(val, name, size);
	free(entry);
	return (val);
}
