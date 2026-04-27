/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/27 23:32:08 by jepiscic         ###   ########.fr       */
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
			exit(FT(a, b, size) != 0);
		}
		default:
		{
			int	status;
			wait(&status);
			if (WIFSIGNALED(status))
				return (printf(STRF(FT)"(NULL, '%d', %d): "CRASHOK"\n", b, size), 0);
			if (WEXITSTATUS(status))
				return (printf(STRF(FT)"(NULL, '%d', %d): "ERROR": returns nonnull\n", b, size), 1);
			return (0);
		}
	}
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "mamma mia !", "fiouf pidoum \n$$wah", "\0argl", "nojdezll,DZEIK,dezkj\a\v"};
	int		tabsize = sizeof(s) / sizeof(char *);
	char	*chr;
	int		size;

	for (int i = 0; i < tabsize; i++)
	{
		chr = s[i];
		size = strlen(chr);
		for (int c = -128; c < 127; c++)
		{
			if (FT(chr, c, size) != STD(chr, c, size))
			{
				err++;
				printf(STRF(FT)"(\"%s\", '%d', %d): "ERROR"\n", chr, c, size);
			}
		}
	}
	err += null_check(NULL, 42, 19);
	return (err != 0);
}
