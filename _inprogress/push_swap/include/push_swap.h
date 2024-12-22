/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:43:46 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/22 16:27:35 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define ERROR	"Error\n"

void	init_game(t_list_circ **a, t_list_circ **b, t_list **op, char **argv);
int		isduplicate(t_node_circ *node);
void	raise_error(t_list_circ *a, t_list_circ *b, t_list *op);
void	add_op(t_list *op, char *operation);
void	push(t_list_circ *a, t_list_circ *b, t_list *op, char todo);
void	swap(t_list_circ *a, t_list_circ *b, t_list *op, char todo);
void	rotate(t_list_circ *a, t_list_circ *b, t_list *op, char todo);
void	rrotate(t_list_circ *a, t_list_circ *b, t_list *op, char todo);

#endif
