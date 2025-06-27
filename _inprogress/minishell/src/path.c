/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:53:16 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/25 23:05:10 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	expand_path(char dest[MAXPATHLEN + 1], \
				char *path_to_expand, char *path_end)
{
	size_t	len;
	size_t	home_len;
	char	*dir;

	len = MAXPATHLEN + 1;
	dir = getenv(path_to_expand);
	if (!dir)
		return (perror("getenv"), -1);
	home_len = ft_strlcpy(dest, dir, len);
	dest[home_len++] = '/';
	ft_strlcpy(dest + home_len, path_end, len - home_len);
	return (0);
}
