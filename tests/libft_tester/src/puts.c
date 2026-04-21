/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/21 13:48:31 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(int ft_fd, int std_fd)
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
		FT(NULL, ft_fd);
		STD(std_fd, "");
		exit(1);
	}
	int	status;
	wait(&status);
	if (WIFSIGNALED(status) || WEXITSTATUS(status))
		return (0);
	printf(STRF(FT)"(NULL): "ERROR"\n");
	return (1);
}

int	main(void)
{
	char	*s[] = {"", "o", "mamma mia !\n", "fiouf pidoum \n$$wah", "\0argl", "JIFREFPf;129 3U04923RPEZKK%FERHFjfzeuiheziu \tghdiz\rejkdzejdyuzegiuhed", NULL};
	char	*src;
	int		ft_fd = open("traces/"FT"_user_output", O_CREAT | O_TRUNC | O_APPEND);
	int		std_ft = open("traces"FT"_test_output", O_CREAT | O_TRUNC | O_APPEND);

	for (int i = 0; s[i]; i++)
	{
		src = s[i];
		FT(src, ft_fd);
		STD(ft_fd, "%s", src);
	}
	null_check(NULL, ft_fd, std_fd);
	close(ft_fd);
	close(std_fd);
	return (0);
}
