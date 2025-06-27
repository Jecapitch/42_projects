/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 08:53:16 by jpiscice          #+#    #+#             */
/*   Updated: 2025/06/27 13:06:25 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	expand_path(t_list *var_list, char dest[MAXPATHLEN + 1], \
				char *path_to_expand, char *path_end)
{
	size_t	len;
	t_var	*var;
	t_node	*node;
	char	full_end[MAXPATHLEN + 1];

	len = MAXPATHLEN + 1;
	var = NULL;
	node = NULL;
	ft_bzero(full_end, len);
	full_end[0] = '/';
	ft_strlcat(full_end, path_end, len);
	node = search_var(path_to_expand, var_list);
	if (!node)
		return (-1);
	var = (t_var *)node->content;
	ft_strlcat(dest, var->value, len);
	ft_strlcat(dest, full_end, len);
	if (ft_strlen(dest) < ft_strlen(path_to_expand) + ft_strlen(path_end) + 1)
		return (-1);
	return (0);
}
