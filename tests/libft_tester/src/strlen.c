/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/28 00:04:43 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(void)
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
			exit(FT(NULL) != 0);
		}
		default:
		{
			int	status;
			wait(&status);
			if (WIFSIGNALED(status))
				return (printf(STRF(FT)"(NULL): "CRASHOK"\n"), 0);
			if (WEXITSTATUS(status))
				return (printf(STRF(FT)"(NULL): "ERROR"\n"), 0);
			return (0);
		}
	}
}

int	main(void)
{
	int		err = 0;
	char	a[] = "Cette phrase a une longueur de 34.";
	char	b[] = "\"Cette phrase a une longueur de 34.\"";
	char	c[] = "\t ) .Cette phrase n'aurait-elle pas des trucs en trop ?)  \n";
	char	d[] = "\"\\t ) .Cette phrase n'aurait-elle pas des trucs en trop ?)  \\n\"";
	char	e[] = "";
	char	f[] = "1";
	char	*all[] = {a, b, c, d, e, f, NULL};

	for (int i = 0; all[i]; i++)
	{
		char	*s = all[i];
		if (FT(s) != STD(s))
		{
			err++;
			printf(STRF(FT)"(%s):"ERROR"\n", s);
		}
	}
	null_check();
	return (err != 0);
}
