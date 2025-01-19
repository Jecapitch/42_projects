/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:43:46 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/17 14:26:02 by jpiscice         ###   ########.fr       */
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
};

// START & END
_Bool		init_game(t_game **game, char **argv);
t_node_circ	*value_node(int data);
void		clear_game(t_game **game);

// ERRORS
int			isduplicate(t_node_circ *node);
void		raise_error(t_game *game);

// MATH
int			pow3(int pow);
int			powof3(int n);
int			mod3(t_node_circ *node);
int			div3(t_node_circ *node);

// OPERATIONS
void		swap(t_game *game);
void		push(t_game *game, char operation, int div);
void		rotate(t_game *game, int div);
void		rrotate(t_game *game);
void		add_op(t_game *game, char *operation);

// SORT
void		sortn(t_game *game, size_t size);
void		sort2(t_game *game);
void		sort3(t_game *game);
void		sort4(t_game *game);
void		sort5(t_game *game);
void		push_swap(t_game *game);

// UTILS
int			getval_int(t_node_circ *node);
void		display_game(t_game *game);

#endif
