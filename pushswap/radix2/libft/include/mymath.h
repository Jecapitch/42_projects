/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:25:41 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/13 13:24:50 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMATH_H
# define MYMATH_H

# include "libft.h"

# ifndef PI
#  define PI		3.141592653589793
# endif
# ifndef PHI
#  define PHI	1.618033988749894
# endif
# ifndef LN10
#  define LN10	2.302585092994046
# endif
# ifndef E
#  define E		2.718281828459045
# endif

int		ft_absval(int n);
long	ft_sum(int a, int b);
long	ft_sum_tab(int *tab, size_t size);
long	ft_sum_list(t_list *list);
long	ft_sum_deque(t_deque *list);
long	ft_sum_list_circ(t_list_circ *list);
double	ft_power(double n, int pow);
int		ft_power_int(int n, int pow);
int		ft_powerof10(long n);
int		ft_sqrt_int(int nb);
double	ft_sqrt(double n);
double	ft_mean_tab(int *tab, size_t size);
double	ft_mean_list(t_list *list);
double	ft_mean_deque(t_deque *list);
double	ft_mean_list_circ(t_list_circ *list);

#endif /* MYMATH_H */
