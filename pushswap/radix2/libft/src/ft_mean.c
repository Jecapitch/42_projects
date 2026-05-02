/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:55:37 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 07:10:33 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mymath.h"

double	ft_mean_tab(int *tab, size_t size)
{
	return (ft_sum_tab(tab, size) / size);
}

double	ft_mean_list(t_list *list)
{
	double	sum;

	if (!list || !list->size)
		return (0);
	sum = ft_sum_list(list);
	return (sum / list->size);
}

double	ft_mean_deque(t_deque *list)
{
	double	sum;

	if (!list || !list->size)
		return (0);
	sum = ft_sum_deque(list);
	return (sum / list->size);
}

double	ft_mean_list_circ(t_list_circ *list)
{
	double	sum;

	if (!list || !list->size)
		return (0);
	sum = ft_sum_list_circ(list);
	return (sum / list->size);
}
