/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mymath.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:25:41 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/29 22:46:39 by jpiscice         ###   ########.fr       */
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
long	ft_sum_arr(int *arr);
long	ft_sum_list(t_list *list);
long	ft_sum_list2(t_list_2 *list);
long	ft_sum_list_circ(t_list_circ *list);
long	ft_power(int n, int pow);
double	ft_sqrt(double n);
double	ft_mean_arr(int *arr);
double	ft_mean_list(t_list *list);
double	ft_mean_list2(t_list_2 *list);
double	ft_mean_list_circ(t_list_circ *list);
double	ft_std_dev_list_circ(t_list_circ *list);

#endif