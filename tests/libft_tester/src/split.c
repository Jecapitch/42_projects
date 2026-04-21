/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/21 11:08:22 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(char *a, int sep)
{
	pid_t	pid = fork();

	if (pid == -1)
	{
		fprintf(stderr, STRF(FT)": fork() error");
		return (1);
	}
	if (pid == 0)
	{
		int	devnull = open("/dev/null", O_WRONLY);
		if (devnull != -1)
		{
			dup2(devnull, STDERR_FILENO);
			close(devnull);
		}
		void	**s = FT(a, sep);
		if (s)
		{
			tester_ft_free_str_tab(s);
			exit(0);
		}
		exit(1);
	}
	int	status;
	wait(&status);
	if (WIFSIGNALED(status) || WEXITSTATUS(status))
		return (0);
	printf(STRF(FT)"(NULL, %d): "ERROR"\n", sep);
	return (1);
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "mamma mia !", "fiouf pidoum \n$$wah", "\0argl", "       ", "aonx,AEFKALJ23O1£93erç!yfezè!ç&e!çy!èéhidzehohlbmvùcipùv$)fvçFËZR*Flpkmkj"};
	int		tabsize = sizeof(s) / sizeof(char *);

	for (int i = 0; i < tabsize; i++)
	{
		for (int ascii = 0; ascii < 256; ascii++)
		{
			char	*sp = s[i];
			int		sep = ascii;
			char	**ft = FT(sp, sep);
			if (!ft)
			{
				err++;
				printf(STRF(FT)"(\"%s\", %d): "ERROR"\n", sp, b);
				continue ;
			}
			char	**std = STD(sp, sep);
			for (int k = 0; ft[k] || std[k]; k++)
			{
				char	*a = ft[k];
				char	*b = std[k];
				if ((!a && b) || (a && !b) || strcmp(a, b))
				{
					err++;
					printf(STRF(FT)"(\"%s\", \"%s\"): "ERROR"\n", a, b);
					break ;
				}
			}
			tester_ft_free_str_tab(ft);
			tester_ft_free_str_tab(std);
		}
		err += null_check(NULL, 42);
	}
	return (err != 0);
}
