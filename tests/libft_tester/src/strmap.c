/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jepiscic <jepiscic@student.42belgium.be>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:48:45 by jpiscice          #+#    #+#             */
/*   Updated: 2026/04/28 00:14:42 by jepiscic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tester.h"

int	null_check(char (*f)(unsigned int, char))
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
			char	*s = FT(NULL, f);
			int		ret = (s && !strcmp(s, ""));
			tester_ft_free_safe(s);
			exit(ret);
		}
		default:
		{
			int	status;
			wait(&status);
			if (WIFSIGNALED(status))
				printf(STRF(FT)"(NULL, uplow): "CRASHOK"\n");
		}
	}
	return (0);
}

char	uplow(unsigned int i, char s)
{
	if (i & 1)
		return (ft_tolower(s));
	return (ft_toupper(s));
}

char	rot13(unsigned int i, char s)
{
	(void)i;
	if (ft_isalpha(s))
	{
		int	c = ft_islower(s) * ('a' - 'A') + 'A';
		return ((s - c + 13) % 26 + c);
	}
	return (s);
}

char	rotuplow(unsigned int i, char s)
{
	(void)i;
	for (int j = 0; j < 3; j++)
	{
		s = rot13(i, s);
		s = uplow(i, s);
	}
	return (s);
}

int	main(void)
{
	int		err = 0;
	char	*s[] = {"", "o", "maMma mia !", "fiouf & pidoum \t$$WAH", "\0argl", NULL};
	char	*ft;
	char	*std;
	char	(*f[])(unsigned int, char) = {uplow, rot13, rotuplow, NULL};
	char	*fname[] = {"uplow", "rot13", "rotuplow", NULL};

	for (int i = 0; s[i]; i++)
	{
		for (int j = 0; f[j]; j++)
		{
			ft = FT(s[i], f[j]);
			std = STD(s[i], f[j]);
			if (ft == s[i] || strcmp(ft, std))
			{
				err++;
				printf(STRF(FT)"(\"%s\", %s): "ERROR"\n", s[i], fname[j]);
			}
			if (ft != s[i])
				tester_ft_free_safe(ft);
			tester_ft_free_safe(std);
		}
	}
	err += null_check(uplow);
	return (err != 0);
}
