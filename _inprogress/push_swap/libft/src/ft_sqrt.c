/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiscice <jpiscice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:43:15 by jpiscice          #+#    #+#             */
/*   Updated: 2024/12/29 20:43:41 by jpiscice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
