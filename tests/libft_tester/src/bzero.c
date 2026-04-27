/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/27 23:17:04 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(char *a, int size)
{
	switch(fork())
	{
		case -1:
		{
			fprintf(stderr, STRF(FT)": fork() error");
			exit(1);
		}
		case 0:
		{
			int	devnull = open("/dev/null", O_WRONLY);
			if (devnull != -1)
			{
				dup2(devnull, STDERR_FILENO);
				close(devnull);
			}
			FT(a, size);
			exit(0);
		}
		default:
		{
			int	status;
			wait(&status);
			if (WIFSIGNALED(status))
				printf(STRF(FT)"(NULL, %d): "YEL"crash (OK)"CRESET"\n", size);
		}
	}
	return (0);
}

int	main(void)
{
	int		err = 0;

	for (int i = 0; i < 50; i++)
	{
		int 	size = i;
		char	dest[size];
		char	dest2[size];

		FT(dest, size);
		STD(dest2, size);
		if (memcmp(dest, dest2, size))
		{
			err++;
			printf(STRF(FT)"(dest[%lu], %d): "ERROR"\n", sizeof(dest), size);
		}
	}
	err += null_check(NULL, 42);
	return (err != 0);
}
