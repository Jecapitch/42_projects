/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_deq.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 13:27:13 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_DEQ_H
# define LIST_DEQ_H
# include "libft.h"

typedef struct s_double_end_node	t_denode;
typedef struct s_double_end_list	t_deque;

struct s_double_end_node
{
	void		*content;
	t_denode	*prev;
	t_denode	*next;
};

struct s_double_end_list
{
	t_denode	*head;
	t_denode	*tail;
	size_t		size;
};

/* MAIN FUNCTIONS */
t_deque		*ft_init_deq(void);
t_denode	*ft_newnode_deq(void *content);
void		ft_push_deq(t_deque *list, t_denode *newnode);
void		ft_append_deq(t_deque *list, t_denode *newnode);
void		ft_insert_deq(t_deque *list, \
							t_denode *prev_node, t_denode *newnode);
t_denode	*ft_dequeue_deq(t_deque *list);
t_denode	*ft_pop_deq(t_deque *list);
t_denode	*ft_extract_deq(t_deque *list, t_denode *node);

/* UTILS */
void		ft_deq_int_display(t_deque *list, char *sep);
size_t		ft_listsize_deq(t_deque *list);
t_denode	*ft_list_tail_deq(t_deque *list);
void		ft_rot_deq(t_deque *list);
void		ft_rrot_deq(t_deque *list);

/* DELETION */
void		ft_listdelone_deq(t_denode *node, void (*del)(void *));
void		ft_listclear_deq(t_deque **list, void (*del)(void *));

#endif /* LIST_DOUBLE_H */
