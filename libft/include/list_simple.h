/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_simple.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/15 19:51:34 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H
# include "libft.h"

typedef struct s_node_simple	t_node;
typedef struct s_node_double	t_node_2;
typedef struct s_list			t_list;

struct s_node_simple
{
	void	*content;
	t_node	*next;
};

struct s_node_double
{
	void		*content;
	t_node_2	*prev;
	t_node_2	*next;
};

struct s_list
{
	void	*first;
	void	*last;
	size_t	size;
};

// LIST UTILS
void		ft_init_list(t_list *list);
int			ft_listsize(void *node);
void		*ft_listlast(void *node);

// SIMPLE CHAINED NODES – ADD & DELETE
t_node		*ft_newnode(void *content);
void		ft_push(t_list *lst, t_node *newnode);
void		ft_append(t_list *lst, t_node *newnode);
t_node		*ft_pop(t_list *list);
t_node		*ft_tail(t_list *list);

// DOUBLE CHAINED NODES – ADD & DELETE
t_node_2	*ft_newnode_2(void *content);
void		ft_push_2(t_list *lst, t_node_2 *newnode);
void		ft_append_2(t_list *lst, t_node_2 *newnode);
t_node_2	ft_pop_2(t_list *list);
t_node_2	*ft_tail_2(t_list *list);

//SIMPLE CHAINED ITERATE
void		ft_lstclear(t_list *lst, void (*del)(void *));

#endif
