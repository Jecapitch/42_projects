/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:10:32 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/14 21:43:12 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H
# include "libft.h"

typedef struct s_list			t_list;
typedef struct s_list_double	t_list_2;
typedef struct s_list_start		t_list_start;

struct s_list
{
	void	*content;
	t_list	*next;
};

struct s_list_double
{
	void		*content;
	t_list_2	*prev;
	t_list_2	*next;
};

struct s_list_start
{
	void	*first;
	void	*last;
	size_t	size;
};

// LIST UTILS
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);

// LIST NODES – ADD & DELETE
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *newnode);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
void		ft_lstdelone(t_list *lst, void (*del)(void *));

//LIST ITERATE
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
