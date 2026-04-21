/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/21 15:16:00 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(char *a, int b, int size)
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
			FT(a, b, size);
			exit(0);
		}
		default:
		{
			int	status;
			wait(&status);
			if (WIFSIGNALED(status))
				printf(STRF(FT)"(NULL, '%d', %d): "YEL"crash (OK)"CRESET"\n", b, size);
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
		memset(dest, 0, size);
		memset(dest2, 0, size);
		for (int c = -128; c < 127; c++)
		{
			if (strncmp(FT(dest, c, size), STD(dest2, c, size), size))
			{
				err++;
				printf(STRF(FT)"(\"%s\"[%zu], '%d', %d): "ERROR"\n", dest, sizeof(dest), c, size);
			}
		}
	}
	err += null_check(NULL, 42, 19);
	return (err != 0);
}
