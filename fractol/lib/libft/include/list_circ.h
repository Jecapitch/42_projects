/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_circ.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2025/01/21 20:40:04 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_CIRC_H
# define LIST_CIRC_H
# include "libft.h"

typedef struct s_node_circ	t_node_circ;
typedef struct s_list_circ	t_list_circ;

struct s_node_circ
{
	void		*content;
	t_node_circ	*prev;
	t_node_circ	*next;
};

struct s_list_circ
{
	t_node_circ	*first;
	t_node_circ	*last;
	size_t		size;
};

// MAIN FUNCTIONS
t_list_circ	*ft_init_list_circ(void);
t_node_circ	*ft_newnode_circ(void *content);
void		ft_push_circ(t_list_circ *list, t_node_circ *newnode);
void		ft_append_circ(t_list_circ *list, t_node_circ *newnode);
void		ft_insert_circ(t_list_circ *list, t_node_circ *prev_node, \
				t_node_circ *newnode);
t_node_circ	*ft_dequeue_circ(t_list_circ *list);
t_node_circ	*ft_pop_circ(t_list_circ *list);

// UTILS
void		ft_list_circ_int_display(t_list_circ *list, char *sep);
size_t		ft_listsize_circ(t_list_circ *list);
t_node_circ	*ft_listlast_circ(t_list_circ *list);
void		ft_listiter_circ(t_list_circ *list, void (*f)(void *));
void		ft_rotlist_circ(t_list_circ *list);
void		ft_rrotlist_circ(t_list_circ *list);

//DELETION
void		ft_listdelone_circ(t_node_circ *node, void (*del)(void *));
void		ft_listclear_circ(t_list_circ **list, void (*del)(void *));

#endif
