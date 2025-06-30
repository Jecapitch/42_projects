/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_double.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/28 23:56:36 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_DOUBLE_H
# define LIST_DOUBLE_H
# include "libft.h"

typedef struct s_node_double	t_node_2;
typedef struct s_list_2			t_list_2;

struct s_node_double
{
	void		*content;
	t_node_2	*prev;
	t_node_2	*next;
};

struct s_list_2
{
	t_node_2	*first;
	t_node_2	*last;
	size_t		size;
};

// MAIN FUNCTIONS
t_list_2	*ft_init_list_2(void);
t_node_2	*ft_newnode_2(void *content);
void		ft_push_2(t_list_2 *list, t_node_2 *newnode);
void		ft_append_2(t_list_2 *list, t_node_2 *newnode);
void		ft_insert_2(t_list_2 *list, t_node_2 *prev_node, t_node_2 *newnode);
t_node_2	*ft_dequeue_2(t_list_2 *list);
t_node_2	*ft_pop_2(t_list_2 *list);

// UTILS
void		ft_list2_int_display(t_list_2 *list, char *sep);
size_t		ft_listsize_2(t_list_2 *list);
t_node_2	*ft_listlast_2(t_list_2 *list);
void		ft_rotlist_2(t_list_2 *list);
void		ft_rrotlist_2(t_list_2 *list);

//DELETION
void		ft_listdelone_2(t_node_2 *node, void (*del)(void *));
void		ft_listclear_2(t_list_2 **list, void (*del)(void *));

#endif
