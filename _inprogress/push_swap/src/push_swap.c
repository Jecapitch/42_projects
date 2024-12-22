/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/22 21:45:09 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		add_op(t_list *op, char *operation);

void	add_op(t_list *op, char *operation)

{
	t_node	*node;
	char	*content;

	content = ft_calloc(4, sizeof(char));
	ft_strlcpy(content, operation, 4);
	node = ft_newnode(content);
	ft_append(op, node);
}
