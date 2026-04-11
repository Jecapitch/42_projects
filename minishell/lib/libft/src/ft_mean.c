/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:55:37 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/29 22:45:29 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mymath.h"

double	ft_mean_arr(int *arr)
{
	double	sum;
	size_t	size;

	sum = ft_sum_arr(arr);
	size = sizeof(*arr) / sizeof(int);
	return (sum / size);
}

double	ft_mean_list(t_list *list)
{
	double	sum;

	if (!list || !list->size)
		return (0);
	sum = ft_sum_list(list);
	return (sum / list->size);
}

double	ft_mean_list2(t_list_2 *list)
{
	double	sum;

	if (!list || !list->size)
		return (0);
	sum = ft_sum_list2(list);
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
