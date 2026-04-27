/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/27 23:18:23 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	main(void)
{
	int	err = 0;

	for (int n = 0; n < 50; n++)
	{
		for (int size = 0; size < 20; size++)
		{
			void	*ft = FT(n, size); 
			void	*std = STD(n, size);
			if (memcmp(ft, std, n * size))
			{
				err++;
				printf(STRF(FT)"('%d', %d): "ERROR"\n", n, size);
			}
			tester_ft_free_safe(ft);
			tester_ft_free_safe(std);
		}
	}
	return (err != 0);
}
