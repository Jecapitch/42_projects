/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/27 23:53:17 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(char *src)
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
		char	*s = FT(src);
		int		ret = !s;
		tester_ft_free_safe(s);
		exit(ret);
	}
	int	status;
	wait(&status);
	if (WIFSIGNALED(status))
		return (printf(STRF(FT)"(NULL): "CRASHOK"\n"), 0);
	if (WEXITSTATUS(status))
		return (0);
	printf(STRF(FT)"(NULL): "ERROR"\n");
	return (1);
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "mamma mia !", "fiouf pidoum \n$$wah", "\0argl"};
	int		tabsize = sizeof(s) / sizeof(char *);
	char	*src;

	for (int i = 0; i < tabsize; i++)
	{
		src = s[i];
		char 	*ft = FT(src);
		char	*std = STD(src);
		if ((!ft && std) || strcmp(ft, src) || strcmp(ft, std))
		{
			err++;
			printf(STRF(FT(src))": "ERROR"\n");
		}
		if (ft)
			free(ft);
		if (std)
			free(std);
	}
	err += null_check(NULL);
	return (err != 0);
}
