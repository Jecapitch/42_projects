/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/28 00:14:17 by jepiscic         ###   ########.fr       */
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
		char	**s = FT(a, sep);
		int		ret = (s && s[0] != NULL);

		tester_ft_free_str_tab(s);
		exit(ret);
	}
	int	status;
	wait(&status);
	if (WIFSIGNALED(status))
		return (printf(STRF(FT(NULL, sep))": "CRASHOK"\n"), 0);
	if (WEXITSTATUS(status))
		return (printf(STRF(FT(NULL, sep))": "ERROR"\n"), 1);
	return (0);
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "mamma mia !", "fiouf pidoum \n$$wah", "\0argl", "       ", "aonx,AEFKALJ23O1£93erç!yfezè!ç&e!çy!èéhidzehohlbmvùcipùv$)fvçFËZR*Flpkmkj"};
	int		tabsize = sizeof(s) / sizeof(char *);

	for (int i = 0; i < tabsize; i++)
	{
		for (int ascii = -128; ascii < 127; ascii++)
		{
			char	*sp = s[i];
			int		sep = ascii;
			char	**ft = FT(sp, sep);
			if (!ft)
			{
				err++;
				printf(STRF(FT)"(\"%s\", %d): "ERROR"\n", sp, sep);
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
					printf(STRF(FT)"(\"%s\", %d): "ERROR"\n", sp, sep);
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
