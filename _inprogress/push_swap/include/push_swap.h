/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:43:46 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/25 18:04:56 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define ERROR	"Error\n"

// START & END
void	init_game(t_list_circ **a, t_list_circ **b, t_list **op, char **argv);
void	clear_game(t_list_circ **a, t_list_circ **b, t_list **op);

// ERRORS
int		isduplicate(t_node_circ *node);
void	raise_error(t_list_circ *a, t_list_circ *b, t_list *op);

// OPERATIONS
void	swap(t_list_circ *a, t_list_circ *b, t_list *op, int cmp);
void	push(t_list_circ *a, t_list_circ *b, t_list *op, char todo);
void	rotate(t_list_circ *a, t_list_circ *b, t_list *op, int cmp);
void	rrotate(t_list_circ *a, t_list_circ *b, t_list *op, int cmp);
void	push_swap(t_list_circ *a, t_list_circ *b, t_list *op);
void	add_op(t_list *op, char *operation);

// COMPARISONS
int		cmp_first(t_list_circ *stack);
int		cmp_last(t_list_circ *stack);
int		cmp_first_combine(t_list_circ *a, t_list_circ *b);
int		cmp_last_combine(t_list_circ *a, t_list_circ *b);
int		cmp_first_2_last(t_list_circ *stack);
int		cmp_last_2_first(t_list_circ *stack, char cmp_sign);
int		cmp_2_last_combine(t_list_circ *a, t_list_circ *b);

#endif
