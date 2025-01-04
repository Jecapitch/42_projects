/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:43:46 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/04 01:43:05 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "mymath.h"
# define ERROR	"Error\n"

typedef struct s_game	t_game;

struct s_game
{
	t_list_circ	*a;
	t_list_circ	*b;
	t_list_circ	*a2;
	t_list_circ	*b2;
	t_list		*op;
};

// START & END
_Bool		init_game(t_game **game, char **argv, \
				int nperlength[], int actual_length[]);
t_node_circ	*value_node(long data);
void		normalize(t_game *game, int nperlength[]);
void		lengths_to_treat(int nperlength[], int actual_lengths[]);
void		clear_game(t_game **game);

// ERRORS
int			isduplicate(t_node_circ *node);
void		raise_error(t_game *game);

// MATH
int			power3(int pow);
int			mod3(t_node_circ *node);
int			div3(t_node_circ *node);

// OPERATIONS
void		push(t_game *game, char operation);
void		rotate(t_game *game, char operation);
void		rrotate(t_game *game, char operation);
void		add_op(t_list *op, char *operation);

// SORT
void		sortn(t_game *game, size_t size);
void		sort2(t_game *game);
void		sort3(t_game *game);
void		sort4(t_game *game);
void		sort5(t_game *game);
void		push_swap(t_game *game, int nperlength[], int actual_lengths[]);

// UTILS
int			getval_int(t_node_circ *node);
long		getval_long(t_node_circ *node);
double		getval_double(t_node_circ *node);
void		display_game(t_list_circ *a, t_list_circ *b, t_list *op);

#endif
