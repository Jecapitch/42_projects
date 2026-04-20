/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/18 00:47:02 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"
#undef STD
#define STD(s, i, n)	((unsigned)i <= strlen(s) ? strndup(s + i, n) : strdup(""))

int	null_check(char *src, int i, int size)
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
		char	*dest = FT(src, i, size);
		int		ret = !dest;
		if (dest)
			free(dest);
		exit(ret);
	}
	int	status;
	wait(&status);
	if (WIFSIGNALED(status) || WEXITSTATUS(status))
		return (0);
	printf(STRF(FT)"(NULL, %d, %d): "ERROR"\n", i, size);
	return (1);
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "mamma mia !", "fiouf pidoum \n$$wah", "\0argl", NULL};
	int 	size = 13; 
	char	*src;

	for (int i = 0; s[i]; i++)
	{
		src = s[i];
		for (int k = 0; k < 10; k++)
		{
			char *ft = FT(src, k, size);
			char *std = STD(src, k, size);
			if ((ft && !std) || (!ft && std) || strcmp(ft, std))
			{
				printf("src=\"%s\" ft=\"%s\" std=\"%s\"\n", src, ft, std);
				err++;
				printf(STRF(FT)"(%s, %d, %d): "ERROR"\n", src, k, size);
			}
			if (ft)
				free(ft);
			if (std)
				free(std);
		}
	}
	err += null_check(NULL, 19, 42);
	return (err != 0);
}
