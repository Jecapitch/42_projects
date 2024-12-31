/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:43:46 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/30 19:03:03 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "mymath.h"
# define ERROR	"Error\n"

typedef struct s_minmax	t_minmax;

struct s_minmax
{
	int	min;
	int	max;
};

// START & END
int			init_game(t_list_circ **a, t_list_circ **b, t_list **op, char **argv);
t_node_circ	*value_node(char *data);
void		normalize(t_list_circ *list);
void		clear_game(t_list_circ **a, t_list_circ **b, t_list **op);

// ERRORS
int			isduplicate(t_node_circ *node);
void		raise_error(t_list_circ *a, t_list_circ *b, t_list *op);

// MATH
int			power3(int pow);
int			mod3(t_node_circ *node);
int			div3(t_node_circ *node);

// OPERATIONS
void		push(t_list_circ *a, t_list_circ *b, t_list *op, char todo);
void		rotate(t_list_circ *a, t_list_circ *b, t_list *op);
void		push_swap(t_list_circ *a, t_list_circ *b, t_list *op);
void		add_op(t_list *op, char *operation);

// UTILS
int			getval_int(t_node_circ *node);
double		getval_double(t_node_circ *node);
void		display_game(t_list_circ *a, t_list_circ *b, t_list *op);

#endif
