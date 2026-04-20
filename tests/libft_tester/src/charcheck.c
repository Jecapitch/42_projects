/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/17 14:06:31 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	main(void)
{
	int		err = 0;

	for (int c = -1; c < 256; c++)
	{
		if (!(!FT(c)) != !(!STD(c)))
		{
			err++;
			printf(STRF(FT)"(%c): "ERROR"\n", c);
		}
	}
	return (err != 0);
}
