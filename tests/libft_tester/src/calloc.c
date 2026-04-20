/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/20 16:01:56 by jepiscic         ###   ########.fr       */
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
			if (ft)
				free(ft);
			if (std)
				free(std);
		}
	}
	return (err != 0);
}
