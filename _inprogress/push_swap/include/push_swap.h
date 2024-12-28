/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:43:46 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/28 01:55:35 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define ERROR	"Error\n"

// START & END
int		init_game(t_list_circ **a, t_list_circ **b, t_list **op, char **argv);
void	clear_game(t_list_circ **a, t_list_circ **b, t_list **op);

// ERRORS
int		isduplicate(t_node_circ *node);
void	raise_error(t_list_circ *a, t_list_circ *b, t_list *op);

// OPERATIONS
int		right_bit(void *value);
void	right_shift(void *value);
void	push(t_list_circ *a, t_list_circ *b, t_list *op, char todo);
void	rotate(t_list_circ *a, t_list_circ *b, t_list *op);
void	push_swap(t_list_circ *a, t_list_circ *b, t_list *op);
void	add_op(t_list *op, char *operation);

// DISPLAY
void	display_game(t_list_circ *a, t_list_circ *b, t_list *op);

#endif
