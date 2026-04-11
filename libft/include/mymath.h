/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:25:41 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 07:09:04 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYMATH_H
# define MYMATH_H
# define PI		3.141592653589793
# define PHI	1.618033988749894
# define LN10	2.302585092994046
# define E		2.718281828459045
# include "libft.h"

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

#endif
