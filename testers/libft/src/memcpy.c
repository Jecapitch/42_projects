/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/17 13:45:43 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(char *dest, char *src, int size)
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
		void* ret = FT(dest, src, size);
		exit(ret == dest);
	}
	int	status;
	wait(&status);
	if (WIFSIGNALED(status) || WEXITSTATUS(status))
		return (0);
	printf(STRF(FT)"(%s, %s, %d): "ERROR"\n", dest ? dest : "NULL", src ? src : "NULL", size);
	return (1);
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "mamma mia !", "fiouf pidoum \n$$wah", "\0argl"};
	int		tabsize = sizeof(s) / sizeof(char *);
	int 	size; 
	char	*src;

	for (int i = 0; i < tabsize; i++)
	{
		size = strlen(s[i]) + 2 * (i & 1);
		char dest[size];
		char dest2[size];
		src = s[i];
		if (strncmp(FT(dest, src, size), STD(dest2, src, size), size))
		{
			err++;
			printf(STRF(FT)"(dest[%d], \"%s\", %d): "ERROR"\n", size, src, size);
		}
	}
	size = 42;
	char dest[size];
	char dest2[size];
	src = s[2];
	if (strncmp(FT(dest, src, size), STD(dest2, src, size), size))
	{
		err++;
		printf(STRF(FT)"(dest[%d], \"%s\", %d): "ERROR"\n", size, s[2], 0);
	}
	err += null_check(NULL, s[2], 42);
	err += null_check(s[2], NULL, 42);
	return (err != 0);
}
