/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:15:11 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/17 20:55:48 by jpiscice         ###   ########.fr       */
/*   Updated: 2025/01/04 23:00:12 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	clear_game(t_game **game)
{
	if (!game)
		return ;
	ft_listclear_circ(&(*game)->a, ft_free_nul);
	ft_listclear_circ(&(*game)->b, ft_free_nul);
	ft_listclear(&(*game)->op, ft_free_nul);
	ft_free_nul(*game);
}
