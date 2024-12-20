/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:43:46 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/20 15:33:46 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# define ERROR	"Error\n"

void		init_game(t_list_circ *a, t_list_circ *b, t_list *op, char **argv);
t_node_circ	*value_node(char *data);
void		init_stack(t_list_circ *a, t_list_circ *b, t_list *op, char **argv);
int			isduplicate(t_node_circ *node);
void		raise_error(t_list_circ *a, t_list_circ *b, t_list *op);

#endif
