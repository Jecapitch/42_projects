/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jointrim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/27 23:21:14 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(char *a, char *b)
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
		void	*s = FT(a, b);
		int		ret = 1;
		if (s)
		{
			ret = !strcmp(s, a ? a : b);
			free(s);
		}
		exit(ret);
	}
	int	status;
	wait(&status);
	if (WIFSIGNALED(status) || WEXITSTATUS(status))
		return (0);
	printf(STRF(FT)"(%s, %s): "ERROR"\n", a ? a : "NULL", b ? b : "NULL");
	return (1);
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "mamma mia !", "fiouf pidoum \n$$wah", "\0argl", "       "};
	int		tabsize = sizeof(s) / sizeof(char *);

	for (int i = 0; i < tabsize; i++)
	{
		for (int j = 0; j < tabsize; j++)
		{
			char	*a = s[i];
			char	*b = s[j];
			char	*ft = FT(a, b);
			char	*std = STD(a, b);
			if ((!ft && std) || (ft && !std)  || strcmp(ft, std))
			{
				err++;
				printf(STRF(FT)"(\"%s\", \"%s\"): "ERROR"\n", a, b);
			}
			err += null_check(NULL, b);
			err += null_check(a, NULL);
			if (ft)
				free(ft);
			if (std)
				free(std);
		}
	}
	return (err != 0);
}
