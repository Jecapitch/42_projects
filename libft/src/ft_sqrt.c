/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:43:15 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/10 03:47:28 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt_int(int n)
{
	int	left;
	int	right;
	int	mid;
	int	sqr;

	if (n <= 0)
		return (0);
	left = 0;
	right = n;
	while (left < right)
	{
		mid = (left + right) / 2;
		sqr = mid * mid;
		if (sqr == n)
			return (mid);
		if (sqr < n)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return ((left + right) / 2);
}

double	ft_sqrt(double n)
{
	double	x;
	double	y;
	double	precision;

	if (n <= 0)
		return (0);
	x = n;
	y = 1;
	precision = 0.00001;
	while (x - y > precision)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}
