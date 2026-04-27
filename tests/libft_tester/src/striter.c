/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/27 16:37:49 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(void (*f)(unsigned int, char *))
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
			FT(NULL, f);
			exit(0);
		}
		default:
		{
			int	status;
			wait(&status);
			if (WIFSIGNALED(status))
				printf(STRF(FT)"(NULL, uplow): "YEL"crash (OK)"CRESET"\n");
		}
	}
	return (0);
}

void	uplow(unsigned int i, char *s)
{
	if (i & 1)
		*s = ft_tolower(*s);
	else
		*s = ft_toupper(*s);
}

void	rot13(unsigned int i, char *s)
{
	(void)i;
	if (ft_isalpha(*s))
	{
		int	c = tester_ft_islower(*s) * ('a' - 'A') + 'A';
		*s = (*s - c + 13) % 26 + c;
	}
}

void	rotuplow(unsigned int i, char *s)
{
	(void)i;
	for (int j = 0; j < 3; j++)
	{
		rot13(i, s);
		uplow(i, s);
	}
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "maMma mia !", "fiouf & pidoum \t$$WAH", "\0argl", NULL};
	char	*ft;
	char	*std;
	void	(*f[])(unsigned int, char *) = {uplow, rot13, rotuplow, NULL};
	char	*fname[] = {"uplow", "rot13", "rotuplow", NULL};

	for (int i = 0; s[i]; i++)
	{
		for (int j = 0; f[j]; j++)
		{
			ft = strdup(s[i]);
			std = strdup(s[i]);
			FT(ft, f[j]);
			STD(std, f[j]);
			if (strcmp(ft, std))
			{
				err++;
				printf(STRF(FT)"(\"%s\", %s): "ERROR"\n", s[i], fname[j]);
			}
			free(ft);
			free(std);
		}
	}
	err += null_check(uplow);
	return (err != 0);
}
