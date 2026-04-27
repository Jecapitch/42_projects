/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/27 23:50:03 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(int size)
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
			return (FT(NULL, size) != NULL);
		}
		default:
		{
			int	status;
			wait(&status);
			if (WIFSIGNALED(status))
				return (printf(STRF(FT)"(NULL, %d): "CRASHOK"\n", size), 0);
			if (WEXITSTATUS(status))
				return (printf(STRF(FT)"(NULL, %d): "ERROR"\n", size), 1);
			return (0);
		}
	}
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "mamma mia !", "fiouf pidoum \n$$wah", "\0argl", "nojdez\tll,DZEIK,dezkj\a"};
	int		tabsize = sizeof(s) / sizeof(char *);
	char	*chr;

	for (int i = 0; i < tabsize; i++)
	{
		chr = s[i];
		for (int c = -128; c < 127; c++)
		{
			if (FT(chr, c) !=  STD(chr, c))
			{
				err++;
				printf(STRF(FT)"(\"%s\", '%d'): "ERROR"\n", chr, c);
			}
		}
	}
	err += null_check(42);
	return (err != 0);
}
