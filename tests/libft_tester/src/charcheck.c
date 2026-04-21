/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/21 21:02:35 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	main(void)
{
	int		err = 0;

	for (int c = -128; c < 127; c++)
	{
		if ((strstr(STRF(FT), "ft_is") && !(!FT(c)) != !(!STD(c))) || (strstr(STRF(FT), "ft_to") && FT(c) != STD(c))) 
		{
			err++;
			printf(STRF(FT)"(%c): "ERROR"\n", c);
		}
	}
	return (err != 0);
}
