/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/14 22:57:37 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H
# include "libft.h"

typedef struct s_list			t_node;
typedef struct s_node_double	t_node_2;
typedef struct s_list			t_list;

struct s_node
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
void		ft_init_lst(void *list);
int			ft_lstsize(t_node *node);
t_node		*ft_lstlast(t_node *node);

// SIMPLE CHAINED NODES – ADD & DELETE
t_node		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list *lst, t_node *newnode);
void		ft_lstadd_back(t_list *lst, t_node *newnode);
void		ft_lstdelone(t_node *node, void (*del)(void *));

// DOUBLE CHAINED NODES – ADD & DELETE
t_node_2	*ft_lstnew_2(void *content);
void		ft_push_2(t_list *lst, t_node_2 *newnode);
void		ft_append_2(t_list *lst, t_node_2 *newnode);
void		ft_pop_2(t_node_2 *node, void (*del)(void *));

//SIMPLE CHAINED ITERATE
void		ft_lstclear(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
