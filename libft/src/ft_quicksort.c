/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 00:01:14 by jpiscice          #+#    #+#             */
/*   Updated: 2026/02/07 00:02:07 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

static int	partition(int *arr, int start, int end)
{
	int	val;

	val = arr[start + (end - start) / 2];
	while (1)
	{
		while (arr[start] < val)
			start++;
		while (arr[end] > val)
			end--;
		if (start >= end)
			return (end);
		swap(arr, start, end);
		start++;
		end--;
	}
}

void	quicksort(int *arr, int start, int end)
{
	int	part;

	part = 0;
	if (start < end)
	{
		part = partition(arr, start, end);
		quicksort(arr, start, part);
		quicksort(arr, part + 1, end);
	}
}
