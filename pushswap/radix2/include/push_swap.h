/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:43:46 by jpiscice          #+#    #+#             */
/*   Updated: 2025/02/17 20:23:30 by jpiscice         ###   ########.fr       */
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
	t_list		*op;
	int			min;
	int			max;
	size_t		min_index;
	size_t		max_index;
};

// START & END
_Bool		init_game(t_game **game, char **argv);
void		compute_position(t_game *game, int *c);
void		normalize(t_game *game);
void		clear_game(t_game **game);

// ERRORS
_Bool		isduplicate(t_game *game, t_node_circ *node);
void		raise_error(t_game *game);

// GET NODE VALUE
t_node_circ	*set_node_val(int data);
int			getval(t_node_circ *node);
int			first_val(t_list_circ *stack);
int			second_val(t_list_circ *stack);
int			last_val(t_list_circ *stack);

// RADIX SORT
void		radix_sort(t_game *game);
void		rad_push(t_game *game, t_list_circ *stack);
_Bool		rad_rotate(t_game *game, t_list_circ *stack);

// OPERATIONS - SMALL LIST
_Bool		swap(t_game *game, int aref, int bref);
_Bool		smallpush(t_game *game, t_list_circ *stack, \
				int aref, int bref);
_Bool		smallrotate(t_game *game, int aref, int bref);
_Bool		rrotate(t_game *game, int aref, int bref);

// OPERATIONS - COMMON
void		empty_stack(t_game *game, t_list_circ *stack);
void		add_op(t_game *game, char *operation);

// SORT CHECK
_Bool		issorted(t_game *game);
_Bool		issorted_rot(t_game *game, t_list_circ *stack, int min);
_Bool		isinverted(t_game *game, t_list_circ *stack);
_Bool		isinverted_rot(t_game *game, t_list_circ *stack, int max);

// SORT
void		small_sort(t_game *game);
_Bool		rot_sort(t_game *game, int min, size_t min_index);
_Bool		reverse_rot_sort(t_game *game, int max, size_t max_index);
void		reverse_sort(t_game *game);

// DEBUG PRINT
void		display_game(t_game *game);
void		display_game_base(t_game *game, int base);

#endif
