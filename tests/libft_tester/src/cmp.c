/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/17 14:00:45 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(char *a, char *b, int size)
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
				printf(STRF(FT)"(%s, %s, %d): "YEL"crash (OK)"CRESET"\n", \
						a ? a : "NULL", b ? b : "NULL", size);
		}
	}
	return (0);
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "mamma mia !", "fiouf pidoum \n$$wah", "\0argl"};
	int		len[] = {0, 1, 2, 4, 8, 13, 42, 200};
	int		tabsize = sizeof(s) / sizeof(char *);
	int		lensize = sizeof(len) / sizeof(int);

	for (int i = 0; i < tabsize; i++)
		for (int j = 0; j < tabsize; j++)
			for (int k = 0; k < lensize; k++)
			{
				int	ft = FT(s[i], s[j], len[k]);
				int	std = STD(s[i], s[j], len[k]);
				if ((ft != std) && ((ft > 0 && std < 0) || (ft < 0 && std > 0)))
				{
					err++;
					printf(STRF(FT)"(\"%s\", \"%s\", %d): "ERROR"\n", s[i], s[j], len[k]);
				}
			}
	err += null_check(NULL, s[2], 42);
	err += null_check(s[2], NULL, 42);
	return (err != 0);
}
