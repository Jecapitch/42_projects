/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_single.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/19 23:30:37 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_SINGLE_H
# define LIST_SINGLE_H
# include "libft.h"

typedef struct s_node_single	t_node;
typedef struct s_list			t_list;

struct s_node_single
{
	void	*content;
	t_node	*next;
};

struct s_list
{
	t_node	*first;
	t_node	*last;
	size_t	size;
};

// MAIN FUNCTIONS
t_list	*ft_init_list(void);
t_node	*ft_newnode(void *content);
void	ft_push(t_list *list, t_node *newnode);
void	ft_append(t_list *list, t_node *newnode);
t_node	*ft_pop(t_list *list);

// UTILS
size_t	ft_listsize(t_list *list);
t_node	*ft_listlast(t_list *list);
void	ft_rotlist(t_list *list);
void	ft_rrotlist(t_list *list);

//DELETION
void	ft_listdelone(t_node *node, void (*del)(void *));
void	ft_listclear(t_list *list, void (*del)(void *));

#endif
